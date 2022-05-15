# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ekeen-wy <ekeen-wy@student.42kl.edu.my>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/05/15 14:20:16 by ekeen-wy          #+#    #+#              #
#    Updated: 2022/05/15 15:27:43 by ekeen-wy         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME := pipex.a

CC := gcc

CFLAGS := -Wall -Wextra -Werror

DEPS := ft_pipex.h

BDEPS := ft_pipex_bonus.h

PRINTF := ft_printf_mod/libftprintf.a

PRINTFOBJ := ft_printf_mod/*.o

SRC := ft_utils_pipex.c

BSRC := ft_utils_pipex_bonus.c

OBJ := $(SRC:.c=.o)

BOBJ := $(BSRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJ) 
	ar csr $(NAME) $? $(PRINTFOBJ)

$(OBJ): $(PRINTF) $(DEPS) $?

$(PRINTF):
	$(MAKE) -C ft_printf_mod

fclean: clean 
	rm -f $(NAME)

clean:
	$(MAKE) fclean -C ft_printf_mod
	rm -f $(OBJ)

re: fclean all

.PHONY: all clean fclean re