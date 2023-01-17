
NAME = minishell

CC = cc
CFLAGS = -Wall -Wextra -Werror -g

INCLUDES_DIR = includes
LIBS_DIR = libs
SRCS_DIR = srcs

# srcs directory
LEXER_DIR = lexer
PARSER_DIR = parser
BUILTIN_DIR = builtin
EXEC_DIR = execute
ENV_DIR = env
UTILS_DIR = utils

LEXER_SRCS = lexer.c labeling.c check_odd_quote.c lexer_error.c
PARSER_SRCS = check.c delete_blank.c merge_string.c parser_token.c remove_quote.c replace_env.c sort_redirection.c parsing.c parser_error.c make_token.c
BUILTIN_SRCS = env.c export.c unset.c echo.c cd.c exit.c pwd.c
EXEC_SRCS = exec_builtin.c exec_cmd.c exec_pipe.c redir.c heredoc.c
ENV_SRCS = init_env.c utils.c
UTILS_SRCS = signal.c error.c read.c

# readline
LDFLAGS = -L/goinfre/$(USER)/.brew/opt/readline/lib
CPPFLAGS = -I/goinfre/$(USER)/.brew/opt/readline/include
READ_LIB = -lreadline

LIBFT_DIR = libs/libft
LIBFT = libft.a
LIBFT_LIB = -lft

SRCS = $(addprefix $(SRCS_DIR)/, main.c) \
	$(addprefix $(SRCS_DIR)/$(LEXER_DIR)/, $(LEXER_SRCS)) \
	$(addprefix $(SRCS_DIR)/$(PARSER_DIR)/, $(PARSER_SRCS)) \
	$(addprefix $(SRCS_DIR)/$(BUILTIN_DIR)/, $(BUILTIN_SRCS)) \
	$(addprefix $(SRCS_DIR)/$(EXEC_DIR)/, $(EXEC_SRCS)) \
	$(addprefix $(SRCS_DIR)/$(ENV_DIR)/, $(ENV_SRCS)) \
	$(addprefix $(SRCS_DIR)/$(UTILS_DIR)/, $(UTILS_SRCS))

OBJS = $(SRCS:.c=.o)

all : $(NAME)

$(NAME) : $(OBJS)
	make -C $(LIBFT_DIR) bonus
	$(CC) $(CFLAGS) $(OBJS) -I $(INCLUDES_DIR) $(READ_LIB) $(LDFLAGS) $(CPPFLAGS) -L $(LIBFT_DIR) $(LIBFT_LIB) -o $@
	
%.o : %.c
	$(CC) $(CFLAGS) -I $(INCLUDES_DIR) $(CPPFLAGS) -c $< -o $@

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
