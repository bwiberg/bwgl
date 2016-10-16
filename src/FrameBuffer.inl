#include "util/OGL_CALL.h"

namespace bwgl {
    inline FrameBuffer::FrameBuffer(GLenum pixelFormat, GLenum dataType)
            : mTexture(GL_TEXTURE_2D, pixelFormat, dataType) {
        OGL_CALL(glGenFramebuffers(1, &mID));
    }

    inline FrameBuffer::~FrameBuffer() {
        OGL_CALL(glDeleteFramebuffers(1, &mID));
    }

    inline void FrameBuffer::bind() {
        OGL_CALL(glBindFramebuffer(GL_FRAMEBUFFER, mID));
    }

    inline void FrameBuffer::unbind() {
#if ENABLE_GL_UNBIND
        OGL_CALL(glBindFramebuffer(GL_FRAMEBUFFER, 0));
#endif
    }

    inline void FrameBuffer::generateTexture(GLint internalFormat,
                                             GLsizei width, GLsizei height) {
        /* Color */

        // Create color texture based on provided format
        mTexture.bind();
        mTexture.loadImage2D(internalFormat,
                             width, height,
                             NULL, // don't init texture memory with data
                             0);
        mTexture.parameter(GL_TEXTURE_MIN_FILTER, GL_LINEAR);
        mTexture.parameter(GL_TEXTURE_MAG_FILTER, GL_LINEAR);
        mTexture.unbind();

        // Attach color texture to framebuffer
        OGL_CALL(glFramebufferTexture2D(GL_FRAMEBUFFER, GL_COLOR_ATTACHMENT0, GL_TEXTURE_2D, mTexture.ID(),
                /* color attachment #0 */ 0));


        /* Depth */

        // Create depth texture
        mDepthBuffer.bind();
        mDepthBuffer.generateStorage(GL_DEPTH_COMPONENT, width, height);
        mDepthBuffer.unbind();

        // Attach depth buffer to framebuffer
        OGL_CALL(glFramebufferRenderbuffer(GL_FRAMEBUFFER, GL_DEPTH_ATTACHMENT, GL_RENDERBUFFER, mDepthBuffer.ID()));


        /* Configuration */

        // Set the list of draw buffers
        GLenum drawBuffers[1] = {GL_COLOR_ATTACHMENT0};
        OGL_CALL(glDrawBuffers(1, drawBuffers));
    }

    inline GLuint FrameBuffer::ID() const {
        return mID;
    }
}
