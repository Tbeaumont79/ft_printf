#!/bin/bash
cd ../
make re
cd -
gcc -Wall -Wextra -Werror -g  *.c ../libftprintf.a ../headers/ft_printf.h
./a.out d

