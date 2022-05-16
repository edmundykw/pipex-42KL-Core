# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ekeen-wy <ekeen-wy@student.42kl.edu.my>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/05/15 14:20:16 by ekeen-wy          #+#    #+#              #
#    Updated: 2022/05/16 09:00:05 by ekeen-wy         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME := pipex

CC := gcc

CFLAGS := -Wall -Wextra -Werror

OUTFLAG := -o

DEPS := ft_pipex.h

BDEPS := ft_pipex_bonus.h 

SRC := ft_utils_pipex.c main.c

HSRC := ft_printf.c ft_print_xlow.c ft_print_xup.c ft_print_u.c ft_print_s.c \
		ft_print_p.c ft_print_d.c ft_print_c.c ft_utils_printf.c \
		ft_stdlib_1.c ft_stdlib_2.c

BSRC := ft_utils_pipex_bonus.c main_bonus.c

OBJ := $(SRC:.c=.o)

HOBJ := $(HSRC:.c=.o)

BOBJ := $(BSRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJ) $(HOBJ)
	$(CC) $(CFLAGS) $(SRC) $(HSRC) $(OUTFLAG) $(NAME) 

$(OBJ): $(SRC) $(DEPS) $(HOBJ)
	$(CC) $(CFLAGS) -c $(SRC)

$(HOBJ): $(HSRC) $(DEPS)
	$(CC) $(CFLAGS) -c $(HSRC)

fclean: clean
	rm -f $(NAME)
	
clean:
	rm -f $(OBJ) $(HOBJ) $(BOBJ)

re: fclean all

bonus: $(BOBJ) $(HOBJ) $(BDEPS)
	$(CC) $(CFLAGS) $(BSRC) $(HSRC) $(OUTFLAG) $(NAME) 

$(BOBJ): $(BSRC) $(BDEPS)
	$(CC) $(CFLAGS) -c $(BSRC)

.PHONY: all clean fclean re bonus