#include "util/OGL_CALL.h"

namespace bwgl {
    inline RenderBuffer::RenderBuffer() {
        OGL_CALL(glGenRenderbuffers(1, &mID));
    }

    inline RenderBuffer::~RenderBuffer() {
        OGL_CALL(glDeleteRenderbuffers(1, &mID));
    }

    inline void RenderBuffer::bind() {
        OGL_CALL(glBindRenderbuffer(GL_RENDERBUFFER, mID));
    }

    inline void RenderBuffer::unbind() {
#if ENABLE_GL_UNBIND
        OGL_CALL(glBindRenderbuffer(GL_RENDERBUFFER, 0));
#endif
    }

    inline void RenderBuffer::generateStorage(GLenum internalFormat, GLsizei width, GLsizei height) {
        OGL_CALL(glRenderbufferStorage(GL_RENDERBUFFER, internalFormat, width, height));
    }

    inline GLuint RenderBuffer::ID() const {
        return mID;
    }
}
