#pragma once

namespace dye {
	extern const char* reset = "\033[0m";
	extern const char* bold = "\033[1m";
	extern const char* dim = "\033[2m";
	extern const char* italic = "\033[3m";
	extern const char* underline = "\033[4m";
	extern const char* slow_blink = "\033[5m";
	extern const char* rapid_blink = "\033[6m";
	extern const char* reverse = "\033[7m";
	extern const char* hidden = "\033[8m";
	extern const char* strikethrough = "\033[9m";

	extern const char* black = "\033[30m";
	extern const char* red = "\033[31m";
	extern const char* green = "\033[32m";
	extern const char* yellow = "\033[33m";
	extern const char* blue = "\033[34m";
	extern const char* magenta = "\033[35m";
	extern const char* cyan = "\033[36m";
	extern const char* white = "\033[37m";

	extern const char* bg_black = "\033[40m";
	extern const char* bg_red = "\033[41m";
	extern const char* bg_green = "\033[42m";
	extern const char* bg_yellow = "\033[43m";
	extern const char* bg_blue = "\033[44m";
	extern const char* bg_magenta = "\033[45m";
	extern const char* bg_cyan = "\033[46m";
	extern const char* bg_white = "\033[47m";

	extern const char* bright_black = "\033[90m";
	extern const char* bright_red = "\033[91m";
	extern const char* bright_green = "\033[92m";
	extern const char* bright_yellow = "\033[93m";
	extern const char* bright_blue = "\033[94m";
	extern const char* bright_magenta = "\033[95m";
	extern const char* bright_cyan = "\033[96m";
	extern const char* bright_white = "\033[97m";
	
	extern const char* bg_bright_black = "\033[100m";
	extern const char* bg_bright_red = "\033[101m";
	extern const char* bg_bright_green = "\033[102m";
	extern const char* bg_bright_yellow = "\033[103m";
	extern const char* bg_bright_blue = "\033[104m";
	extern const char* bg_bright_magenta = "\033[105m";
	extern const char* bg_bright_cyan = "\033[106m";
	extern const char* bg_bright_white = "\033[107m";

	extern const char* fg_default = "\033[39m";
	extern const char* bg_default = "\033[49m";

	extern const char* reset_bold = "\033[21m";
	extern const char* bold_off = "\033[22m";
	extern const char* italic_off = "\033[23m";
	extern const char* underline_off = "\033[24m";
	extern const char* slow_blink_off = "\033[25m";
	extern const char* rapid_blink_off = "\033[26m";
	extern const char* reverse_off = "\033[27m";
	extern const char* hidden_off = "\033[28m";
	extern const char* strikethrough_off = "\033[29m";
}
