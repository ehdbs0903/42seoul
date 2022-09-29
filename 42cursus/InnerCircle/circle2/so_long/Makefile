NAME = so_long

CC = cc
CFLAGS = -Wall -Wextra -Werror

RM = rm -rf

MLX = mlx/libmlx.a
MLX_DIR = mlx

SRCS = ft_so_long.c
OBJS = ft_so_long.o
INC = ft_so_long.h

all: $(MLX) $(NAME)

$(NAME): $(OBJS) $(INC)
	$(CC) $(CFLAGS) $(MLX) -o $@ $(OBJS)

%.o : %.c
	$(CC) $(CFLAGS) -c $< -o $@

$(MLX):
	$(MAKE) -C $(MLX_DIR)

clean:
	$(RM) $(OBJS)
	$(MAKE) clean -C $(MLX_DIR)

fclean:
	$(MAKE) fclean -C $(MLX_DIR)
	$(RM) $(OBJS)
	$(RM) $(NAME)

re:
	make fclean
	make all

.PHONY: all celan fclean re
