#include "./math.hpp"

namespace math {
    // Fast inverse square root
    // See: http://en.wikipedia.org/wiki/Fast_inverse_square_root
    double fast_inverse_sqrt(double x) {
        double xhalf = 0.5f * x;
        int i = *(int*)&x;
        i = 0x5f3759df - (i >> 1);
        x = *(double*)&i;
        x = x * (1.5f - xhalf * x * x);
        return x;
    };

    // Floating point comparison
    // See: http://realtimecollisiondetection.net/blog/?p=89
    bool fequal(float a, float b) {
        return std::abs(a - b) < 0.00001f;
    };
}