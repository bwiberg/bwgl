#include "VertexBuffer.hpp"

namespace bwgl {
    inline VertexBuffer::VertexBuffer(GLenum target, GLenum usage)
            : mTarget(target), mUsage(usage) {
        glGenBuffers(1, &mID);
    }

    inline VertexBuffer::~VertexBuffer() {
        glDeleteBuffers(1, &mID);
    }

    inline void VertexBuffer::bind() {
        glBindBuffer(mMode, mID);
    }

    inline void VertexBuffer::unbind() {
#if ENABLE_GL_UNBIND
        glBindBuffer(GL_ARRAY_BUFFER, 0);
#endif
    }

    inline void VertexBuffer::bufferData(GLsizeiptr size, const GLvoid *data, GLenum usage) {
        glBufferData(mMode, size, data, usage);
    }

    inline GLuint VertexBuffer::ID() const {
        return mID;
    }
}
