# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tboivin <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/04/08 02:09:24 by tboivin           #+#    #+#              #
#    Updated: 2017/04/08 02:09:27 by tboivin          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= lem-in

SRC		= main.c \
		  add_lists.c \
		  parse.c \
		  tool.c \
		  check.c \
		  path.c \
		  print.c \
		  tool2.c \
		  tool3.c \

OBJ		= $(addprefix srcs/,$(SRC:.c=.o))

INCLUDES = ./includes/lemin.h 

ALL_FLAGS = -Wall -Wextra -Werror
CFLAGS	=  $(ALL_FLAGS) -I./includes/ -I./libft/includes/

all: $(INCLUDES) makefile libft $(NAME)

libft:
	@make -C ./libft

$(NAME): libft $(OBJ) $(INCLUDES)
	@gcc $(OBJ) -o $(NAME)  -L./libft -lft

clean:
	@make clean -C ./libft
	@rm -rf $(OBJ)

fclean: clean
	@rm -rf $(NAME) $(OBJ)
	@make fclean -C ./libft

re: fclean all

.PHONY: clean fclean re libft all