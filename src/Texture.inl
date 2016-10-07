inline bwgl::Texture::Texture() {
    glGenTextures(1, &id_);
}

inline bwgl::Texture::~Texture() {
    glDeleteTextures(1, &id_);
}

inline void bwgl::Texture::bind() {
    glBindTexture(GL_TEXTURE_2D, id_);
}

inline void bwgl::Texture::unbind() {
#if ENABLE_GL_UNBIND
    glBindTexture(GL_TEXTURE_2D, 0);
#endif
}


inline void bwgl::Texture::loadImage2D(GLint internalFormat,
                                       GLsizei width, GLsizei height,
                                       const GLvoid *data) {
    glTexImage2D(target_, 0, internalFormat,
                 width, height, 0,
                 pixelFormat_, dataType_,
                 data);

    glGenerateMipmap(GL_TEXTURE_2D);
}

inline void bwgl::Texture::loadImage2D(GLint internalFormat,
                                       GLsizei width, GLsizei height,
                                       const GLvoid *data,
                                       GLint mipmapLevel) {
    glTexImage2D(target_, mipmapLevel, internalFormat,
                 width, height, 0,
                 pixelFormat_, dataType_,
                 data);
}

inline void bwgl::Texture::parameter(GLenum pname, GLfloat param) {
    glTexParameterf(GL_TEXTURE_2D, pname, param);
}

inline void bwgl::Texture::parameter(GLenum pname, GLint param) {
    glTexParameteri(GL_TEXTURE_2D, pname, param);
}

inline void bwgl::Texture::parameter(GLenum pname, const GLfloat *params) {
    glTexParameterfv(GL_TEXTURE_2D, pname, params);
}

inline void bwgl::Texture::parameter(GLenum pname, const GLint *params) {
    glTexParameteriv(GL_TEXTURE_2D, pname, params);
}
