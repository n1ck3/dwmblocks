# CLAUDE.md

This file provides guidance to Claude Code (claude.ai/code) when working with code in this repository.

## Project Overview

dwmblocks is a modular status bar for dwm that displays output from shell commands at specified intervals. Each "block" runs a command and displays its output with an optional icon prefix.

## Build Commands

- **Quick build**: `make`
- **Clean build**: `make clean && make`  
- **Install system-wide**: `sudo make install` (installs to `/usr/local/bin`)
- **Uninstall**: `sudo make uninstall`
- **Note**: No unit tests - this is a status bar utility

## Repository Structure

### Key Files
- `blocks.def.h` - Default blocks configuration (copy to `blocks.h` before building)
- `blocks.h` - Active blocks configuration (generated from blocks.def.h on first build)
- `dwmblocks.c` - Main program source
- `Makefile` - Build configuration
- `install.sh` - Installation helper script

### Branch Strategy
- `master` - Main development branch
- `prod` - Production customizations

## Architecture

### Core Components

**Block Structure** (`blocks.h`)
- Icon: Visual prefix for block output
- Command: Shell command or script path (typically in `$HOME/.config/dwmblocks/`)
- Update Interval: Seconds between updates (0 = signal-only update)
- Update Signal: Signal number for manual updates (0 = no signal)

**Main Program** (`dwmblocks.c`)
- Executes block commands at specified intervals
- Updates X11 root window name (dwm reads this as status text)
- Handles signals for instant block updates
- Output limit: CMDLENGTH (50 characters per block)

### Program Flow
1. `statusloop()` - Main loop checking intervals
2. `getcmd()` - Executes shell command via popen
3. `getstatus()` - Concatenates all blocks with delimiter
4. `setroot()` - Updates X11 root window if changed
5. Signal handlers - Allow manual block updates

### Signal System
- Uses SIGRTMIN + signal number from blocks.h
- Example: Signal 10 in blocks.h = SIGRTMIN+10
- Send signals: `pkill -RTMIN+10 dwmblocks`

## Development Workflow

### Modifying Blocks
1. Edit `blocks.h` to add/modify blocks
2. Rebuild: `make clean && make`
3. Restart: `pkill dwmblocks && ./dwmblocks`

### Testing Changes
```bash
# Build and test locally
make clean && make
pkill dwmblocks
./dwmblocks

# Install system-wide
sudo make install
```

### Updating Specific Blocks via Signal
```bash
pkill -RTMIN+10 dwmblocks  # Update volume (signal 10)
pkill -RTMIN+11 dwmblocks  # Update brightness (signal 11)
```

### Command Line Options
- `-d <delimiter>` - Set delimiter between blocks
- `-p` - Output to stdout instead of X11 root window

## Code Style
- **Language**: C (ANSI/C99)
- **Indentation**: Tabs
- **Naming**: snake_case for functions/variables
- **Constants**: UPPERCASE for macros
- **Memory**: Proper cleanup of file handles and X resources