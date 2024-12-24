NAME = libftprintf.a

SRCS = ft_format.c ft_putnbr_fd.c ft_put_unsigned_fd.c \
	   ft_putchar_fd.c ft_put_ptr.c \
	   ft_put_hex_fd.c ft_putstr_fd.c ft_printf.c ft_strlen.c

OBJS = $(SRCS:.c=.o)

CC = gcc
CFLAGS = -Wall -Werror -Wextra -I.

all: $(NAME)

$(NAME): $(OBJS)
	ar rcs $(NAME) $(OBJS)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all