NAME = env.a
CC = gcc
CFLAGS = -Wall -Werror -Wextra

SRC =	add_var.c \
		create_var.c \
		ls_var.c \
		get_var.c \
		get_str_var.c \
		print_var.c \
		env_utils.c \
		get_envp.c \
		lst_to_envp.c

OBJS = $(SRC:.c=.o)

%.o: %.c $(INC)
	$(CC) $(CFLAGS) -c $< -o $@

all : $(NAME)

$(NAME) : $(OBJS)
	ar rcs $(NAME) $(OBJS)
clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all
