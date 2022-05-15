# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ekeen-wy <ekeen-wy@student.42kl.edu.my>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/05/15 14:20:16 by ekeen-wy          #+#    #+#              #
#    Updated: 2022/05/16 00:01:18 by ekeen-wy         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME := pipex

CC := gcc

CFLAGS := -Wall -Wextra -Werror

OUTFLAG := -o

DEPS := ft_pipex.h ft_printf_mod/ft_printf.h

BDEPS := ft_pipex_bonus.h ft_printf_mod/ft_printf.h

PRINTFSRC := ft_printf_mod/*.c

SRC := ft_utils_pipex.c main.c

BSRC := ft_utils_pipex_bonus.c main_bonus.c

OBJ := $(SRC:.c=.o)

BOBJ := $(SRC:.c=.o)

PRINTOBJ := $(PRINTFSRC:.c=.o)

all: $(NAME)

$(NAME): $(SRC) $(PRINTFSRC) $(DEPS)
	$(CC) $(CFLAGS) $(SRC) $(PRINTFSRC) $(OUTFLAG) $(NAME) 

fclean: clean 
	
clean:
	rm -f $(NAME)

re: fclean all

bonus: $(BSRC) $(PRINTFSRC) $(BDEPS)
	$(CC) $(CFLAGS) $(BSRC) $(PRINTFSRC) $(OUTFLAG) $(NAME) 

.PHONY: all clean fclean re bonus