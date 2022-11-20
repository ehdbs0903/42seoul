NAME = push_swap
BONUS_NAME = checker

CC = cc
CFLAGS = -Wall -Wextra -Werror

RM = rm -rf

SRCS = ft_push_swap.c ft_push_swap_utils.c free.c push.c swap.c rotate.c reverse_rotate.c parsing.c parsing_utils.c sort.c sort_over_five.c sort_under_five.c
BONUS_SRCS = checker.c $(addprefix get_next_line/, get_next_line.c get_next_line_utils.c) free.c push.c swap.c rotate.c reverse_rotate.c parsing.c parsing_utils.c ft_push_swap_utils.c sort.c sort_over_five.c sort_under_five.c

LIBFT = $(LIBFT_DIR)/libft.a
LIBFT_DIR = libft

OBJS = $(SRCS:.c=.o)
BONUS_OBJS = $(BONUS_SRCS:.c=.o)

all : $(NAME)

$(NAME) : $(OBJS) $(LIBFT)
	$(CC) $(CFLAGS) $(OBJS) -L $(LIBFT_DIR) -lft -o $(NAME)

$(LIBFT) :
	$(MAKE) -C $(LIBFT_DIR)

$(BONUS_NAME) : $(BONUS_OBJS)
	$(CC) $(CFLAGS) $(BONUS_OBJS) -L $(LIBFT_DIR) -lft -o $(BONUS_NAME)

%.o : %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	$(RM) $(OBJS)
	$(RM) $(BONUS_OBJS)
	$(MAKE) -C $(LIBFT_DIR) clean

fclean: clean
	$(RM) $(NAME)
	$(RM) $(BONUS_NAME)
	$(MAKE) -C $(LIBFT_DIR) fclean

bonus: all $(BONUS_NAME)



re : fclean all

.PHONY: all clean fclean re
