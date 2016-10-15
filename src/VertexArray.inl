namespace bwgl {
    inline VertexArray::VertexArray()
            : mVertexAttributeCount(0) {
        glGenVertexArrays(1, &mID);
    }

    inline VertexArray::~VertexArray() {
        glDeleteVertexArrays(1, &mID);
    }

    inline void VertexArray::bind() {
        glBindVertexArray(mID);
    }

    inline void VertexArray::unbind() {
#if ENABLE_GL_UNBIND
        glBindVertexArray(0);
#endif
    }

    inline void VertexArray::addVertexAttribute(VertexBuffer vertexBuffer,
                                                GLint size,
                                                GLenum type,
                                                GLboolean normalized,
                                                GLsizei stride) {
        vertexBuffer.bind();
        glVertexAttribPointer(mVertexAttributeCount,
                              size,
                              type,
                              normalized,
                              stride,
                              (void *) 0);
        glEnableVertexAttribArray(mVertexAttributeCount);
        vertexBuffer.unbind();

        ++mVertexAttributeCount;
    }

    inline GLuint VertexArray::ID() const {
        return mID;
    }
}
