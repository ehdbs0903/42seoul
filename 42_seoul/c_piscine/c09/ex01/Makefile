TARGET = libft.a
CC = gcc
CFLAG = -Wall -Wextra -Werror

RM = rm -f

AR = ar
ARFLAGS = rcs

INC = includes

SRCS = srcs/ft_putchar.c srcs/ft_swap.c srcs/ft_putstr.c srcs/ft_strlen.c srcs/ft_strcmp.c

OBJS = $(SRCS:.c=.o)

all : $(TARGET)

$(TARGET) : $(OBJS)
	$(AR) $(ARFLAGS) $@ $^

.c.o:
	$(CC) -I $(INC) $(CFLAG) -c -o $@ $<

clean:
	$(RM) $(OBJS)

fclean:
	make clean
	$(RM) $(TARGET)

re:
	make fclean
	make all
