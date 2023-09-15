# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: beroux <beroux@student.42lyon.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/08/15 03:36:50 by beroux            #+#    #+#              #
#    Updated: 2023/09/13 18:00:16 by beroux           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME =	cub3D

SRCS =	main.c hooks.c
INCS =	incs/cub.h

include	srcs/render/sources.mk	srcs/img/sources.mk	srcs/player/sources.mk	srcs/drawing/drawing.mk	srcs/parsing/sources.mk

SRCS :=	$(addprefix srcs/, $(SRCS))

OBJS =	$(SRCS:.c=.o)

CFLAGS =	-Wall -Wextra -Werror -O2 #-fsanitize=address

MLX =		../minilibx-linux/libmlx.a
LIBFT =		../libft/libft.a

ifeq ($(shell command -v xrandr 2> /dev/null),)
    WIN_WIDTH = 800
    WIN_HEIGHT = 600
else
    WIN_WIDTH := ${shell xrandr | grep '*' | awk '{print $$1}' | cut -d 'x' -f1 | head -n 1}
    WIN_HEIGHT := ${shell xrandr | grep '*' | awk '{print $$1}' | cut -d 'x' -f2 | head -n 1}
endif

%.o:		%.c $(INCS)
			$(CC) $(CFLAGS) -DWIN_WIDTH=${WIN_WIDTH} -DWIN_HEIGHT=${WIN_HEIGHT} -c $< -o $@ -Iincs -I../minilibx-linux -I../libft/includes

all:		$(NAME)
			@echo "win width:" ${WIN_WIDTH}
			@echo "win height:" ${WIN_HEIGHT}

$(NAME):	$(OBJS) $(MLX) $(LIBFT)
			$(CC) $(CFLAGS) -o $@ $^ -Iincs -I../minilibx-linux -lXext -I../libft/includes -lX11 -lm -lz

clean:
			$(RM) $(OBJS)
			$(MAKE) -C ../libft clean

fclean:		clean
			$(RM) $(NAME)
			$(MAKE) -C ../minilibx-linux clean
			$(MAKE) -C ../libft fclean

re:			fclean
			$(MAKE) all

$(MLX):
			$(MAKE) -C ../minilibx-linux

$(LIBFT):
			$(MAKE) -C ../libft

.PHONY:		all clean fclean re
