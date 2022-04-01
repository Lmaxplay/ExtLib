#include <string>
#include <windows.h>

std::wstring getExecutableName()
{
#if defined(PLATFORM_POSIX) || defined(__linux__) //check defines for your setup

    std::string sp;
    std::ifstream("/proc/self/comm") >> sp;
    return sp;

#elif defined(_WIN32)
    wchar_t buf[MAX_PATH];
    GetModuleFileNameW(nullptr, buf, MAX_PATH);
    return buf;

#else

    static_assert(false, "unrecognized platform");

#endif
}