#include "util/OGL_CALL.h"

namespace bwgl {
    inline VertexArray::VertexArray()
            : mVertexAttributeCount(0) {
        OGL_CALL(glGenVertexArrays(1, &mID));
    }

    inline VertexArray::~VertexArray() {
        OGL_CALL(glDeleteVertexArrays(1, &mID));
    }

    inline void VertexArray::bind() {
        OGL_CALL(glBindVertexArray(mID));
    }

    inline void VertexArray::unbind() {
#if ENABLE_GL_UNBIND
        OGL_CALL(glBindVertexArray(0));
#endif
    }

    inline void VertexArray::addVertexAttribute(VertexBuffer vertexBuffer,
                                                GLint size,
                                                GLenum type,
                                                GLboolean normalized,
                                                GLsizei stride) {
        vertexBuffer.bind();
        OGL_CALL(glVertexAttribPointer(mVertexAttributeCount,
                                       size,
                                       type,
                                       normalized,
                                       stride,
                                       (void *) 0));
        OGL_CALL(glEnableVertexAttribArray(mVertexAttributeCount));
        vertexBuffer.unbind();

        ++mVertexAttributeCount;
    }

    inline GLuint VertexArray::ID() const {
        return mID;
    }
}
