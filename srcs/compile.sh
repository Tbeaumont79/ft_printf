#!/bin/bash
cd ../
make re
cd -
gcc -Wall -Wextra -Werror -g -fsanitize=address *.c ../libftprintf.a ../headers/ft_printf.h
./a.out d

