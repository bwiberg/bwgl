namespace bwgl {
    inline Texture1D::Texture1D(GLenum target, GLenum pixelFormat, GLenum dataType)
            : mTarget(target), mPixelFormat(pixelFormat), mDataType(dataType) {
        glGenTextures(1, &mID);
    }

    inline Texture1D::~Texture1D() {
        glDeleteTextures(1, &mID);
    }

    inline void Texture1D::bind() {
        glBindTexture(GL_TEXTURE_1D, mID);
    }

    inline void Texture1D::unbind() {
#if ENABLE_GL_UNBIND
        glBindTexture(GL_TEXTURE_1D, 0);
#endif
    }


    inline void Texture1D::loadImage1D(GLint internalFormat,
                                       GLsizei width,
                                       const GLvoid *data) {
        glTexImage1D(mTarget, 0, internalFormat,
                     width, 0,
                     mPixelFormat, mDataType,
                     data);

        glGenerateMipmap(GL_TEXTURE_1D);
    }

    inline void Texture1D::loadImage1D(GLint internalFormat,
                                       GLsizei width,
                                       const GLvoid *data,
                                       GLint mipmapLevel) {
        glTexImage1D(mTarget, mipmapLevel, internalFormat,
                     width, 0,
                     mPixelFormat, mDataType,
                     data);
    }

    inline void Texture1D::parameter(GLenum pname, GLfloat param) {
        glTexParameterf(GL_TEXTURE_1D, pname, param);
    }

    inline void Texture1D::parameter(GLenum pname, GLint param) {
        glTexParameteri(GL_TEXTURE_1D, pname, param);
    }

    inline void Texture1D::parameter(GLenum pname, const GLfloat *params) {
        glTexParameterfv(GL_TEXTURE_1D, pname, params);
    }

    inline void Texture1D::parameter(GLenum pname, const GLint *params) {
        glTexParameteriv(GL_TEXTURE_1D, pname, params);
    }

    inline GLuint Texture1D::ID() const {
        return mID;
    }
}
