#include "util/OGL_CALL.h"

namespace bwgl {
    inline Texture3D::Texture3D(GLenum target, GLenum pixelFormat, GLenum dataType)
            : mTarget(target), mPixelFormat(pixelFormat), mDataType(dataType) {
        OGL_CALL(glGenTextures(1, &mID));
    }

    inline Texture3D::~Texture3D() {
        OGL_CALL(glDeleteTextures(1, &mID));
    }

    inline void Texture3D::bind() {
        OGL_CALL(glBindTexture(GL_TEXTURE_3D, mID));
    }

    inline void Texture3D::unbind() {
#if ENABLE_GL_UNBIND
        OGL_CALL(glBindTexture(GL_TEXTURE_3D, 0));
#endif
    }


    inline void Texture3D::loadImage3D(GLint internalFormat,
                                       GLsizei width, GLsizei height, GLsizei depth,
                                       const GLvoid *data) {
        OGL_CALL(glTexImage3D(mTarget, 0, internalFormat,
                              width, height, depth, 0,
                              mPixelFormat, mDataType,
                              data));

        OGL_CALL(glGenerateMipmap(GL_TEXTURE_3D));
    }

    inline void Texture3D::loadImage3D(GLint internalFormat,
                                       GLsizei width, GLsizei height, GLsizei depth,
                                       const GLvoid *data,
                                       GLint mipmapLevel) {
        OGL_CALL(glTexImage3D(mTarget, mipmapLevel, internalFormat,
                              width, height, depth, 0,
                              mPixelFormat, mDataType,
                              data));
    }

    inline void Texture3D::parameter(GLenum pname, GLfloat param) {
        OGL_CALL(glTexParameterf(GL_TEXTURE_3D, pname, param));
    }

    inline void Texture3D::parameter(GLenum pname, GLint param) {
        OGL_CALL(glTexParameteri(GL_TEXTURE_3D, pname, param));
    }

    inline void Texture3D::parameter(GLenum pname, const GLfloat *params) {
        OGL_CALL(glTexParameterfv(GL_TEXTURE_3D, pname, params));
    }

    inline void Texture3D::parameter(GLenum pname, const GLint *params) {
        OGL_CALL(glTexParameteriv(GL_TEXTURE_3D, pname, params));
    }

    inline GLuint Texture3D::ID() const {
        return mID;
    }
}
