SRC= ft_printf.c ft_parse.c libft.a pf_s.c ft_dispatcher.c ft_buffer.c

NAME= ft_printf

CC= gcc

DCFLAGS = -Wall -Wextra -Werror -g

CFLAGS= -Wall -Wextra -Werror

all:
	$(CC) $(CFLAGS) -o $(NAME) $(SRC)

debug:
	$(CC) $(DCFLAGS) -o $(NAME) $(SRC)


