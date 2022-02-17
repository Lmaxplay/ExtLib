#include "memory.hpp"

MEMORYSTATUSEX getSystemMemory()
{
    MEMORYSTATUSEX status;
    status.dwLength = sizeof(status);
    GlobalMemoryStatusEx(&status);
    return status;
};
