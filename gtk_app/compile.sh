#!/bin/bash

# backtick [`]

g++ first.cpp `pkg-config --libs gtk+-2.0` `pkg-config --cflags gtk+-2.0`

# cp first.cpp tmp.c
# gcc tmp.c `pkg-config --libs gtk+-2.0` `pkg-config --cflags gtk+-2.0`
# rm tmp.c