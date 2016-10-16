#pragma once

#include <gl3.h>

namespace bwgl {
    /// @brief //todo add brief description to Texture3D
    /// @author benjamin
    class Texture3D {
    public:
        Texture3D(GLenum target, GLenum pixelFormat, GLenum dataType);

        ~Texture3D();

        void bind();

        void unbind();

        void loadImage3D(GLint internalFormat,
                         GLsizei width, GLsizei height,
                         const GLvoid *data);

        void loadImage3D(GLint internalFormat,
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

#include "Texture3D.inl"
