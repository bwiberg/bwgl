#include "VertexBufferObject.hpp"

inline bwgl::VertexBufferObject::VertexBufferObject(GLenum target, GLenum usage)
        : mTarget(target), mUsage(usage) {
    glGenBuffers(1, &mID);
}

inline bwgl::VertexBufferObject::~VertexBufferObject() {
    glDeleteBuffers(1, &mID);
}

inline void bwgl::VertexBufferObject::bind() {
    glBindBuffer(mMode, mID);
}

inline void bwgl::VertexBufferObject::unbind() {
#if ENABLE_GL_UNBIND
    glBindBuffer(GL_ARRAY_BUFFER, 0);
#endif
}

inline void bwgl::VertexBufferObject::bufferData(GLsizeiptr size, const GLvoid *data, GLenum usage) {
    glBufferData(mMode, size, data, usage);
}

inline GLuint bwgl::VertexBufferObject::ID() const {
    return mID;
}