inline bwgl::RenderBuffer::RenderBuffer() {
    glGenRenderbuffers(1, &mID);
}

inline bwgl::RenderBuffer::~RenderBuffer() {
    glDeleteRenderbuffers(1, mID);
}

inline void bwgl::RenderBuffer::bind() {
    glBindRenderbuffer(GL_RENDERBUFFER, mID);
}

inline void bwgl::RenderBuffer::unbind() {
#if ENABLE_GL_UNBIND
    glBindRenderbuffer(GL_RENDERBUFFER, 0);
#endif
}

inline void bwgl::RenderBuffer::generateStorage(GLenum internalFormat, GLsizei width, GLsizei height) {
    glRenderbufferStorage(GL_RENDERBUFFER, internalFormat, width, height);
}

inline GLuint bwgl::RenderBuffer::ID() const {
    return mID;
}