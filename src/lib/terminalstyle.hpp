#include <iostream>

// ANSI terminal manipulation
namespace ansi {
    const char* fg_black = "\033[1;30m";
    const char* fg_red = "\033[1;31m";
    const char* fg_green = "\033[1;32m";
    const char* fg_yellow = "\033[1;33m";
    const char* fg_blue = "\033[1;34m";
    const char* fg_magenta = "\033[1;35m";
    const char* fg_cyan = "\033[1;36m";
    const char* fg_white = "\033[1;37m";
    const char* fg_default = "\033[1;39m";

    const char* bg_black = "\033[1;40m";
    const char* bg_red = "\033[1;41m";
    const char* bg_green = "\033[1;42m";
    const char* bg_yellow = "\033[1;43m";
    const char* bg_blue = "\033[1;44m";
    const char* bg_magenta = "\033[1;45m";
    const char* bg_cyan = "\033[1;46m";
    const char* bg_white = "\033[1;47m";
    const char* bg_default = "\033[1;49m";

    const char* reset = "\033[1;0m"; // Resets styles
    const char* bold = "\033[1;1m"; // makes it bold/bright, this is often a brighter shade of the same color
    const char* bright = "\033[1;1m"; // makes it bold/bright, this is often a brighter shade of the same color
    const char* underline = "\033[1;4m";
    const char* underlined = "\033[1;4m";
    const char* crossed = "\033[1;9m";
    const char* crossed_out = "\033[1;9m";
    const char* blink = "\033[1;5m";
    const char* blink_slow = "\033[1;5m";
    const char* blink_fast = "\033[1;6m"; // Not widely supported
    const char* overline = "\033[1;53m";
    const char* overlined = "\033[1;53m";
    const char* inverse = "\033[1;7m"; // Swap foreground and background colors
    const char* bold_off = "\033[1;21m";
    const char* bright_off = "\033[1;21m";
    const char* underline_off = "\033[1;24m";
    const char* underlined_off = "\033[1;24m";
    const char* inverse_off = "\033[1;27m";
    const char* crossed_off = "\033[1;29m";
    const char* crossed_out_off = "\033[1;29m";
    const char* blink_off = "\033[1;25m";
    const char* overline_off = "\033[1;55m";
    const char* overlined_off = "\033[1;55m";
    const char* intensity_normal = "\033[1;21m";
    const char* intensity_increased = "\033[1;1m";
    const char* intensity_decreased = "\033[1;2m"; // Light font weight

    const wchar_t* w_fg_black = L"\033[1;30m";
    const wchar_t* w_fg_red = L"\033[1;31m";
    const wchar_t* w_fg_green = L"\033[1;32m";
    const wchar_t* w_fg_yellow = L"\033[1;33m";
    const wchar_t* w_fg_blue = L"\033[1;34m";
    const wchar_t* w_fg_magenta = L"\033[1;35m";
    const wchar_t* w_fg_cyan = L"\033[1;36m";
    const wchar_t* w_fg_white = L"\033[1;37m";
    const wchar_t* w_fg_default = L"\033[1;39m";

    const wchar_t* w_bg_black = L"\033[1;40m";
    const wchar_t* w_bg_red = L"\033[1;41m";
    const wchar_t* w_bg_green = L"\033[1;42m";
    const wchar_t* w_bg_yellow = L"\033[1;43m";
    const wchar_t* w_bg_blue = L"\033[1;44m";
    const wchar_t* w_bg_magenta = L"\033[1;45m";
    const wchar_t* w_bg_cyan = L"\033[1;46m";
    const wchar_t* w_bg_white = L"\033[1;47m";
    const wchar_t* w_bg_default = L"\033[1;49m";

    const wchar_t* w_reset = L"\033[1;0m"; // Resets styles
    const wchar_t* w_bold = L"\033[1;1m"; // makes it bold/bright, this is often a brighter shade of the same color
    const wchar_t* w_bright = L"\033[1;1m"; // makes it bold/bright, this is often a brighter shade of the same color
    const wchar_t* w_underline = L"\033[1;4m";
    const wchar_t* w_underlined = L"\033[1;4m";
    const wchar_t* w_crossed = L"\033[1;9m";
    const wchar_t* w_crossed_out = L"\033[1;9m";
    const wchar_t* w_blink = L"\033[1;5m";
    const wchar_t* w_blink_slow = L"\033[1;5m";
    const wchar_t* w_blink_fast = L"\033[1;6m"; // Not widely supported
    const wchar_t* w_overline = L"\033[1;53m";
    const wchar_t* w_overlined = L"\033[1;53m";
    const wchar_t* w_inverse = L"\033[1;7m"; // Swap foreground and background colors
    const wchar_t* w_bold_off = L"\033[1;21m";
    const wchar_t* w_bright_off = L"\033[1;21m";
    const wchar_t* w_underline_off = L"\033[1;24m";
    const wchar_t* w_underlined_off = L"\033[1;24m";
    const wchar_t* w_inverse_off = L"\033[1;27m";
    const wchar_t* w_crossed_off = L"\033[1;29m";
    const wchar_t* w_crossed_out_off = L"\033[1;29m";
    const wchar_t* w_blink_off = L"\033[1;25m";
    const wchar_t* w_overline_off = L"\033[1;55m";
    const wchar_t* w_overlined_off = L"\033[1;55m";
    const wchar_t* w_intensity_normal = L"\033[1;21m";
    const wchar_t* w_intensity_increased = L"\033[1;1m";
    const wchar_t* w_intensity_decreased = L"\033[1;2m"; // Light font weight

    const char* newline = "\n";
    const wchar_t* w_newline = L"\n";
    const char* upline = "\x1b[A";
    const wchar_t* w_upline = L"\x1b[A";

    const char* clearline = "\33[2K\r";
    const wchar_t* w_clearline = L"\33[2K\r";
}

#define coutred std::cout << ansi::fg_red << ansi::intensity_increased
#define coutgreen std::cout << ansi::fg_green << ansi::intensity_increased
#define coutyellow std::cout << ansi::fg_yellow << ansi::intensity_increased
#define coutblue std::cout << ansi::fg_blue << ansi::intensity_increased
#define coutmagenta std::cout << ansi::fg_magenta << ansi::intensity_increased
#define coutcyan std::cout << ansi::fg_cyan << ansi::intensity_increased
#define coutwhite std::cout << ansi::fg_white << ansi::intensity_increased
#define coutblack std::cout << ansi::fg_black << ansi::intensity_increased
#define coutdarkred std::cout << ansi::fg_red << ansi::intensity_decreased
#define coutdarkgreen std::cout << ansi::fg_green << ansi::intensity_decreased
#define coutdarkyellow std::cout << ansi::fg_yellow << ansi::intensity_decreased
#define coutdarkblue std::cout << ansi::fg_blue << ansi::intensity_decreased
#define coutdarkmagenta std::cout << ansi::fg_magenta << ansi::intensity_decreased
#define coutdarkcyan std::cout << ansi::fg_cyan << ansi::intensity_decreased
#define coutdarkwhite std::cout << ansi::fg_white << ansi::intensity_decreased
#define coutdarkblack std::cout << ansi::fg_black << ansi::intensity_decreased
#define coutreset std::cout << ansi::reset
#define consolereset std::cout << ansi::reset
