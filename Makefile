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

SRC		= srcs/main.c \
		  srcs/add_lists.c \
		  srcs/parse.c \
		  srcs/tool.c \
		  srcs/check.c \
		  srcs/path.c \
		  srcs/print.c \
		  srcs/tool2.c \
		  srcs/tool3.c \

OBJ		= $(SRC:.c=.o)

CFLAGS	= -Wall -Wextra -Werror -g -I includes/

$(NAME): $(OBJ)
	@make -C libft
	@gcc $(OBJ) -o $(NAME) -L libft/ -lft -I libft/includes/

all: $(NAME)

clean:
	@make -C libft/ clean
	@rm -rf $(OBJ)

fclean: clean
	@rm -rf $(NAME) $(OBJ)
	@make -C libft/ fclean

re: fclean $(NAME)
