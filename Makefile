SRC= ft_printf.c ft_parse.c libft.a pf_s.c ft_dispatcher.c ft_itoa_base.c ft_buffer.c pf_d.c pf_x.c pf_XU.c string_lower.c pf_p.c

NAME= ft_printf

CC= gcc

DCFLAGS = -Wall -Wextra -Werror -g

CFLAGS= 

all:
	$(CC) $(CFLAGS) -o $(NAME) $(SRC)

debug:
	$(CC) $(DCFLAGS) -o $(NAME) $(SRC)


