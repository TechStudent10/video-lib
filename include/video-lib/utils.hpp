#pragma once

struct Vector2D {
    double x;
    double y;

public:
    Vector2D operator+(const Vector2D& other) {
        return { x + other.x, y + other.y };
    }

    Vector2D operator-(const Vector2D& other) {
        return { x - other.x, y - other.y };
    }

    Vector2D operator*(const Vector2D& other) {
        return { x * other.x, y * other.y };
    }

    Vector2D operator/(const Vector2D& other) {
        return { x / other.x, y / other.y };
    }

    Vector2D operator+(const double& other) {
        return { x + other, y + other };
    }

    Vector2D operator-(const double& other) {
        return { x - other, y - other };
    }

    Vector2D operator*(const double& other) {
        return { x * other, y * other };
    }

    Vector2D operator/(const double& other) {
        return { x / other, y / other };
    }
};

struct Transform {
    Vector2D position;
    // 0.5, 0.5 = center
    // 0, 0 = top left
    // 0, 1 = top right
    // 1, 0 = bottom left
    // 1, 1 = bottom right
    Vector2D anchorPoint = { 0.5, 0.5 };
    float rotation;
    float pitch;
    float roll; 
};

struct Color {
    int r; int g; int b; int a = 255;

    Color fade(float progress) {
        return {
            r,
            g,
            b,
            static_cast<int>(a * progress)
        };
    }
};

struct Dimensions {
    Vector2D size;
    Transform transform;
};
