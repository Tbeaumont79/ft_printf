#!/bin/bash
cd ../
make re
cd -
gcc -Wall -Wextra -Werror -fsanitize=address  *.c ../libftprintf.a ../headers/ft_printf.h

