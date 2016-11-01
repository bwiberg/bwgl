#include "util/OGL_CALL.h"

namespace bwgl {
    inline VertexBuffer::VertexBuffer(GLenum target, GLenum usage)
            : mTarget(target), mUsage(usage) {
        OGL_CALL(glGenBuffers(1, &mID));
    }

    inline VertexBuffer::~VertexBuffer() {
        OGL_CALL(glDeleteBuffers(1, &mID));
    }

    inline void VertexBuffer::bind() {
        OGL_CALL(glBindBuffer(mTarget, mID));
    }

    inline void VertexBuffer::unbind() {
#if ENABLE_GL_UNBIND
        OGL_CALL(glBindBuffer(GL_ARRAY_BUFFER, 0));
#endif
    }

    inline void VertexBuffer::bufferData(GLsizeiptr size, const GLvoid *data) {
        this->bufferData(size, data, mUsage);
    }

    inline void VertexBuffer::bufferData(GLsizeiptr size, const GLvoid *data, GLenum usage) {
        OGL_CALL(glBufferData(mTarget, size, data, usage));
    }

    inline void VertexBuffer::bufferSubData(GLintptr offset, GLsizeiptr size, const GLvoid *data) {
        OGL_CALL(glBufferSubData(mTarget, offset, size, data));
    }

    inline GLuint VertexBuffer::ID() const {
        return mID;
    }
}
