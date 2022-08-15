TARGET = libftprintf.a
CC = gcc
CFLAG = -Wall -Wextra -Werror

RM = rm -f

AR = ar
ARFLAGS = rcs

SRCS = ft_printf.c ft_print_format.c ft_print_u.c ft_print_x.c ft_print_p.c

LIBFT_SRCS = $(addprefix libft/, ft_isalpha.c ft_isdigit.c ft_isalnum.c ft_isascii.c ft_isprint.c ft_strlen.c ft_memset.c ft_bzero.c ft_memcpy.c ft_memmove.c ft_strlcpy.c ft_strlcat.c ft_toupper.c ft_tolower.c ft_strchr.c ft_strrchr.c ft_strncmp.c ft_memchr.c ft_memcmp.c ft_strnstr.c ft_atoi.c ft_calloc.c ft_strdup.c ft_substr.c ft_strjoin.c ft_strtrim.c ft_split.c ft_itoa.c ft_strmapi.c ft_striteri.c ft_putchar_fd.c ft_putstr_fd.c ft_putendl_fd.c ft_putnbr_fd.c)

OBJS = $(SRCS:.c=.o)
LIBFT_OBJS = $(LIBFT_SRCS:.c=.o)

OBJ = $(OBJS) $(LIBFT_OBJS)

all : $(TARGET)

$(TARGET) : $(OBJ)
	$(AR) $(ARFLAGS) $@ $^

.c.o:
	$(CC) -I $(CFLAG) -c -o $@ $<

clean:
	$(RM) $(OBJ)

fclean:
	make clean 
	$(RM) $(TARGET)

re:
	make fclean
	make all

.PHONY: all clean fclean bonus
