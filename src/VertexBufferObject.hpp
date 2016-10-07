#pragma once

#include OPENGL_HEADER

namespace bwgl {
    /// @brief //todo add brief description to VertexBufferObject
    /// @author benjamin
    class VertexBufferObject {
    public:
        VertexBufferObject(GLenum target, GLenum usage = GL_STATIC_DRAW);

        ~VertexBufferObject();

        void bind();

        void unbind();

        void bufferData(GLsizeiptr size, const GLvoid *data, GLenum usage = mUsage);

        GLuint ID() const;

    private:
        GLuint mID;

        GLenum mTarget, mUsage;

    };
}

#include "VertexBufferObject.inl"
