#include <math.h>
#include <string>

namespace math
{
    // Fast inverse square root
    // See: http://en.wikipedia.org/wiki/Fast_inverse_square_root
    double fast_inverse_sqrt(double x);

    // Floating point comparison
    // See: http://realtimecollisiondetection.net/blog/?p=89
    bool fequal(float a, float b);
}