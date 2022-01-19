#include <iostream>
#include <filesystem>
#include <windows.h>
#include <direct.h>
#include <fstream>

#include "lib/getExecutableName.h"

using namespace std;


int main() {
    cout << "Hello World!!!\n";
    filesystem::path exePath = filesystem::path(getExecutableName()).parent_path();
    filesystem::path dataPath = exePath;
    dataPath.append("data");
    std::ifstream ifs(filesystem::path(dataPath).append("program.cfg"));
    std::string content( (std::istreambuf_iterator<char>(ifs) ), (std::istreambuf_iterator<char>()    ) );
    std::cout << content;
    return 0;
}