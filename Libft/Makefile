# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: bod <marvin@42.fr>                         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/10/06 16:16:32 by bod               #+#    #+#              #
#    Updated: 2020/02/09 16:27:27 by thbeaumo         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a


SRC = ft_atoi.c ft_bzero.c ft_calloc.c ft_itoa.c ft_isalpha.c ft_isdigit.c \
	  ft_isprint.c ft_isalnum.c ft_memcmp.c ft_memcpy.c ft_memmove.c \
	  ft_memset.c ft_putstr_fd.c  ft_putchar_fd.c ft_putendl_fd.c\
	  ft_strchr.c ft_strdup.c ft_strjoin.c ft_strlcat.c ft_strlcpy.c \
	  ft_strnstr.c ft_isascii.c  ft_strchr.c ft_strlen.c ft_substr.c \
	  ft_strrchr.c ft_strtrim.c ft_tolower.c ft_split.c \
	  ft_strncmp.c ft_toupper.c  ft_putnbr_fd.c ft_strmapi.c ft_memchr.c\
	  ft_memccpy.c ft_putchar.c ft_putstr.c ft_maj_alpha.c

OBJ = $(SRC:.c=.o)

CC = gcc

FLAG = -Wall -Wextra -Werror
 
all: $(NAME)

$(NAME): $(OBJ)
	ar rcs $(NAME) $^

%.o: %.c
	$(CC) -o $@ -c $< $(FLAG)

clean:
	rm -rf $(OBJ)

fclean: clean
	rm -rf $(NAME)

re: clean all


.PHONY: clean all re fclean
