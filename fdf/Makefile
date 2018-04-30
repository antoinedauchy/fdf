# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: adauchy <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/11/27 20:02:36 by adauchy           #+#    #+#              #
#    Updated: 2017/12/14 07:58:48 by adauchy          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC		=		gcc

RM		=		rm -f

NAME	=		fdf

CFLAGS	=	-Wextra -Wall -Werror

LIB		=	-lmlx -framework OpenGL -framework AppKit

SRCS	=	main.c							\
			calc_fdf/calc_point.c			\
			calc_fdf/get_dir.c				\
			calc_fdf/get_print_order.c		\
			calc_fdf/get_set_color.c		\
			calc_fdf/move_block_rgb.c		\
			calc_fdf/move_field.c			\
			calc_fdf/reset_moves.c			\
			calc_fdf/set_rgb.c				\
											\
			init/check_file.c				\
			init/get_map.c					\
			init/init_data.c				\
			init/init_ext_height.c			\
			init/init_mlx.c					\
											\
			mlx_fcts/key_hook.c				\
			mlx_fcts/loop_hook.c			\
			mlx_fcts/mouse_hook.c			\
			mlx_fcts/mouse_press_hook.c		\
			mlx_fcts/mouse_release_hook.c	\
											\
			print_fdf/print_colors.c		\
			print_fdf/print_env.c			\
			print_fdf/print_field.c			\
			print_fdf/print_hills.c			\
			print_fdf/print_rotation.c		\
			print_fdf/print_sep_panel.c		\
			print_fdf/print_set.c			\
			print_fdf/print_status.c		\
											\
			print_tools/print_line.c		\
			print_tools/print_polygone.c	\
			print_tools/print_square.c		\
			print_tools/put_pxl_img.c		\
											\
			tools/cursor_in_square.c		\
			tools/ft_abs.c					\
			tools/ft_strlen.c				\
			tools/ft_swap.c					\
			tools/get_nbr.c					\
			tools/get_next_line.c			\
			tools/put_err.c					\

OBJS	=	$(SRCS:.c=.o)

all		:	$(NAME)

$(NAME)	:	$(OBJS)
			$(CC) -o $(NAME) $(OBJS) $(CFLAGS) $(LIB)

clean	:
			$(RM) $(OBJS)

fclean	:	clean
			$(RM) $(NAME)

re		:	fclean all

.PHONY	:	all clean fclean re
