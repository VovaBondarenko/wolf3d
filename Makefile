# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vbondare <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/10/30 02:22:52 by vbondare          #+#    #+#              #
#    Updated: 2017/10/30 02:24:45 by vbondare         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = wolf3d

FLAGS = -Wall -Wextra -Werror

LIB = libft/libft.a

SRC = color.c extra_func.c image.c init.c main.c map.c menu.c paint.c player.c texture.c \
		static_map1.c static_map2.c

.PHONY: all re clean

all:
	@make -C libft/
	@cc -o $(NAME) $(FLAGS) *.c $(LIB) -lmlx -framework OpenGL -framework AppKit

clean:
	@/bin/rm -f $(NAME)

re:	clean all
