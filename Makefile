# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aouichou <aouichou@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/06/21 17:47:51 by aouichou          #+#    #+#              #
#    Updated: 2022/07/03 20:05:39 by aouichou         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= fdf

SRC_D		= srcs/
OBJ_D		= objs/
INC_D		= includes/
LIBFT_D		= libs/libft/
LIBMLX_D	= libs/mlx/

SRC		= main.c	\
		tools.c						\
		tools_2.c					\
		free.c						\
		exit.c						\
		parsing.c					\
		key_hooks.c					\
		mouse_hooks.c				\
		draw.c						\
		colors.c					\
		ft_mlx.c					\
		inits.c						\
		menu.c						\
		move.c						\
		projections.c				\
		rotations.c					\
		apply_colors.c				\
		apply_topography_colors.c	\

OBJ		= $(addprefix $(OBJ_D), $(SRC:.c=.o))
FLAGS	= -g -Wall -Werror -Wextra
LIBS	= -L /usr/local/lib -L libs/libft -lft -L libs/mlx -lmlx -lmlx_Linux
LIBS	+= -lpthread -lXext -lX11 -lm

INCS	= -I /usr/X11/$(INC_D) -I $(INC_D) -I minilibx-linux/ -I libft/includes -I ft_3d/ -I parser/ -I ft_btree/

all: $(LIBFT_D) $(LIBMLX_D) $(OBJ_D) $(NAME)

$(OBJ_D):
	@mkdir -p $@

$(NAME): $(OBJ)
	sh resolution.sh
	@make -C $(LIBFT_D)
	@make -C $(LIBMLX_D)
	gcc -o $@ $^ $(LIBS)

$(OBJ_D)%.o: $(SRC_D)%.c
	gcc $(FLAGS) -o $@ -c $< $(INCS)

clean:
	@make -C $(LIBFT_D) clean
	@make -C $(LIBMLX_D) clean
	rm -rf $(OBJ_D)
	rm -rf	res.txt

fclean: clean
	@make -C $(LIBFT_D) fclean
	@make -C $(LIBMLX_D) clean
	rm -f $(NAME)

re: fclean all

.PHONY: clean fclean re all
