#pragma once

#include OPENGL_HEADER

#include "Texture.hpp"
#include "RenderBuffer.hpp"

namespace bwgl {
    /// @brief //todo add brief description to FrameBuffer
    /// @author benjamin
    class FrameBuffer {
    public:
        FrameBuffer(GLenum pixelFormat, GLenum dataType);

        ~FrameBuffer();

        void bind();

        void unbind();

        void generateTexture(GLint internalFormat,
                             GLsizei width, GLsizei height);

        GLuint ID() const;
    private:
        GLuint mID;

        Texture mTexture;

        RenderBuffer mDepthBuffer;
    };
}

#include "FrameBuffer.inl"