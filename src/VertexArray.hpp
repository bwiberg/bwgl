#pragma once

#include OPENGL_HEADER

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

        void addVertexAttribute(VertexBuffer vertexBuffer);

        GLuint ID() const;

    private:
        GLuint mID;

        GLuint mVertexAttributeCount;
    };
}

#include "VertexArray.inl"
