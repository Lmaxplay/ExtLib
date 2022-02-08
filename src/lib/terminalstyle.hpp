#include <iostream>

// Foreground colors
#define ansi_fg_black "\033[1;30m"
#define ansi_fg_red "\033[1;31m"
#define ansi_fg_green "\033[1;32m"
#define ansi_fg_yellow "\033[1;33m"
#define ansi_fg_blue "\033[1;34m"
#define ansi_fg_magenta "\033[1;35m"
#define ansi_fg_cyan "\033[1;36m"
#define ansi_fg_white "\033[1;37m"
#define ansi_fg_default "\033[1;39m"

// Background colors
#define ansi_bg_black "\033[1;40m"
#define ansi_bg_red "\033[1;41m"
#define ansi_bg_green "\033[1;42m"
#define ansi_bg_yellow "\033[1;43m"
#define ansi_bg_blue "\033[1;44m"
#define ansi_bg_magenta "\033[1;45m"
#define ansi_bg_cyan "\033[1;46m"
#define ansi_bg_white "\033[1;47m"
#define ansi_bg_default "\033[1;49m"

// Various style controls
#define ansi_reset "\033[1;0m" // Resets styles
#define ansi_bold "\033[1;1m" // makes it bold/bright, this is often a brighter shade of the same color
#define ansi_bright "\033[1;1m" // makes it bold/bright, this is often a brighter shade of the same color
#define ansi_underline "\033[1;4m"
#define ansi_underlined "\033[1;4m"
#define ansi_crossed "\033[1;9m"
#define ansi_crossed_out "\033[1;9m"
#define ansi_blink "\033[1;5m"
#define ansi_blink_slow "\033[1;5m"
#define ansi_blink_fast "\033[1;6m" // Not widely supported
#define ansi_overline "\033[1;53m"
#define ansi_overlined "\033[1;53m"
#define ansi_inverse "\033[1;7m" // Swap foreground and background colors
#define ansi_bold_off "\033[1;21m"
#define ansi_bright_off "\033[1;21m"
#define ansi_underline_off "\033[1;24m"
#define ansi_underlined_off "\033[1;24m"
#define ansi_inverse_off "\033[1;27m"
#define ansi_crossed_off "\033[1;29m"
#define ansi_crossed_out_off "\033[1;29m"
#define ansi_blink_off "\033[1;25m"
#define ansi_overline_off "\033[1;55m"
#define ansi_overlined_off "\033[1;55m"
#define ansi_intensity_normal "\033[1;21m"
#define ansi_intensity_increased "\033[1;1m"
#define ansi_intensity_decreased "\033[1;2m" // Light font weight


// Foreground colors
#define ansi_w_fg_black L"\033[1;30m"
#define ansi_w_fg_red L"\033[1;31m"
#define ansi_w_fg_green L"\033[1;32m"
#define ansi_w_fg_yellow L"\033[1;33m"
#define ansi_w_fg_blue L"\033[1;34m"
#define ansi_w_fg_magenta L"\033[1;35m"
#define ansi_w_fg_cyan L"\033[1;36m"
#define ansi_w_fg_white L"\033[1;37m"
#define ansi_w_fg_default L"\033[1;39m"

// Background colors
#define ansi_w_bg_black L"\033[1;40m"
#define ansi_w_bg_red L"\033[1;41m"
#define ansi_w_bg_green L"\033[1;42m"
#define ansi_w_bg_yellow L"\033[1;43m"
#define ansi_w_bg_blue L"\033[1;44m"
#define ansi_w_bg_magenta L"\033[1;45m"
#define ansi_w_bg_cyan L"\033[1;46m"
#define ansi_w_bg_white L"\033[1;47m"
#define ansi_w_bg_default L"\033[1;49m"

// Various style controls
#define ansi_w_reset L"\033[1;0m" // Resets styles
#define ansi_w_bold L"\033[1;1m" // makes it bold/bright, this is often a brighter shade of the same color
#define ansi_w_bright L"\033[1;1m" // makes it bold/bright, this is often a brighter shade of the same color
#define ansi_w_underline L"\033[1;4m"
#define ansi_w_underlined L"\033[1;4m"
#define ansi_w_crossed L"\033[1;9m"
#define ansi_w_crossed_out L"\033[1;9m"
#define ansi_w_blink L"\033[1;5m"
#define ansi_w_blink_slow L"\033[1;5m"
#define ansi_w_blink_fast L"\033[1;6m" // Not widely supported
#define ansi_w_overline L"\033[1;53m"
#define ansi_w_overlined L"\033[1;53m"
#define ansi_w_inverse L"\033[1;7m" // Swap foreground and background colors
#define ansi_w_bold_off L"\033[1;21m"
#define ansi_w_bright_off L"\033[1;21m"
#define ansi_w_underline_off L"\033[1;24m"
#define ansi_w_underlined_off L"\033[1;24m"
#define ansi_w_inverse_off L"\033[1;27m"
#define ansi_w_crossed_off L"\033[1;29m"
#define ansi_w_crossed_out_off L"\033[1;29m"
#define ansi_w_blink_off L"\033[1;25m"
#define ansi_w_overline_off L"\033[1;55m"
#define ansi_w_overlined_off L"\033[1;55m"
#define ansi_w_intensity_normal L"\033[1;21m"
#define ansi_w_intensity_increased L"\033[1;1m"
#define ansi_w_intensity_decreased L"\033[1;2m" // Light font weight

#define ansi_newline "\n"
#define ansi_w_newline L"\n"

#define coutred std::cout << ansi_fg_red << ansi_intensity_increased
#define coutgreen std::cout << ansi_fg_green << ansi_intensity_increased
#define coutyellow std::cout << ansi_fg_yellow << ansi_intensity_increased
#define coutblue std::cout << ansi_fg_blue << ansi_intensity_increased
#define coutmagenta std::cout << ansi_fg_magenta << ansi_intensity_increased
#define coutcyan std::cout << ansi_fg_cyan << ansi_intensity_increased
#define coutwhite std::cout << ansi_fg_white << ansi_intensity_increased
#define coutblack std::cout << ansi_fg_black << ansi_intensity_increased
#define coutdarkred std::cout << ansi_fg_red << ansi_intensity_decreased
#define coutdarkgreen std::cout << ansi_fg_green << ansi_intensity_decreased
#define coutdarkyellow std::cout << ansi_fg_yellow << ansi_intensity_decreased
#define coutdarkblue std::cout << ansi_fg_blue << ansi_intensity_decreased
#define coutdarkmagenta std::cout << ansi_fg_magenta << ansi_intensity_decreased
#define coutdarkcyan std::cout << ansi_fg_cyan << ansi_intensity_decreased
#define coutdarkwhite std::cout << ansi_fg_white << ansi_intensity_decreased
#define coutdarkblack std::cout << ansi_fg_black << ansi_intensity_decreased
#define coutreset std::cout << ansi_reset
#define consolereset std::cout << ansi_reset
