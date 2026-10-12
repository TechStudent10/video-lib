#pragma once

#include <vector>
// #include <common.hpp>
#include "utils.hpp"

#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>

class Frame {
protected:
    enum class ShapeType {
        Rect,
        Circle
    };

    void primitiveDraw(Transform transform, Vector2D size, Color color, ShapeType type = ShapeType::Rect);
    std::vector<unsigned char> imageData;
public:
    int width;
    int height;

    unsigned int fbo;
    unsigned int textureID;

    unsigned int shapeShaderProgram;
    unsigned int texShaderProgram;
    unsigned int texYUVShaderProgram;
    // unsigned int rectVAO, rectVBO;
    unsigned int VAO, VBO, EBO;

    Frame(int width, int height);

    void clearFrame(Color color = { 0, 0, 0, 255 });

    void putPixel(Vector2D position, Color color);
    Color getPixel(Vector2D position);

    void drawRect(Dimensions dimensions, Color color);
    void drawLine(Vector2D start, Vector2D end, Color color, int thickness = 1);
    void drawCircle(Transform transform, int radius, Color color, bool filled = true);

    void drawTexture(unsigned int texture, Vector2D size, Transform transform, unsigned int VAO, unsigned int VBO, unsigned int EBO, float opacity = 1.f);
    void drawTextureYUV(unsigned int textureY, unsigned int textureU, unsigned int textureV, Vector2D size, Transform transform, unsigned int VAO, unsigned int VBO, unsigned int EBO, float opacity = 1.f);

    // 0.5, 0.5 = center
    // 0, 0 = top left
    // 0, 1 = top right
    // 1, 0 = bottom left
    // 1, 1 = bottom right
    glm::mat4 createBaseMatrix(Vector2D anchorPoint = { 0.5, 0.5 });
    glm::mat4 createModelFromTransform(Transform transform, Vector2D pos, Vector2D size, bool reverseY = false);

    std::vector<unsigned char> getFrameData();
};