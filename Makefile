# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sehhong <sehhong@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/06/02 09:21:25 by sehhong           #+#    #+#              #
#    Updated: 2021/06/02 12:14:44 by sehhong          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

LIBFT_DIR = libft
LIBFT_LIB = libft.a

SRCS = arg_extracter.c format_checker.c format_maker.c \
		ft_printf_utils.c ft_printf.c 
OBJS = $(SRCS:.c=.o)

CC = gcc
CFLAGS = -Wall -Werror -Wextra
AR = ar rcs
RM = rm -f

all: $(NAME)

%.o: %.c 
	$(CC) $(CFLAGS) -c $< -o $@

$(NAME) : $(OBJS)
	make all -C $(LIBFT_DIR)
	cp $(LIBFT_DIR)/$(LIBFT_LIB) $(NAME)
	$(AR) $(NAME) $(OBJS)

bonus: $(NAME)

clean: 
	$(RM) $(OBJS)
	make clean -C $(LIBFT_DIR)

fclean:	clean
	$(RM) $(NAME)
	make fclean -C $(LIBFT_DIR)

re: fclean all

.PHONY: all bonus clean fclean re 