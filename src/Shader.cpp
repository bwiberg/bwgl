#include "Shader.hpp"

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
        typedef std::pair<GLuint, std::string> ShaderStage;

        GLuint programID = glCreateProgram();

        std::string shaderStageSource = "";
        GLuint shaderStageID;
        for (ShaderStage stage : mShaderStages) {
            if (TryReadFromFile(stage.second, shaderStageSource) &&
                TryCompileShaderStage(stage.first, shaderStageSource.c_str(), shaderStageID)) {
                glAttachShader(programID, shaderStageID);
                // reset the source string
                shaderStageSource = "";
            } else {
                std::cerr << "Failed to load shader '" << stage.second << "'" << std::endl;
                return Shader(0);
            }
        }

        glLinkProgram(programID);
        GLint isLinked;
        glGetProgramiv(programID, GL_LINK_STATUS, &isLinked);

        if (isLinked == GL_FALSE) {
            GLint length;
            glGetShaderiv(programID, GL_INFO_LOG_LENGTH, &length);
            std::string log(length, ' ');
            glGetShaderInfoLog(programID, length, &length, &log[0]);
            std::cerr << "Failed to link shaderprogram : " << std::endl
                      << log << std::endl;
            return Shader(0);
        }

        return Shader(programID);
    }

    bool Shader::Builder::TryCompileShaderStage(GLuint type, GLchar const *source, GLuint &shaderStageID) {
        shaderStageID = glCreateShader(type);
        glShaderSource(shaderStageID, 1, &source, NULL);
        glCompileShader(shaderStageID);

        // See if compiling was successful
        GLint compiled = 0;
        glGetShaderiv(shaderStageID, GL_COMPILE_STATUS, &compiled);
        if (compiled == GL_FALSE) {
            GLint logSize = 0;
            glGetShaderiv(shaderStageID, GL_INFO_LOG_LENGTH, &logSize);
            std::string log(logSize, ' ');
            glGetShaderInfoLog(shaderStageID, logSize, &logSize, &log[0]);
            std::cerr << "Failed to compile shader: " << log << std::endl;
            glDeleteShader(shaderStageID); // Don't leak the shader.
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
        glUseProgram(mID);
    }

    bool Shader::isValid() {
        return mID != 0;
    }

    GLuint Shader::ID() {
        return mID;
    }

    Shader::Shader(GLuint ID) : mID(ID) {}
}
