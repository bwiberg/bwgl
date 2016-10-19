#pragma once

#include <string>
#include <unordered_map>

#include <gl3.h>

namespace bwgl {
    /// @brief //todo add brief description to Shader
    /// @author Benjamin Wiberg
    class Shader {
    public:
        Shader(std::unordered_map<GLuint, std::string> stages);

        /**
         * (Tries to) compile the shader. If successful, it should NOT be
         * called again.
         * @return Whether compilation/linking was successful
         */
        bool compile();

        /**
         * Use the shader. Equivalent to glUseShader(shader.ID());
         */
        void use();

        /**
         * Checks if the shader is valid. Equivalent to shader.ID() != 0.
         * @return True if the shader is valid
         */
        bool isValid();

        /**
         * Gets the OpenGL ID of the shader.
         * @return The ID
         */
        inline GLuint ID() const {
            return mID;
        }

    private:
        static bool TryCompileShaderStage(GLuint type, GLchar const *source, GLuint &shaderStageID);

        std::unordered_map<GLuint, std::string> mStages;

        GLuint mID;
    };
}