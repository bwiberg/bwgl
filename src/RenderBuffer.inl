namespace bwgl {
    inline RenderBuffer::RenderBuffer() {
        glGenRenderbuffers(1, &mID);
    }

    inline RenderBuffer::~RenderBuffer() {
        glDeleteRenderbuffers(1, mID);
    }

    inline void RenderBuffer::bind() {
        glBindRenderbuffer(GL_RENDERBUFFER, mID);
    }

    inline void RenderBuffer::unbind() {
#if ENABLE_GL_UNBIND
        glBindRenderbuffer(GL_RENDERBUFFER, 0);
#endif
    }

    inline void RenderBuffer::generateStorage(GLenum internalFormat, GLsizei width, GLsizei height) {
        glRenderbufferStorage(GL_RENDERBUFFER, internalFormat, width, height);
    }

    inline GLuint RenderBuffer::ID() const {
        return mID;
    }
}
