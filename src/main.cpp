#include <iostream>
#include <filesystem>
#include <windows.h>
#include <direct.h>
#include <fstream>
#include <string>

#include "lib/getExecutableName.h"

using namespace std;


int main() {
    cout << "Hello World!!!\n";
    filesystem::path exePath = filesystem::path(getExecutableName()).parent_path();
    filesystem::path dataPath = exePath;
    string line;
    string prgstr = string(dataPath.string());
    char* prgchar = prgstr.data();
    char* configfile = strcat(prgchar, (char*)"\\data\\program.cfg");
    FILE* file = fopen(prgchar, "r");
    // ...buffer contains the entire file...

    dataPath.append("data");
    return 0;
}