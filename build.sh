#!/bin/sh
gcc -Os sokol/sokol.c -I./sokol main.c -lX11 -lGL -lm -lpthread -ldl -lXcursor -lXi -o zeq
strip zeq
