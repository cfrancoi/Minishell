NAME = env.a
CC = gcc
CFLAGS = -Wall -Werror -Wextra

SRCS			=	add_var.c \
				create_var.c \
				ls_var.c \
				get_var.c \
				get_str_var.c \
				print_var.c \
				env_utils.c \
				get_envp.c \
				lst_to_envp.c
OBJ_DIR		= ./objs/
OBJS		= $(addprefix $(OBJ_DIR),$(SRCS:.c=.o))
INC_DIR		= ../include/
INC			= $(addprefix $(INC_DIR), env.h)

$(OBJ_DIR)%.o: %.c $(INC)
	$(CC) $(CFLAGS) -c $< -o $@ -I $(INC_DIR)

all :
	mkdir -p $(OBJ_DIR)
	$(MAKE) $(NAME) --no-print-directory

$(NAME) : $(OBJS)
	ar rcs $(NAME) $(OBJS)

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)
	rm -rf $(OBJ_DIR)

re: fclean all

.PHONY: re fclean clean all
