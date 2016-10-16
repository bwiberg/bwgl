namespace bwgl {
    inline Texture2D::Texture2D(GLenum target, GLenum pixelFormat, GLenum dataType)
            : mTarget(target), mPixelFormat(pixelFormat), mDataType(dataType) {
        glGenTextures(1, &mID);
    }

    inline Texture2D::~Texture2D() {
        glDeleteTextures(1, &mID);
    }

    inline void Texture2D::bind() {
        glBindTexture(GL_TEXTURE_2D, mID);
    }

    inline void Texture2D::unbind() {
#if ENABLE_GL_UNBIND
        glBindTexture(GL_TEXTURE_2D, 0);
#endif
    }


    inline void Texture2D::loadImage2D(GLint internalFormat,
                                       GLsizei width, GLsizei height,
                                       const GLvoid *data) {
        glTexImage2D(mTarget, 0, internalFormat,
                     width, height, 0,
                     mPixelFormat, mDataType,
                     data);

        glGenerateMipmap(GL_TEXTURE_2D);
    }

    inline void Texture2D::loadImage2D(GLint internalFormat,
                                       GLsizei width, GLsizei height,
                                       const GLvoid *data,
                                       GLint mipmapLevel) {
        glTexImage2D(mTarget, mipmapLevel, internalFormat,
                     width, height, 0,
                     mPixelFormat, mDataType,
                     data);
    }

    inline void Texture2D::parameter(GLenum pname, GLfloat param) {
        glTexParameterf(GL_TEXTURE_2D, pname, param);
    }

    inline void Texture2D::parameter(GLenum pname, GLint param) {
        glTexParameteri(GL_TEXTURE_2D, pname, param);
    }

    inline void Texture2D::parameter(GLenum pname, const GLfloat *params) {
        glTexParameterfv(GL_TEXTURE_2D, pname, params);
    }

    inline void Texture2D::parameter(GLenum pname, const GLint *params) {
        glTexParameteriv(GL_TEXTURE_2D, pname, params);
    }

    inline GLuint Texture2D::ID() const {
        return mID;
    }
}
