# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: beroux <beroux@student.42lyon.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/08/15 03:36:50 by beroux            #+#    #+#              #
#    Updated: 2023/10/04 16:48:37 by gd-harco         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


BASE_INCLUDED = libft/includes minilibx-linux
IS_BONUS =	1

ifeq ($(IS_BONUS), 1)
	NAME 		=	cub3D_bonus
	SRCS 		=	main_bonus.c hooks_bonus.c mouse_hooks_bonus.c minimap_bonus.c init_angles_bonus.c
	INCS_DIR	=	$(BASE_INCLUDED) bonus/incs
	INCS_FLAGS	=	$(addprefix -I, $(INCS_DIR))
	INCS 		=	bonus/incs/cub_bonus.h
	include	bonus/srcs/render/sources.mk	bonus/srcs/img/sources.mk	bonus/srcs/player/sources.mk	bonus/srcs/drawing/drawing.mk	bonus/srcs/parsing/sources.mk bonus/srcs/gamepad/sources.mk bonus/srcs/sprites/sources.mk
	SRCS 		:=	$(addprefix bonus/srcs/, $(SRCS))
	OBJS 		=	$(SRCS:.c=.o)
else
	NAME		=	cub3D
	SRCS		=	main.c hooks.c
	INCS_DIR	=	$(BASE_INCLUDED) incs
	INCS_FLAGS	=	$(addprefix -I, $(INCS_DIR))
	INCS		=	incs/cub.h
	include	srcs/render/sources.mk	srcs/img/sources.mk	srcs/player/sources.mk	srcs/drawing/drawing.mk	srcs/parsing/sources.mk
	SRCS		:=	$(addprefix srcs/, $(SRCS))
	OBJS		=	$(SRCS:.c=.o)
endif

LIBS = -lXext -lX11 -lm -lz

CFLAGS =	-Wall -Wextra -Werror #-O2 #-g3 -fsanitize=address

MLX =		minilibx-linux/libmlx.a
LIBFT =		libft/libft.a

ifeq ($(shell command -v xrandr 2> /dev/null),)
    WIN_WIDTH = 600
    WIN_HEIGHT = 600
else
    WIN_HEIGHT := ${shell xrandr | grep '*' | awk '{print $$1}' | cut -d 'x' -f2 | head -n 1}
    WIN_WIDTH := ${WIN_HEIGHT}
endif

%.o:		%.c
			$(CC) $(CFLAGS) -DWIN_WIDTH=${WIN_WIDTH} -DWIN_HEIGHT=${WIN_HEIGHT} -c $< -o $@ $(INCS_FLAGS)
all:		$(NAME)
			@echo "win width:" ${WIN_WIDTH}
			@echo "win height:" ${WIN_HEIGHT}

$(NAME):	$(OBJS) $(MLX) $(LIBFT)
			$(CC) $(CFLAGS) -o $@ $^ -I$(INCS_FLAGS) $(LIBS)

clean:
			$(RM) $(OBJS)
			@if [ $(IS_BONUS) -eq 0 ]; then $(MAKE) clean IS_BONUS=1 ; fi
			$(MAKE) -C libft clean

fclean:		clean
			$(RM) cub3D
			$(RM) cub3D_bonus
			$(MAKE) -C minilibx-linux clean
			$(MAKE) -C libft fclean

re:			fclean
			$(MAKE) all

re_bonus:	fclean
			$(MAKE) bonus

$(MLX):
			$(MAKE) -C minilibx-linux

$(LIBFT):
			$(MAKE) -C libft

bonus:
			$(MAKE) all IS_BONUS=1

.PHONY:		all clean fclean re bonus
