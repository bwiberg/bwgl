bwgl::FrameBuffer::FrameBuffer(GLenum pixelFormat, GLenum dataType)
        : mTexture(GL_TEXTURE_2D, pixelFormat, dataType) {
    glGenFramebuffers(1, &mID);
}

bwgl::FrameBuffer::~FrameBuffer() {
    glDeleteFramebuffers(1, &mID);
}

void bwgl::FrameBuffer::bind() {
    glBindFramebuffer(GL_FRAMEBUFFER, mID);
}

void bwgl::FrameBuffer::unbind() {
#if ENABLE_GL_UNBIND
    glBindFramebuffer(GL_FRAMEBUFFER, 0);
#endif
}

void bwgl::FrameBuffer::generate(GLint internalFormat,
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
    glFramebufferTexture2D(GL_FRAMEBUFFER, GL_COLOR_ATTACHMENT0, GL_TEXTURE_2D, mTexture.ID(),
            /* color attachment #0 */ 0);


    /* Depth */

    // Create depth texture
    mDepthBuffer.bind();
    mDepthBuffer.generateStorage(GL_DEPTH_COMPONENT, width, height);
    mDepthBuffer.unbind();

    // Attach depth buffer to framebuffer
    glFramebufferRenderbuffer(GL_FRAMEBUFFER, GL_DEPTH_ATTACHMENT, GL_RENDERBUFFER, mDepthBuffer.ID());


    /* Configuration */

    // Set the list of draw buffers
    GLenum drawBuffers[1] = {GL_COLOR_ATTACHMENT0};
    glDrawBuffers(1, drawBuffers);
}

inline GLuint bwgl::FrameBuffer::ID() const {
    return mID;
}