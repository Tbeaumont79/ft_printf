SRC= ft_printf.c ft_parse.c libft.a pf_s.c ft_dispatcher.c ft_itoa_base.c ft_buffer.c pf_d.c

NAME= ft_printf

CC= gcc

DCFLAGS = -Wall -Wextra -Werror -g

CFLAGS= -Wall -Wextra -Werror

all:
	$(CC) $(CFLAGS) -o $(NAME) $(SRC)

debug:
	$(CC) $(DCFLAGS) -o $(NAME) $(SRC)


