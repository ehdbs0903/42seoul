NAME = a.out

CC = c++
FLAGS = -Wall -Wextra -Werror -std=c++98 -pedantic

SRCS = main.cpp Amateria.cpp Ice.cpp Cure.cpp Character.cpp MateriaSource.cpp

OBJS_DIR = objs
OBJS = $(addprefix $(OBJS_DIR)/, $(SRCS:.cpp=.o))

$(NAME) : $(OBJS)
	@$(CC) $(FLAGS) -o $(NAME) $(OBJS)

$(OBJS_DIR)/%.o : %.cpp
	@mkdir -p $(OBJS_DIR)
	@$(CC) $(FLAGS) -c $^ -o $@

all : $(NAME)

clean :
	@rm -rf $(OBJS_DIR)

fclean :
	@make clean
	@rm -rf $(NAME)

re : fclean all