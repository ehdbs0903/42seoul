NAME = so_long

CC = cc
CFLAGS = -Wall -Wextra -Werror

RM = rm -rf

MLX = mlx/libmlx.a
MLX_DIR = mlx

LIBFTPRINTF = ft_printf/libftprintf.a
LIBFTPRINTF_DIR = ft_printf

SRC = ft_so_long.c ft_so_long_utils.c $(addprefix get_next_line/, get_next_line.c get_next_line_utils.c)
SOBJ = $(SRC:.c=.o)

SRCS = img_map.c key_action.c
OBJS = $(SRCS:.c=.o)

BONUS_SRCS = img_map_bonus.c key_action_bonus.c
BONUS_OBJS = $(BONUS_SRCS:.c=.o)

INC = ft_so_long.h

ifdef WITH_BONUS
	OBJ = $(SOBJ) $(BONUS_OBJS)
else
	OBJ = $(SOBJ) $(OBJS)
endif

all: $(MLX) $(LIBFTPRINTF) $(NAME)

bonus:
	make WITH_BONUS=1 all

$(NAME): $(OBJ) $(INC)
	$(CC) $(OBJ) $(LIBFTPRINTF) -Lmlx -lmlx -framework OpenGL -framework AppKit -o $@

%.o : %.c
	$(CC) $(CFLAGS) -Imlx  -c $< -o $@

$(MLX):
	$(MAKE) -C $(MLX_DIR)

$(LIBFTPRINTF):
	$(MAKE) -C $(LIBFTPRINTF_DIR)

clean:
	$(RM) $(SOBJ) $(OBJS) $(BONUS_OBJS)
	$(MAKE) clean -C $(MLX_DIR)
	$(MAKE) clean -C $(LIBFTPRINTF_DIR)

fclean:
	make clean
	$(RM) $(NAME)

re:
	make fclean
	make all
	make bonus

.PHONY: all celan fclean re
