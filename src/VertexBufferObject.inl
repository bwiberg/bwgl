#include "VertexBufferObject.hpp"

namespace bwgl {
    inline VertexBufferObject::VertexBufferObject(GLenum target, GLenum usage)
            : mTarget(target), mUsage(usage) {
        glGenBuffers(1, &mID);
    }

    inline VertexBufferObject::~VertexBufferObject() {
        glDeleteBuffers(1, &mID);
    }

    inline void VertexBufferObject::bind() {
        glBindBuffer(mMode, mID);
    }

    inline void VertexBufferObject::unbind() {
#if ENABLE_GL_UNBIND
        glBindBuffer(GL_ARRAY_BUFFER, 0);
#endif
    }

    inline void VertexBufferObject::bufferData(GLsizeiptr size, const GLvoid *data, GLenum usage) {
        glBufferData(mMode, size, data, usage);
    }

    inline GLuint VertexBufferObject::ID() const {
        return mID;
    }
}
