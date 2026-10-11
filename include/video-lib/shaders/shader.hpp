#pragma once

#include <glad/gl.h>

namespace shader {
    GLuint compileShader(GLenum type, const char* source);
    GLuint createProgram(const char* vertex, const char* fragment);
}
