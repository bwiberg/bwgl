#include <gl3.h>
#include <iostream>

/** @func _OpenGLErrorToString
 *  @brief Converts an OpenGL error to an std::string.
 *  @param err The OpenGL error returned by <a href="https://www.opengl.org/sdk/docs/man/html/glGetError.xhtml">glGetError</a>.
 *  @returns A string that explain the OpenGL error. These are copied directly from the OpenGL documentation.
 *
 * This function is called by _DisplayOpenGLError to get a user-friendly message in addition to an errror code.
 */
inline std::string _OpenGLErrorToString(GLenum err) {
    // Error messages copied from the glGetError documentation: https://www.opengl.org/sdk/docs/man/docbook4/xhtml/glGetError.xml
    switch (err) {
        case GL_NO_ERROR:
            return "No Error: No error has been recorded. The value of this symbolic constant is guaranteed to be 0.";
        case GL_INVALID_ENUM:
            return "Invalid enum: An unacceptable value is specified for an enumerated argument. The offending command is ignored and has no other side effect than to set the error flag.";
        case GL_INVALID_VALUE:
            return "Invalid value: A numeric argument is out of range. The offending command is ignored and has no other side effect than to set the error flag.";
        case GL_INVALID_OPERATION:
            return "Invalid operation: The specified operation is not allowed in the current state. The offending command is ignored and has no other side effect than to set the error flag.";
        case GL_INVALID_FRAMEBUFFER_OPERATION:
            return "Invalid framebuffer operation: The framebuffer object is not complete. The offending command is ignored and has no other side effect than to set the error flag.";
        case GL_OUT_OF_MEMORY:
            return "Out of memory: There is not enough memory left to execute the command. The state of the GL is undefined, except for the state of the error flags, after this error is recorded.";
        default:
            break;
    }
    return "Unspecified error";
}

/** @func _DisplayOpenGLError
 *  @brief Prints a user friendly message for the most recent OpenGL error (if any) to stdout.
 *  @param command The command that was run.
 *  @param file The file from which the command was run.
 *  @param line The line in the file where the command was fun.
 *
 *  This function is used by the OGL_CALL macro to provide debugging information in stdout when an OpenGL API call fails.
 */

inline void _DisplayOpenGLError(std::string command, std::string file, int line) {
    GLenum err = glGetError();
    if (err != GL_NO_ERROR) {
        std::cerr << "OpenGL Error: " << err << " -- " << _OpenGLErrorToString(err) << std::endl;
        std::cerr << "Relevant Command: " << command << std::endl;
        std::cerr << "Location: " << file << " at Line: " << line << std::endl;
    }
}


/** @def OGL_CALL
 *  @brief Provides an easy to use macro that wraps around OpenGL calls and checks their error.
 *  @param x The OpenGL command.
 *
 *  This is only defined in the Debug build when NDEBUG is NOT defined. If you are unfamiliar with C++
 *  preprocess macros, the __FILE__ macro, or the __LINE__ macro, you can read <a href="http://www.cplusplus.com/doc/tutorial/preprocessor/">this</a>
 *  for more information.
 */
#ifndef NDEBUG
#define OGL_CALL(x) x; _DisplayOpenGLError(#x, __FILE__, __LINE__);
#else
#define OGL_CALL(x) x;
#endif