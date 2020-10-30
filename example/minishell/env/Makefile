NAME =env.a
CC = gcc
CFLAGS = -Wall -Werror -Wextra

SRC =	add_var.c \
		create_var.c \
		ls_var.c \
		get_var.c \
		get_str_var.c \
		print_var.c \
		free_lst_var.c

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
