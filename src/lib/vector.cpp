#include "vector.hpp" // Importing function defenitions

void vec2i_copy(vec2i &dest, vec2i src) {
    int x = src.x;
    int y = src.y;
    dest.x = x;
    dest.y = y;
    return;
};

void vec2l_copy(vec2l &dest, vec2l src) {
    long x = src.x;
    long y = src.y;
    dest.x = x;
    dest.y = y;
    return;
};

void vec2f_copy(vec2f &dest, vec2f src) {
    float x = src.x;
    float y = src.y;
    dest.x = x;
    dest.y = y;
    return;
}
void vec2d_copy(vec2d &dest, vec2d src) {
    double x = src.x;
    double y = src.y;
    dest.x = x;
    dest.y = y;
    return;
}

void vec2i_add(vec2i dest, vec2i a, vec2i b) {
    dest.x = a.x + b.x;
    dest.y = a.y + b.y;
    return;
}

void vec2l_add(vec2l dest, vec2l a, vec2l b) {
    dest.x = a.x + b.x;
    dest.y = a.y + b.y;
    return;
}

void vec2f_add(vec2f dest, vec2f a, vec2f b) {
    dest.x = a.x + b.x;
    dest.y = a.y + b.y;
    return;
}

void vec2d_add(vec2d dest, vec2d a, vec2d b) {
    dest.x = a.x + b.x;
    dest.y = a.y + b.y;
    return;
}

void vec2i_sub(vec2i dest, vec2i a, vec2i b) {
    dest.x = a.x - b.x;
    dest.y = a.y - b.y;
    return;
}

void vec2l_sub(vec2l dest, vec2l a, vec2l b) {
    dest.x = a.x - b.x;
    dest.y = a.y - b.y;
    return;
}

void vec2f_sub(vec2f dest, vec2f a, vec2f b) {
    dest.x = a.x - b.x;
    dest.y = a.y - b.y;
    return;
}

void vec2d_sub(vec2d dest, vec2d a, vec2d b) {
    dest.x = a.x - b.x;
    dest.y = a.y - b.y;
    return;
}

void vec2i_div(vec2i dest, vec2i a, vec2i b) {
    dest.x = a.x / b.x;
    dest.y = a.y / b.y;
    return;
}

void vec2l_div(vec2l dest, vec2l a, vec2l b) {
    dest.x = a.x / b.x;
    dest.y = a.y / b.y;
    return;
}

void vec2f_div(vec2f dest, vec2f a, vec2f b) {
    dest.x = a.x / b.x;
    dest.y = a.y / b.y;
    return;
}

void vec2d_div(vec2d dest, vec2d a, vec2d b) {
    dest.x = a.x / b.x;
    dest.y = a.y / b.y;
    return;
}

void vec2i_mul(vec2i dest, vec2i a, vec2i b) {
    dest.x = a.x * b.x;
    dest.y = a.y * b.y;
    return;
}

void vec2l_mul(vec2l dest, vec2l a, vec2l b) {
    dest.x = a.x * b.x;
    dest.y = a.y * b.y;
    return;
}

void vec2f_mul(vec2f dest, vec2f a, vec2f b) {
    dest.x = a.x * b.x;
    dest.y = a.y * b.y;
    return;
}

void vec2d_mul(vec2d dest, vec2d a, vec2d b) {
    dest.x = a.x * b.x;
    dest.y = a.y * b.y;
    return;
}



void vec3i_copy(vec3i &dest, vec3i src) {
    int x = src.x;
    int y = src.y;
    int z = src.z;
    dest.x = x;
    dest.y = y;
    dest.z = z;
    return;
};

void vec3l_copy(vec3l &dest, vec3l src) {
    long x = src.x;
    long y = src.y;
    long z = src.z;
    dest.x = x;
    dest.y = y;
    dest.z = z;
    return;
};

void vec3f_copy(vec3f &dest, vec3f src) {
    float x = src.x;
    float y = src.y;
    float z = src.z;
    dest.x = x;
    dest.y = y;
    dest.z = z;
    return;
}
void vec3d_copy(vec3d &dest, vec3d src) {
    double x = src.x;
    double y = src.y;
    double z = src.z;
    dest.x = x;
    dest.y = y;
    dest.z = z;
    return;
}