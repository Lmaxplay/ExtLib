#include <iostream>
#include <filesystem>
#include <windows.h>
#include <direct.h>
#include <fstream>
#include <string>
#include <limits>

#include "lib/getExecutableName.h"
#include "lib/vector.hpp"


using namespace std;

int main() {
    vec2d a = {10, 20};
    vec2d b = {10, 20};
    vec2d c = a + b;
    cout << c.x << c.y << "\n";
    return 0;
}