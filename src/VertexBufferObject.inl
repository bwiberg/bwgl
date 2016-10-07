#include "VertexBufferObject.hpp"

inline bwgl::VertexBufferObject::VertexBufferObject(GLenum mode, GLenum usage)
        : mode_(mode), usage_(usage) {
    glGenBuffers(1, &id_);
}

inline bwgl::VertexBufferObject::~VertexBufferObject() {
    glDeleteBuffers(1, &id_);
}

inline void bwgl::VertexBufferObject::bind() {
    glBindBuffer(mode_, id_);
}

inline void bwgl::VertexBufferObject::unbind() {
#if ENABLE_GL_UNBIND
    glBindBuffer(GL_ARRAY_BUFFER, 0);
#endif
}

inline void bwgl::VertexBufferObject::bufferData(GLsizeiptr size, const GLvoid *data, GLenum usage) {
    glBufferData(mode_, size, data, usage);
}
