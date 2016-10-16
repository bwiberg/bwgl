#include "util/OGL_CALL.h"

namespace bwgl {
    inline Texture2D::Texture2D(GLenum target, GLenum pixelFormat, GLenum dataType)
            : mTarget(target), mPixelFormat(pixelFormat), mDataType(dataType) {
        OGL_CALL(glGenTextures(1, &mID));
    }

    inline Texture2D::~Texture2D() {
        OGL_CALL(glDeleteTextures(1, &mID));
    }

    inline void Texture2D::bind() {
        OGL_CALL(glBindTexture(GL_TEXTURE_2D, mID));
    }

    inline void Texture2D::unbind() {
#if ENABLE_GL_UNBIND
        OGL_CALL(glBindTexture(GL_TEXTURE_2D, 0));
#endif
    }


    inline void Texture2D::loadImage2D(GLint internalFormat,
                                       GLsizei width, GLsizei height,
                                       const GLvoid *data) {
        OGL_CALL(glTexImage2D(mTarget, 0, internalFormat,
                              width, height, 0,
                              mPixelFormat, mDataType,
                              data));

        OGL_CALL(glGenerateMipmap(GL_TEXTURE_2D));
    }

    inline void Texture2D::loadImage2D(GLint internalFormat,
                                       GLsizei width, GLsizei height,
                                       const GLvoid *data,
                                       GLint mipmapLevel) {
        OGL_CALL(glTexImage2D(mTarget, mipmapLevel, internalFormat,
                              width, height, 0,
                              mPixelFormat, mDataType,
                              data));
    }

    inline void Texture2D::parameter(GLenum pname, GLfloat param) {
        OGL_CALL(glTexParameterf(GL_TEXTURE_2D, pname, param));
    }

    inline void Texture2D::parameter(GLenum pname, GLint param) {
        OGL_CALL(glTexParameteri(GL_TEXTURE_2D, pname, param));
    }

    inline void Texture2D::parameter(GLenum pname, const GLfloat *params) {
        OGL_CALL(glTexParameterfv(GL_TEXTURE_2D, pname, params));
    }

    inline void Texture2D::parameter(GLenum pname, const GLint *params) {
        OGL_CALL(glTexParameteriv(GL_TEXTURE_2D, pname, params));
    }

    inline GLuint Texture2D::ID() const {
        return mID;
    }
}
