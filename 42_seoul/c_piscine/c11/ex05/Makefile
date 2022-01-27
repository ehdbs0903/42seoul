TARGET = do-op
CC = gcc
CFLAG = -Wall -Wextra -Werror

RM = rm -f

LDFLAGS = -lc

SRCS = calculator.c ft_putnbr.c main.c operate.c

OBJS = $(SRCS:.c=.o)

all : $(TARGET)

$(TARGET) : $(OBJS)
	$(CC) $(LDFLAGS) -o $@ $^

.c.o:
	$(CC) $(CFLAG) -c -o $@ $<

clean:
	$(RM) $(OBJS)

fclean:
	make clean
	$(RM) $(TARGET)

re:
	make fclean
	make all
