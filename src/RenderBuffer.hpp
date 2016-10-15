#pragma once

#include <gl3.h>

namespace bwgl {
    /// @brief //todo add brief description to RenderBuffer
    /// @author benjamin
    class RenderBuffer {
    public:
        RenderBuffer();

        ~RenderBuffer();

        void bind();

        void unbind();

        void generateStorage(GLenum internalFormat, GLsizei width, GLsizei height);

        GLuint ID() const;
    private:
        GLuint mID;
    };
}

#include "RenderBuffer.inl"