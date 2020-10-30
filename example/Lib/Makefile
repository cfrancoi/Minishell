NAME = libft.a
FLAGS = -Wall -Wextra -Werror
CC = gcc
SRC =	mem/ft_memset.c \
		mem/ft_bzero.c \
		mem/ft_memcpy.c \
		mem/ft_memccpy.c \
		mem/ft_memmove.c \
		mem/ft_memchr.c \
		mem/ft_memcmp.c \
		\
		check/ft_isalpha.c \
		check/ft_isdigit.c \
		check/ft_isalnum.c \
		check/ft_isascii.c \
		check/ft_isprint.c \
		\
		str/ft_strlen.c \
		str/ft_toupper.c \
		str/ft_tolower.c \
		str/ft_strchr.c \
		str/ft_strrchr.c \
		str/ft_strncmp.c \
		str/ft_strlcpy.c \
		str/ft_strlcat.c \
		str/ft_strnstr.c \
		str/ft_atoi.c \
		str/ft_atol.c \
		str/ft_strcpy_a.c \
		\
		alloc/ft_calloc.c \
		alloc/ft_strdup.c \
		alloc/ft_substr.c \
		alloc/ft_strjoinf.c \
		alloc/ft_itoa_base.c \
		alloc/ft_split.c \
		alloc/ft_array_free.c \
		\
		write/ft_putchar_fd.c \
		write/ft_putstr_fd.c \
		write/ft_putendl_fd.c \
		write/ft_putnbr_fd.c \
		write/ft_puttabstr_fd.c \
		\
		gnl/get_next_line.c \
		gnl/get_next_line_utils.c
		\
INC = libft.h gnl/get_next_line.h
OBJS = $(SRC:.c=.o)

all: $(NAME)

%.o: %.c $(INC)
	$(CC) $(FLAGS) -c $< -o $@

$(NAME): $(OBJS) $(INC)
	ar rcs $(NAME) $(OBJS) $(INC)

clean:
	rm -rf $(OBJS)
	rm -rf $(BONUS_OBJS)

fclean: clean
	rm -rf $(NAME)

re: fclean all
