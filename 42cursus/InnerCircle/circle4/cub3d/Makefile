# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sanghan <sanghan@student.42seoul.kr>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/01/20 14:51:48 by sanghan           #+#    #+#              #
#    Updated: 2023/02/02 20:17:07 by doykim           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = cub3d

CC = cc
CFLAGS = -Wall -Wextra -Werror -g

INCLUDES_DIR = includes
LIBS_DIR = ./libft
SRCS_DIR = srcs
MLX_DIR	= mlx

# srcs directory
UTILS_DIR = utils
INIT_DIR = init
KEY_DIR = key
LOOP_DIR = loop
RAY_DIR = raycast

INIT_SRCS = init_game.c check_file.c init_element.c init_rgb.c read_map.c
UTILS_SRCS = error_exit.c free.c print.c
KEY_SRCS = key_press.c
LOOP_SRCS = main_loop.c
RAY_SRCS = raycast.c

LIBFT = libft.a
LIBFT_LIB = -lft

SRCS = $(addprefix $(SRCS_DIR)/, main.c) \
	$(addprefix $(SRCS_DIR)/$(UTILS_DIR)/, $(UTILS_SRCS)) \
	$(addprefix $(SRCS_DIR)/$(INIT_DIR)/, $(INIT_SRCS)) \
	$(addprefix $(SRCS_DIR)/$(KEY_DIR)/, $(KEY_SRCS)) \
	$(addprefix $(SRCS_DIR)/$(LOOP_DIR)/, $(LOOP_SRCS)) \
	$(addprefix $(SRCS_DIR)/$(RAY_DIR)/, $(RAY_SRCS))

OBJS = $(SRCS:.c=.o)

all : $(NAME)

$(NAME) : $(OBJS)
	make -C $(LIBS_DIR) bonus
	$(CC) $(CFLAGS) $(OBJS) -I $(INCLUDES_DIR) -L $(LIBS_DIR) $(LIBFT_LIB) -lmlx -framework OpenGL -framework AppKit -o $@
	make -C $(MLX_DIR) all

%.o : %.c
	$(CC) $(CFLAGS) -I $(INCLUDES_DIR) -c $< -o $@

clean :
	rm -rf $(OBJS)
	make -C $(LIBS_DIR) clean
	make -C $(MLX_DIR) clean

fclean : clean
	rm -rf $(NAME)
	make -C $(LIBS_DIR) fclean
	rm -rf $(MLXDIR)/libmlx.a

re :
	make fclean
	make all

.PHONY = all clean fclean re
