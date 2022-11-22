SRC_FILE = philosophers.c ../src/ft_putstr_fd.c ../src/ft_putchar_fd.c ../src/ft_isdigit.c ../src/ft_atoi.c \
	philo_init.c utils.c

OBJ_FILE = $(SRC_FILE:.c=.o)

NAME = philo

CC = gcc

RED = \033[0;31m

RESET = \033[0m

CYAN = \033[0;36m

YELLOW = \033[0;33m

CFLAGS = -Wall -Werror -Wextra

all : $(NAME) philosophers.h

%.o:%.c
	@echo "$(CYAN)                          <----------- COMPILING $< ----------->$(RESET)"
	@$(CC) $(CFLAGS) -c $< -o $@

$(NAME) : $(OBJ_FILE)
	@$(CC) $(CFLAGS) $(OBJ_FILE)  -lpthread -o $(NAME)
clean :
	@echo "$(YELLOW)                        <----------- REMOVING OBJECT FILES ----------->$(RESET)"
	@rm -rf $(OBJ_FILE)
fclean : clean
	@echo "$(YELLOW)                        <----------- REMOVING ALL ----------->$(RESET)"
	@rm -rf $(NAME) $(BONUS)
re : fclean all
.PHONY : clean fclean re
