#pragma once

#include <gl3.h>

namespace bwgl {
    /// @brief //todo add brief description to Texture
    /// @author benjamin
    class Texture2D {
    public:
        Texture2D(GLenum target, GLenum pixelFormat, GLenum dataType);

        ~Texture2D();

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

        GLuint ID() const;


    private:
        GLuint mID;

        GLenum mTarget;

        GLenum mPixelFormat;

        GLenum mDataType;
    };
}

#include "Texture2D.inl"
