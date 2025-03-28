#!/usr/bin/env bash

# cd $HOME/suckless/dwm-flexipath

make clean

rm blocks.h &> /dev/null

make
if [[ "$?" > 0 ]] ; then
    echo
    echo "!!! Make went wrong. :( Exiting..."
    exit 1
fi

sudo make clean install

pkill dwmblocks ; dwmblocks &
