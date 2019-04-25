#! /usr/bin/bash
gnome-terminal --window-with-profile=Bash -e 'bash -c "make -j; ./output; read;"'