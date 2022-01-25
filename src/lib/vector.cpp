#include "vector.hpp" // Importing function defenitions

void *vec2i_copy(vec2i &dest, vec2i src) {
    int x = src.x;
    int y = src.y;
    dest.x = x;
    dest.y = y;
    return &dest;
};

void *vec2l_copy(vec2l &dest, vec2l src) {
    long x = src.x;
    long y = src.y;
    dest.x = x;
    dest.y = y;
    return &dest;
};

void *vec2f_copy(vec2f &dest, vec2f src) {
    float x = src.x;
    float y = src.y;
    dest.x = x;
    dest.y = y;
    return &dest;
}
void *vec2d_copy(vec2d &dest, vec2d src) {
    double x = src.x;
    double y = src.y;
    dest.x = x;
    dest.y = y;
    return &dest;
}

void *vec3i_copy(vec3i &dest, vec3i src) {
    int x = src.x;
    int y = src.y;
    int z = src.z;
    dest.x = x;
    dest.y = y;
    dest.z = z;
    return &dest;
};

void *vec3l_copy(vec3l &dest, vec3l src) {
    long x = src.x;
    long y = src.y;
    long z = src.z;
    dest.x = x;
    dest.y = y;
    dest.z = z;
    return &dest;
};

void *vec3f_copy(vec3f &dest, vec3f src) {
    float x = src.x;
    float y = src.y;
    float z = src.z;
    dest.x = x;
    dest.y = y;
    dest.z = z;
    return &dest;
}
void *vec3d_copy(vec3d &dest, vec3d src) {
    double x = src.x;
    double y = src.y;
    double z = src.z;
    dest.x = x;
    dest.y = y;
    dest.z = z;
    return &dest;
}