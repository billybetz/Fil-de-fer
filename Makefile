# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: bbetz <marvin@42.fr>                       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/03/14 19:46:58 by bbetz             #+#    #+#              #
#    Updated: 2016/05/30 21:33:16 by bbetz            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fdf

CC = gcc

CFLAG = -Wall -Werror -Wextra

EXTRA_FLAGS = -lmlx -framework OpenGL -framework AppKit

INC = 	./include/						\
		

SRC =	./sources/main.c 				\
		./sources/divers.c 				\
		./sources/draw_map.c 			\
		./sources/drawline.c 			\
		./sources/drawline_beeline.c 	\
		./sources/drawline_cadran.c 	\
		./sources/drawline_cadran2.c 	\
		./sources/events.c 				\
		./sources/get_points.c 			\
		./sources/rotations.c 			\
		./sources/translations.c 		\
		./sources/zooms.c 				\

LIB = libft/libft.a

OBJ = $(SRC:.c=.o)

all: $(NAME)

$(NAME):
	@make -C libft
	@$(CC)  -I $(INC) $(LIB) $(CFLAG) $(EXTRA_FLAGS) $(SRC) -o $(NAME)

clean:
	@make clean -C libft
	@/bin/rm -f $(OBJ)

fclean: clean
	@make fclean -C libft
	@/bin/rm -f $(NAME)

re: fclean all
