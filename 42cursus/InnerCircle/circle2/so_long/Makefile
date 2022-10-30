NAME = so_long

CC = cc
CFLAGS = -Wall -Wextra -Werror

RM = rm -rf

MLX = mlx/libmlx.a
MLX_DIR = mlx

LIBFTPRINTF = ft_printf/libftprintf.a
LIBFTPRINTF_DIR = ft_printf

SRCS = ft_so_long.c ft_so_long_utils.c img_map.c key_action.c $(addprefix get_next_line/, get_next_line.c get_next_line_utils.c)
OBJS = ft_so_long.o ft_so_long_utils.o img_map.o key_action.o $(addprefix get_next_line/, get_next_line.o get_next_line_utils.o)
INC = ft_so_long.h

all: $(MLX) $(LIBFTPRINTF) $(NAME)

$(NAME): $(OBJS) $(INC)
	$(CC) $(OBJS) $(LIBFTPRINTF) -Lmlx -lmlx -framework OpenGL -framework AppKit -o $@

%.o : %.c
	$(CC) $(CFLAGS) -Imlx  -c $< -o $@

$(MLX):
	$(MAKE) -C $(MLX_DIR)

$(LIBFTPRINTF):
	$(MAKE) -C $(LIBFTPRINTF_DIR)

clean:
	$(RM) $(OBJS)
	$(MAKE) clean -C $(MLX_DIR)
	$(MAKE) clean -C $(LIBFTPRINTF_DIR)

fclean:
	$(MAKE) fclean -C $(MLX_DIR)
	$(MAKE) fclean -C $(LIBFTPRINTF_DIR)
	$(RM) $(OBJS)
	$(RM) $(NAME)

re:
	make fclean
	make all

.PHONY: all celan fclean re
