NAME	=
CLIENT	=	client
SERVER	=	server

LIBFTPRINTF	=	ft_printf/libftprintf.a
LIBFTPRINTF_DIR	=	ft_printf

SRC_C	=	ft_client.c
SRC_S	=	ft_server.c
OBJ_S	=	ft_server.o
OBJ_C	=	ft_client.o
INC		=	ft_minitalk.h

CC			=	gcc
CFLAG		=	-Wall -Wextra -Werror
RM			=	rm -rf

#Colors:
GREEN		=	\e[38;5;118m
YELLOW		=	\e[38;5;226m
RESET		=	\e[0m
_SUCCESS	=	[$(GREEN)SUCCESS$(RESET)]
_INFO		=	[$(YELLOW)INFO$(RESET)]

all: $(LIBFTPRINTF) $(CLIENT) $(SERVER)

$(SERVER): $(OBJ_S) $(INC)
	@ $(CC) $(CFLAGS) $(LIBFTPRINTF) -o $@ $(OBJ_S)

$(CLIENT): $(OBJ_C) $(INC)
	@ $(CC) $(CFLAGS) $(LIBFTPRINTF) -o $@ $(OBJ_C)

%.o: %.c
	@ $(CC) $(CFLAGS) -c $< -o $@

$(LIBFTPRINTF):
	@ $(MAKE) -C $(LIBFTPRINTF_DIR)

clean:
	@ $(MAKE) clean -C $(LIBFTPRINTF_DIR)
	@ $(RM) $(OBJ_C) $(OBJ_S)

fclean: clean
	@ $(MAKE) fclean -C $(LIBFTPRINTF_DIR)
	@ $(RM) $(CLIENT) $(SERVER)

re: 
	make fclean
	make all

.PHONY: all clean fclean re
