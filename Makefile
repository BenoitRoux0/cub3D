# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: beroux <beroux@student.42lyon.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/08/15 03:36:50 by beroux            #+#    #+#              #
#    Updated: 2023/09/05 14:40:12 by beroux           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME =	cub3D

SRCS =	main.c hooks.c
INCS =	incs/cub.h

include	srcs/render/sources.mk	srcs/img/sources.mk	srcs/player/sources.mk	srcs/drawing/drawing.mk	srcs/parsing/sources.mk

SRCS :=	$(addprefix srcs/, $(SRCS))

OBJS =	$(SRCS:.c=.o)

CFLAGS =	-Wall -Wextra -Werror -g3 #-fsanitize=address

MLX =		minilibx-linux/libmlx.a
LIBFT =		libft/libft.a

%.o:		%.c $(INCS)
			$(CC) $(CFLAGS) -c $< -o $@ -Iincs -Iminilibx-linux -Ilibft/includes

all:		$(NAME)

$(NAME):	$(OBJS) $(MLX) $(LIBFT)
			$(CC) $(CFLAGS) -o $@ $^ -Iincs -Iminilibx-linux -lXext -Ilibft/includes -lX11 -lm -lz

clean:
			$(RM) $(OBJS)
			$(MAKE) -C libft clean

fclean:		clean
			$(RM) $(NAME)
			$(MAKE) -C minilibx-linux clean
			$(MAKE) -C libft fclean

re:			fclean
			$(MAKE) all

$(MLX):
			$(MAKE) -C minilibx-linux

$(LIBFT):
			$(MAKE) -C libft

.PHONY:		all clean fclean re
