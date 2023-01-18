NAME = cub3d

CC = cc
CFLAGS = -Wall -Wextra -Werror

INCLUDES_DIR = includes
LIBS_DIR = libs
SRCS_DIR = srcs

# srcs directory
MAP_DIR = map
UTILS_DIR = utils
GAME_DIR = game

MAP_SRCS = check_map.c
UTILS_SRCS = error_exit.c
GAME_SRCS = init_game.c

LIBFT_DIR = libs/libft
LIBFT = libft.a
LIBFT_LIB = -lft

SRCS = $(addprefix $(SRCS_DIR)/, main.c) \
	$(addprefix $(SRCS_DIR)/$(UTILS_DIR)/, $(UTILS_SRCS)) \
	$(addprefix $(SRCS_DIR)/$(MAP_DIR)/, $(MAP_SRCS)) \
	$(addprefix $(SRCS_DIR)/$(GAME_DIR)/, $(GAME_SRCS))

OBJS = $(SRCS:.c=.o)

all : $(NAME)

$(NAME) : $(OBJS)
	make -C $(LIBFT_DIR) bonus
	$(CC) $(CFLAGS) $(OBJS) -I $(INCLUDES_DIR) -L $(LIBFT_DIR) $(LIBFT_LIB) -lmlx -framework OpenGL -framework AppKit -o $@
	
%.o : %.c
	$(CC) $(CFLAGS) -I $(INCLUDES_DIR) -c $< -o $@

clean :
	rm -rf $(OBJS)
	make -C $(LIBFT_DIR) clean

fclean : clean
	rm -rf $(NAME)
	make -C $(LIBFT_DIR) fclean

re :
	make fclean
	make all

.PHONY = all clean fclean re
