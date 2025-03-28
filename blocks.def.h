// Icons can be found here:
// - https://fontawesome.com/v4/cheatsheet/

//Modify this file to change what commands output to your statusbar, and recompile using the make command.
static const Block blocks[] = {
	/*Icon*/	/*Command*/		                                            /*Update Interval*/ /*Update Signal*/
	{"󰍛 ",      "$HOME/.config/dwmblocks/scripts/memory.sh",                30,                 0},
	{" ",      "$HOME/.config/dwmblocks/scripts/disk.sh",                  30,                 0},
	{"󰂀 ",      "$HOME/.config/dwmblocks/scripts/battery.sh",               30,                 0},
	{"󰕾 ",      "$HOME/.config/dwmblocks/scripts/volume.sh",                0,                  10},
	{" ",      "$HOME/.config/dwmblocks/scripts/date.sh",                  60,                 0},
	{" ",      "whoami",                                                   0,                  0},
	{"",        "$HOME/.config/dwmblocks/scripts/reboot-required.sh",       5,                  0},
	//{"󰍛 ",    "$HOME/.config/dwm/scripts/dwmblocks-mem.sh",               30,                 0},
	//{" :",   "$HOME/.config/dwm/scripts/dwmblocks-disk.sh",              30,                 0},
	//{"󰂀 ",    "$HOME/.config/dwm/scripts/dwmblocks-bat.sh",               30,                 0},
	//{"󰕾 ",    "$HOME/.config/dwm/scripts/dwmblocks-vol.sh",               1,                  0},
	//{"󰃰 ",    "$HOME/.config/dwm/scripts/dwmblocks-date.sh",              5,                  0},
};

//sets delimiter between status commands. NULL character ('\0') means no delimiter.
static char delim[] = " | ";
static unsigned int delimLen = 5;
