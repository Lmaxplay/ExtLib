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
    string prgstr = string(dataPath.string() + "\\program.cfg");
    ifstream myfile(replace(prgstr.begin(), prgstr.end(), '\\', '/'));
    if (myfile.is_open())
    {
        //int index = 0;
        while ( getline (myfile,line) )
        {
            cout << line << '\n';
            line.find(":");
        }
        myfile.close();
    } else {
        cout << "Unable to open file\n";
    }
    dataPath.append("data");
    std::cout << (dataPath.string() + "\\program.cfg").compare("D:\\Projects\\CPPProgram\\output\\data\\program.cfg");
    return 0;
}