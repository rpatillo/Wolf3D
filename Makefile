#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rpatillo <rpatillo@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2015/06/08 11:42:29 by rpatillo          #+#    #+#              #
#    Updated: 2015/06/12 17:04:11 by rpatillo         ###   ########.fr        #
#                                                                              #
#******************************************************************************#


NAME = wolf3d

FLAGS = -Wall -Wextra -Werror

CC = gcc
LIB = -framework AppKit -framework OpenGL -L minilibx_macos/ -lmlx -L libft -lft
COMP = -I minilibx_macos/ -I libft/ -I inc/

FILE_SRC = ./src/main.c \
		./src/parse.c \
		./src/draw.c \
		./src/calc.c \
		./src/calc2.c \
		./src/keyhook.c \
		./src/keyhook2.c \
		./src/error.c \

FILE_OBJ = $(FILE_SRC:.c=.o)

all: $(NAME)

$(NAME): $(FILE_OBJ)
		make -C ./libft
		make -C ./minilibx_macos
		$(CC) -o $(NAME) $(FILE_OBJ) $(FLAGS) $(COMP) $(LIB)
		@clear
		@echo	""
		@echo	Wolfd3d by rpatillo
		@echo	""
		@echo "		Flags :"$(FLAGS)
		@echo	""
		@echo "		Maps are located in maps dir"

clean:
		make -C ./libft/ clean
		make -C ./minilibx_macos/ clean
		rm -Rfv $(FILE_OBJ)
		@clear

fclean: clean
		make -C libft/ fclean
		make -C minilibx_macos/ clean
		rm -Rfv $(NAME) $(FILE_OBJ)
		@clear

re: fclean all

.PHONY:	all clean fclean re