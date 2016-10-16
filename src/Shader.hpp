#pragma once

#include <string>
#include <unordered_map>

#include <gl3.h>

namespace bwgl {
    /// @brief //todo add brief description to Shader
    /// @author Benjamin Wiberg
    class Shader {
    public:
        /**
         * Java-inspired Builder pattern to create Shader instances with different combinations of shader stages.
         */
        class Builder {
            friend class Shader;
        public:
            /**
             * Add a vertex shader stage to the program.
             * @param filename The vertex shader's filename 
             * @return Itself 
             */
            Builder &vertex(std::string filename);

            /**
             * Add a tesselation control shader stage to the program.
             * @param filename The tesselation control shader's filename 
             * @return Itself 
             */
            Builder &tessControl(std::string filename);

            /**
             * Add a tesselation evaluation shader stage to the program.
             * @param filename The tesselation evaluation shader's filename 
             * @return Itself 
             */
            Builder &tessEvaluation(std::string filename);

            /**
             * Add a geometry shader stage to the program.
             * @param filename The geometry shader's filename 
             * @return Itself 
             */
            Builder &geometry(std::string filename);

            /**
             * Add a fragment shader stage to the program.
             * @param filename The fragment shader's filename 
             * @return Itself 
             */
            Builder &fragment(std::string filename);

            /**
             * Builds shader stages, attaches them to a shader program and links it together.
             * @return The shader program
             */
            Shader build();

            /**
             * Builds shader stages, attaches them to a shader program and links it together.
             * @return Pointer to the shader program
             */
            Shader *buildDynamic();

        private:
            GLuint internalBuild();

            std::unordered_map<GLuint, std::string> mShaderStages;

            Builder() {}

            static bool TryCompileShaderStage(GLuint type, GLchar const *source, GLuint &shaderStageID);
        };

        /**
         * Create a shader builder that will result in a new shader program.
         * @return The shader builder
         */
        static Builder create();

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
        GLuint ID();

    private:
        Shader(GLuint ID);

        const GLuint mID;
    };
}