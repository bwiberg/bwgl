#pragma once

#include OPENGL_HEADER

namespace bwgl {
    /// @brief //todo add brief description to Texture
    /// @author benjamin
    class Texture {
    public:
        Texture(GLenum target, GLenum pixelFormat, GLenum dataType);

        ~Texture();

        void bind();

        void unbind();

        void loadImage2D(GLint internalFormat,
                         GLsizei width, GLsizei height,
                         const GLvoid *data);

        void loadImage2D(GLint internalFormat,
                         GLsizei width, GLsizei height,
                         const GLvoid *data,
                         GLint mipmapLevel);

        void parameter(GLenum pname, GLfloat param);

        void parameter(GLenum pname, GLint param);

        void parameter(GLenum pname, const GLfloat *params);

        void parameter(GLenum pname, const GLint *params);


    private:
        GLuint id_;

        GLenum target_;

        GLenum pixelFormat_;

        GLenum dataType_;
    };
}

#include "Texture.inl"