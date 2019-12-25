SRC= ft_printf.c ft_parse.c libft.a pf_s.c ft_dispatcher.c ft_itoa_base.c ft_buffer.c pf_d.c pf_x.c pf_XU.c string_lower.c pf_p.c pf_c.c pf_u.c ft_width.c ft_nb_len.c ft_abs.c
NAME= ft_printf

CC= gcc

DCFLAGS = -Wall -Wextra -Werror -g

CFLAGS= -Wall -Wextra -Werror

all:
	$(CC) $(CFLAGS) -o $(NAME) $(SRC)

debug:
	$(CC) $(DCFLAGS) -o $(NAME) $(SRC)


