# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: beroux <beroux@student.42lyon.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/08/15 03:36:50 by beroux            #+#    #+#              #
#    Updated: 2023/09/01 13:15:50 by beroux           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME =	cub3D

SRCS =	main.c hooks.c
INCS =	incs/cub.h incs/defines.h

include	srcs/render/sources.mk
include srcs/img/sources.mk
include srcs/player/sources.mk
include	srcs/drawing/drawing.mk

SRCS :=	$(addprefix srcs/, $(SRCS))

OBJS =	$(SRCS:.c=.o)

CFLAGS =	-Wall -Wextra -Werror -g3 -fsanitize=address

MLX =		minilibx-linux/libmlx.a
LIBFT =		libft/libft.a

%.o:		%.c $(INCS)
			$(CC) $(CFLAGS) -c $< -o $@ -Iincs -Iminilibx-linux -Ilibft/includes

all:		$(NAME)

$(NAME):	$(OBJS) $(MLX) $(LIBFT)
			$(CC) $(CFLAGS) -o $@ $^ -Iincs -Iminilibx-linux -lXext -Ilibft/includes -lX11 -lm -lz

clean:
			$(RM) $(OBJS)

fclean:		clean
			$(RM) $(NAME)
			$(MAKE) -C minilibx-linux clean

re:			fclean
			$(MAKE) all

$(MLX):
			$(MAKE) -C minilibx-linux

$(LIBFT):
			$(MAKE) -C libft

.PHONY:		all clean fclean re