NAME = unnecessary_violence
CC = c++
FLAGS = -Wall -Wextra -Werror -std=c++98 -pedantic

SRCS = main.cpp Weapon.cpp HumanA.cpp HumanB.cpp

OBJS_DIR = objs
OBJS = $(addprefix $(OBJS_DIR)/, $(SRCS:.cpp=.o))

$(NAME) : $(OBJS)
	@$(CC) $(FLAGS) -o $(NAME) $(OBJS)

$(OBJS_DIR)/%.o : %.cpp
	@mkdir $(OBJS_DIR) 2> /dev/null || true
	@$(CC) $(FLAGS) -c $^ -o $@

all : $(NAME)

clean :
	@rm -rf $(OBJS_DIR)

fclean :
	@make clean
	@rm -rf $(NAME)

re : fclean all
