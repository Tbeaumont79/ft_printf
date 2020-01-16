DIR_S = srcs

DIR_O = objs

SOURCES = ft_printf.c \
			ft_parse.c \
			pf_s.c \
			ft_dispatcher.c \
			ft_itoa_base.c \
			ft_buffer.c \
			pf_d.c \
			ft_abs.c \
			pf_XU.c \
			ft_abs.c \
			pf_c.c \
			pf_p.c \
			string_lower.c \
			ft_width.c \
			ft_nb_len.c \
			ft_abs.c \
			ft_get_flag.c \
			ft_get_int.c \
			justify.c \
			pf_u.c \
			pf_x.c \
			ft_buffer.c \
			main.c \

SRCS = $(addprefix $(DIR_S)/,$(SOURCES))

OBJS = $(addprefix $(DIR_O)/,$(SOURCES:.c=.o))

HEADERS = headers

LIBFT = Libft

NAME = libftprintf.a

CC = gcc

CFLAGS = -Wall -Werror -Wextra

all: $(NAME)

$(NAME): $(OBJS)
	make -C $(LIBFT)
	cp Libft/libft.a ./$(NAME)
	ar -rcs $(NAME) $(OBJS)

$(DIR_O)/%.o: $(DIR_S)/%.c
	mkdir -p objs
	${CC} ${CFLAGS} -I ${HEADERS} -o $@ -c $<

clean:
	rm -f $(OBJS)
	rm -rf $(DIR_O)
	make clean -C $(LIBFT)

fclean : clean
	rm -f $(NAME)
	make fclean -C $(LIBFT)

re: fclean all

.PHONY: clean all fclean re
