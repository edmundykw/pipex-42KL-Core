# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ekeen-wy <ekeen-wy@student.42kl.edu.my>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/05/15 14:20:16 by ekeen-wy          #+#    #+#              #
#    Updated: 2022/05/19 15:27:49 by ekeen-wy         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME := pipex

CC := gcc

CFLAGS := -Wall -Wextra -Werror 

OUTFLAG := -o

DEPS := ft_pipex.h

SRC := ft_utils_pipex.c main.c ft_stdlib_1.c ft_stdlib_2.c

OBJ := $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) $(OUTFLAG) $@

%.o: %.c 
	$(CC) $(CFLAGS) -c $<

fclean: clean
	rm -f $(NAME)
	
clean:
	rm -f $(OBJ)

re: fclean all

.PHONY: all clean fclean re