#pragma once

#include <gl3.h>

namespace bwgl {
    /// @brief //todo add brief description to VertexBufferObject
    /// @author benjamin
    class VertexBuffer {
    public:
        VertexBuffer(GLenum target, GLenum usage = GL_STATIC_DRAW);

        ~VertexBuffer();

        void bind();

        void unbind();

        void bufferData(GLsizeiptr size, const GLvoid *data);

        void bufferData(GLsizeiptr size, const GLvoid *data, GLenum usage);

        void bufferSubData(GLintptr offset, GLsizeiptr size, const GLvoid *data);

        GLuint ID() const;

    private:
        GLuint mID;

        GLenum mTarget, mUsage;

    };
}

#include "VertexBuffer.inl"
