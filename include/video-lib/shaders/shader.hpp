#pragma once

namespace shader {
    unsigned int compileShader(unsigned int type, const char* source);
    unsigned int createProgram(const char* vertex, const char* fragment);
}
