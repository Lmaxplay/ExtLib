#include <iostream>
#include <filesystem>
#include <windows.h>
#include <direct.h>
#include <fstream>
#include <string>

#include "lib/getExecutableName.h"
#include "lib/vector.hpp"

using namespace std;


int main() {
    vec2i vector = {0, 3};
    vec2i vector2{};
    long i = 0;
    while (i <= 1000000000) {
        i++;
        vec2i_copy(vector2, vector);
    }
    cout << vector2.x << " " << vector2.y << "\n";

    return 0;
}