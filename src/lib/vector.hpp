// ! Using structs since C++ broke C syntax :(

struct vec2i {int x; int y;};
struct vec2l {long x; long y;};
struct vec2f {float x; float y;};
struct vec2d {double x; double y;};

void *vec2i_copy(vec2i &dest, vec2i src);
void *vec2l_copy(vec2l &dest, vec2l src);
void *vec2f_copy(vec2f &dest, vec2f src);
void *vec2d_copy(vec2d &dest, vec2d src);

void *vec2i_add(vec2i src, vec2i a);
void *vec2l_add(vec2l src, vec2l a);
void *vec2f_add(vec2f src, vec2f a);
void *vec2d_add(vec2d src, vec2d a);



struct vec3i {int x; int y; int z;};
struct vec3l {long x; long y; long z;};
struct vec3f {float x; float y; float z;};
struct vec3d {double x; double y; double z;};

void *vec3i_copy(vec3i &dest, vec3i src);
void *vec3l_copy(vec3l &dest, vec3l src);
void *vec3f_copy(vec3f &dest, vec3f src);
void *vec3d_copy(vec3d &dest, vec3d src);

void *vec3i_add(vec3i src, vec3i a);
void *vec3l_add(vec3l src, vec3l a);
void *vec3f_add(vec3f src, vec3f a);
void *vec3d_add(vec3d src, vec3d a);