namespace bwgl {
    inline Texture3D::Texture3D(GLenum target, GLenum pixelFormat, GLenum dataType)
            : mTarget(target), mPixelFormat(pixelFormat), mDataType(dataType) {
        glGenTextures(1, &mID);
    }

    inline Texture3D::~Texture3D() {
        glDeleteTextures(1, &mID);
    }

    inline void Texture3D::bind() {
        glBindTexture(GL_TEXTURE_3D, mID);
    }

    inline void Texture3D::unbind() {
#if ENABLE_GL_UNBIND
        glBindTexture(GL_TEXTURE_3D, 0);
#endif
    }


    inline void Texture3D::loadImage3D(GLint internalFormat,
                                       GLsizei width, GLsizei height,
                                       const GLvoid *data) {
        glTexImage3D(mTarget, 0, internalFormat,
                     width, height, 0,
                     mPixelFormat, mDataType,
                     data);

        glGenerateMipmap(GL_TEXTURE_3D);
    }

    inline void Texture3D::loadImage3D(GLint internalFormat,
                                       GLsizei width, GLsizei height,
                                       const GLvoid *data,
                                       GLint mipmapLevel) {
        glTexImage3D(mTarget, mipmapLevel, internalFormat,
                     width, height, 0,
                     mPixelFormat, mDataType,
                     data);
    }

    inline void Texture3D::parameter(GLenum pname, GLfloat param) {
        glTexParameterf(GL_TEXTURE_3D, pname, param);
    }

    inline void Texture3D::parameter(GLenum pname, GLint param) {
        glTexParameteri(GL_TEXTURE_3D, pname, param);
    }

    inline void Texture3D::parameter(GLenum pname, const GLfloat *params) {
        glTexParameterfv(GL_TEXTURE_3D, pname, params);
    }

    inline void Texture3D::parameter(GLenum pname, const GLint *params) {
        glTexParameteriv(GL_TEXTURE_3D, pname, params);
    }

    inline GLuint Texture3D::ID() const {
        return mID;
    }
}
