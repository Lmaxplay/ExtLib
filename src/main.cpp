#include <iostream>
#include <filesystem>
#include <windows.h>
#include <direct.h>
#include <fstream>
#include <string>
#include <limits>

#include "lib/getExecutableName.h" // Currently unused
#include "lib/vector.hpp"


using namespace std;

// Main function
int main() {
    vec4d a = {10, 20, 30, 40};
    vec4d b = {10, 20, 30, 40};
    vec4d c = a + b;
    cout << "Of the vector (" << c << ") the length is: " << c.getmagnitude() << " its size is: " << sizeof(c) << "\n";
    return 0;
}
