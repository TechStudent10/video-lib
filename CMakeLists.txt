cmake_minimum_required(VERSION 3.21...4.0)
set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

project(video-lib VERSION 1.0.0)

file(GLOB_RECURSE SOURCES CONFIGURE_DEPENDS src/*.cpp)
add_library(${PROJECT_NAME} ${SOURCES})

include(cmake/CPM.cmake)

CPMAddPackage("gh:g-truc/glm#6f14f47")
CPMAddPackage("gh:geode-sdk/result@1.4.1")
CPMAddPackage("gh:fmtlib/fmt#12.0.0")

find_package(OpenGL REQUIRED)

add_library(glad STATIC
    vendor/glad/src/gl.c
)
target_include_directories(glad PUBLIC vendor/glad/include)

target_include_directories(${PROJECT_NAME} PUBLIC include)
target_link_libraries(${PROJECT_NAME} PRIVATE OpenGL::GL glm::glm fmt glad)

target_include_directories(${PROJECT_NAME} INTERFACE
    $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
    $<INSTALL_INTERFACE:include>
)
