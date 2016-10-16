#pragma once

#include <gl3.h>

namespace bwgl {
    class Texture1D {
    public:
        Texture1D(GLenum target, GLenum pixelFormat, GLenum dataType);

        ~Texture1D();

        void bind();

        void unbind();

        void loadImage1D(GLint internalFormat,
                         GLsizei width,
                         const GLvoid *data);

        void loadImage1D(GLint internalFormat,
                         GLsizei width,
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