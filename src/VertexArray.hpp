#pragma once

#include <gl3.h>

#include "VertexBuffer.hpp"

namespace bwgl {
    /// @brief //todo add brief description to VertexArray
    /// @author benjamin
    class VertexArray {
    public:
        VertexArray();

        ~VertexArray();

        void bind();

        void unbind();

        void addVertexAttribute(VertexBuffer &vertexBuffer,
                                GLint size,
                                GLenum type,
                                GLboolean normalized,
                                GLsizei stride);

        void addElementBuffer(VertexBuffer &elementBuffer);

        GLuint ID() const;

    private:
        GLuint mID;

        GLuint mVertexAttributeCount;
    };
}

#include "VertexArray.inl"
