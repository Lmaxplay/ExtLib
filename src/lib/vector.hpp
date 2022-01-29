struct vec2i {int x; int y;};
struct vec2l {long x; long y;};
struct vec2f {float x; float y;};
struct vec2d {double x; double y;};

void vec2i_copy(vec2i &dest, vec2i src);
void vec2l_copy(vec2l &dest, vec2l src);
void vec2f_copy(vec2f &dest, vec2f src);
void vec2d_copy(vec2d &dest, vec2d src);

void vec2i_add(vec2i dest, vec2i a, vec2i b);
void vec2l_add(vec2l dest, vec2l a, vec2l b);
void vec2f_add(vec2f dest, vec2f a, vec2f b);
void vec2d_add(vec2d dest, vec2d a, vec2d b);

void vec2i_sub(vec2i dest, vec2i a, vec2i b);
void vec2l_sub(vec2l dest, vec2l a, vec2l b);
void vec2f_sub(vec2f dest, vec2f a, vec2f b);
void vec2d_sub(vec2d dest, vec2d a, vec2d b);

void vec2i_div(vec2i dest, vec2i a, vec2i b);
void vec2l_div(vec2l dest, vec2l a, vec2l b);
void vec2f_div(vec2f dest, vec2f a, vec2f b);
void vec2d_div(vec2d dest, vec2d a, vec2d b);

void vec2i_mul(vec2i dest, vec2i a, vec2i b);
void vec2l_mul(vec2l dest, vec2l a, vec2l b);
void vec2f_mul(vec2f dest, vec2f a, vec2f b);
void vec2d_mul(vec2d dest, vec2d a, vec2d b);


struct vec3i {int x; int y; int z;};
struct vec3l {long x; long y; long z;};
struct vec3f {float x; float y; float z;};
struct vec3d {double x; double y; double z;};

void vec3i_copy(vec3i &dest, vec3i src);
void vec3l_copy(vec3l &dest, vec3l src);
void vec3f_copy(vec3f &dest, vec3f src);
void vec3d_copy(vec3d &dest, vec3d src);

void vec3i_add(vec3i dest, vec3i a, vec3i b);
void vec3l_add(vec3l dest, vec3l a, vec3l b);
void vec3f_add(vec3f dest, vec3f a, vec3f b);
void vec3d_add(vec3d dest, vec3d a, vec3d b);

void vec3i_sub(vec3i dest, vec3i a, vec3i b);
void vec3l_sub(vec3l dest, vec3l a, vec3l b);
void vec3f_sub(vec3f dest, vec3f a, vec3f b);
void vec3d_sub(vec3d dest, vec3d a, vec3d b);

void vec3i_div(vec3i dest, vec3i a, vec3i b);
void vec3l_div(vec3l dest, vec3l a, vec3l b);
void vec3f_div(vec3f dest, vec3f a, vec3f b);
void vec3d_div(vec3d dest, vec3d a, vec3d b);
