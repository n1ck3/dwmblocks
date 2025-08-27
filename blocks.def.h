// Icons can be found here:
// - https://fontawesome.com/v4/cheatsheet/

//Modify this file to change what commands output to your statusbar, and recompile using the make command.
static const Block blocks[] = {
	/*Icon*/	/*Command*/		                                    /*Update Interval*/ /*Update Signal*/
	{"󰍛 ",      "$HOME/.config/dwmblocks/memory.sh",                10,                 0},
	{" ",      "$HOME/.config/dwmblocks/disk.sh",                  60,                 0},
	{" ",      "$HOME/.config/dwmblocks/cpu-temperature.sh",		60,                 0},
	{"󰂀 ",      "$HOME/.config/dwmblocks/battery.sh",               60,                 0},
	{"󰕾 ",      "$HOME/.config/dwmblocks/volume.sh",                0,                  10},
	{" ",      "$HOME/.config/dwmblocks/brightness.sh",            0,                  11},
	{"",		"$HOME/.config/dwmblocks/date.sh",					60,                 0},
	{" ",      "whoami",                                           0,                  0},
	{"",        "$HOME/.config/dwmblocks/reboot-required.sh",		5,                  0},
	//{"󰍛 ",    "$HOME/.config/dwm/scripts/dwmblocks-mem.sh",               30,                 0},
	//{" :",   "$HOME/.config/dwm/scripts/dwmblocks-disk.sh",              30,                 0},
	//{"󰂀 ",    "$HOME/.config/dwm/scripts/dwmblocks-bat.sh",               30,                 0},
	//{"󰕾 ",    "$HOME/.config/dwm/scripts/dwmblocks-vol.sh",               1,                  0},
	//{"󰃰 ",    "$HOME/.config/dwm/scripts/dwmblocks-date.sh",              5,                  0},
};

//sets delimiter between status commands. NULL character ('\0') means no delimiter.
static char delim[] = " | ";
static unsigned int delimLen = 5;
