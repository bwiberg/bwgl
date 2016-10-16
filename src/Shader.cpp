#include "Shader.hpp"

#include "util/OGL_CALL.h"
#include <iostream>
#include "FileReader.hpp"

namespace bwgl {
    Shader::Builder &Shader::Builder::vertex(std::string filename) {
        mShaderStages.insert(std::make_pair(GL_VERTEX_SHADER, filename));
        return *this;
    }

    Shader::Builder &Shader::Builder::tessControl(std::string filename) {
        mShaderStages.insert(std::make_pair(GL_TESS_CONTROL_SHADER, filename));
        return *this;
    }

    Shader::Builder &Shader::Builder::tessEvaluation(std::string filename) {
        mShaderStages.insert(std::make_pair(GL_TESS_EVALUATION_SHADER, filename));
        return *this;
    }

    Shader::Builder &Shader::Builder::geometry(std::string filename) {
        mShaderStages.insert(std::make_pair(GL_GEOMETRY_SHADER, filename));
        return *this;
    }

    Shader::Builder &Shader::Builder::fragment(std::string filename) {
        mShaderStages.insert(std::make_pair(GL_FRAGMENT_SHADER, filename));
        return *this;
    }

    Shader Shader::Builder::build() {
        return Shader(internalBuild());
    }

    Shader *Shader::Builder::buildDynamic() {
        return new Shader(internalBuild());
    }

    GLuint Shader::Builder::internalBuild() {
        typedef std::pair<GLuint, std::string> ShaderStage;

        OGL_CALL(GLuint programID = glCreateProgram());

        std::string shaderStageSource = "";
        GLuint shaderStageID;
        for (ShaderStage stage : mShaderStages) {
            if (TryReadFromFile(stage.second, shaderStageSource) &&
                TryCompileShaderStage(stage.first, shaderStageSource.c_str(), shaderStageID)) {
                OGL_CALL(glAttachShader(programID, shaderStageID));
                // reset the source string
                shaderStageSource = "";
            } else {
                std::cerr << "Failed to load shader '" << stage.second << "'" << std::endl;
                return 0;
            }
        }

        OGL_CALL(glLinkProgram(programID));
        GLint isLinked;
        OGL_CALL(glGetProgramiv(programID, GL_LINK_STATUS, &isLinked));

        if (isLinked == GL_FALSE) {
            GLint length;
            OGL_CALL(glGetShaderiv(programID, GL_INFO_LOG_LENGTH, &length));
            std::string log(length, ' ');
            OGL_CALL(glGetShaderInfoLog(programID, length, &length, &log[0]));
            std::cerr << "Failed to link shaderprogram : " << std::endl
                      << log << std::endl;
            return 0;
        }

        return programID;
    }

    bool Shader::Builder::TryCompileShaderStage(GLuint type, GLchar const *source, GLuint &shaderStageID) {
        OGL_CALL(shaderStageID = glCreateShader(type));
        OGL_CALL(glShaderSource(shaderStageID, 1, &source, NULL));
        OGL_CALL(glCompileShader(shaderStageID));

        // See if compiling was successful
        GLint compiled = 0;
        OGL_CALL(glGetShaderiv(shaderStageID, GL_COMPILE_STATUS, &compiled));
        if (compiled == GL_FALSE) {
            GLint logSize = 0;
            OGL_CALL(glGetShaderiv(shaderStageID, GL_INFO_LOG_LENGTH, &logSize));
            std::string log(logSize, ' ');
            OGL_CALL(glGetShaderInfoLog(shaderStageID, logSize, &logSize, &log[0]));
            std::cerr << "Failed to compile shader: " << log << std::endl;
            OGL_CALL(glDeleteShader(shaderStageID);)  // Don't leak the shader.
            return false;
        }

        return true;
    }

    //////////////
    /// Shader ///
    //////////////

    Shader::Builder Shader::create() {
        return Shader::Builder();
    }

    void Shader::use() {
        OGL_CALL(glUseProgram(mID));
    }

    bool Shader::isValid() {
        return mID != 0;
    }

    GLuint Shader::ID() {
        return mID;
    }

    Shader::Shader(GLuint ID) : mID(ID) {}
}
