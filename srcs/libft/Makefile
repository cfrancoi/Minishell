NAME	= libft.a
FLAGS	= -Wall -Wextra -Werror
CC		= gcc
SRC		+= mem/ft_memset.c
SRC		+= mem/ft_bzero.c
SRC		+= mem/ft_memcpy.c
SRC		+= mem/ft_memccpy.c
SRC		+= mem/ft_memmove.c
SRC		+= mem/ft_memchr.c
SRC		+= mem/ft_memcmp.c
SRC		+= check/ft_isalpha.c
SRC		+= check/ft_isdigit.c
SRC		+= check/ft_isalnum.c
SRC		+= check/ft_isascii.c
SRC		+= check/ft_isprint.c
SRC		+= str/ft_array_len.c
SRC		+= str/ft_strlen.c
SRC		+= str/ft_toupper.c
SRC		+= str/ft_tolower.c
SRC		+= str/ft_strchr.c
SRC		+= str/ft_strrchr.c
SRC		+= str/ft_strncmp.c
SRC		+= str/ft_strlcpy.c
SRC		+= str/ft_strlcat.c
SRC		+= str/ft_strnstr.c
SRC		+= str/ft_atoi.c
SRC		+= str/ft_atol.c
SRC		+= str/ft_strcpy_a.c
SRC		+= alloc/ft_calloc.c
SRC		+= alloc/ft_strdup.c
SRC		+= alloc/ft_substr.c
SRC		+= alloc/ft_strjoinf.c
SRC		+= alloc/ft_itoa_base.c
SRC		+= alloc/ft_split.c
SRC		+= alloc/ft_array_free.c
SRC		+= write/ft_putchar_fd.c
SRC		+= write/ft_putstr_fd.c
SRC		+= write/ft_putendl_fd.c
SRC		+= write/ft_putnbr_fd.c
SRC		+= write/ft_puttabstr_fd.c
SRC		+= gnl/get_next_line.c
SRC		+= gnl/get_next_line_utils.c

INC = libft.h gnl/get_next_line.h
OBJS_DIR = ./objs/
OBJS = $(addprefix $(OBJS_DIR),$(notdir $(SRC:%.c=%.o)))

all: $(NAME)

$(OBJS_DIR)%.o : mem/%.c $(INC)
	$(CC) $(FLAGS) -c $< -o $@

$(OBJS_DIR)%.o : str/%.c $(INC)
	$(CC) $(FLAGS) -c $< -o $@

$(OBJS_DIR)%.o : alloc/%.c $(INC)
	$(CC) $(FLAGS) -c $< -o $@

$(OBJS_DIR)%.o : check/%.c $(INC)
	$(CC) $(FLAGS) -c $< -o $@

$(OBJS_DIR)%.o : write/%.c $(INC)
	$(CC) $(FLAGS) -c $< -o $@

$(OBJS_DIR)%.o : gnl/%.c $(INC)
	$(CC) $(FLAGS) -c $< -o $@

$(NAME): $(OBJS) $(INC)
	ar rc $(NAME) $(OBJS) $(INC)

clean:
	rm -rf $(OBJS)
	rm -rf $(BONUS_OBJS)

fclean: clean
	rm -rf $(NAME)

re: fclean all

.PHONY : re fclean clean all