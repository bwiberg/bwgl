#pragma once

#include OPENGL_HEADER

namespace bwgl {
    /// @brief //todo add brief description to VertexBufferObject
    /// @author benjamin
    class VertexBufferObject {
    public:
        VertexBufferObject(GLenum mode, GLenum usage = GL_STATIC_DRAW);

        ~VertexBufferObject();

        void bind();

        void unbind();

        void bufferData(GLsizeiptr size, const GLvoid *data, GLenum usage = usage_);

    private:
        GLuint id_;

        GLenum mode_, usage_;

    };
}

#include "VertexBufferObject.inl"