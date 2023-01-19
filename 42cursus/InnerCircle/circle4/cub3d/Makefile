NAME = cub3d

CC = cc
CFLAGS = -Wall -Wextra -Werror -g

INCLUDES_DIR = includes
LIBS_DIR = libs
SRCS_DIR = srcs
MLX_DIR	= mlx

# srcs directory
UTILS_DIR = utils
INIT_DIR = init
KEY_DIR = key

INIT_SRCS = init_game.c check_file.c init_element.c read_map.c
UTILS_SRCS = error_exit.c free.c print.c
KEY_SRCS = key_press.c

LIBFT_DIR = libs/libft
LIBFT = libft.a
LIBFT_LIB = -lft

SRCS = $(addprefix $(SRCS_DIR)/, main.c) \
	$(addprefix $(SRCS_DIR)/$(UTILS_DIR)/, $(UTILS_SRCS)) \
	$(addprefix $(SRCS_DIR)/$(INIT_DIR)/, $(INIT_SRCS)) \
	$(addprefix $(SRCS_DIR)/$(KEY_DIR)/, $(KEY_SRCS))

OBJS = $(SRCS:.c=.o)

all : $(NAME)

$(NAME) : $(OBJS)
	make -C $(LIBFT_DIR) bonus
	$(CC) $(CFLAGS) $(OBJS) -I $(INCLUDES_DIR) -L $(LIBFT_DIR) $(LIBFT_LIB) -lmlx -framework OpenGL -framework AppKit -o $@
	make -C $(MLX_DIR) all

%.o : %.c
	$(CC) $(CFLAGS) -I $(INCLUDES_DIR) -c $< -o $@

clean :
	rm -rf $(OBJS)
	make -C $(LIBFT_DIR) clean
	make -C $(MLX_DIR) clean

fclean : clean
	rm -rf $(NAME)
	make -C $(LIBFT_DIR) fclean
	rm -rf $(MLXDIR)/libmlx.a

re :
	make fclean
	make all

.PHONY = all clean fclean re
