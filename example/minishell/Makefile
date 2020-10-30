NAME =Minishell.out
CC = gcc
CFLAGS = -Wall -Werror -Wextra
MAIN = main.c
ENV = env/env.a
LIBFT = ../Lib/libft.a
SRC =	get_cmd.c \
		try_line.c \
		rplc_env_cmd.c
		

OBJS = $(SRC:.c=.o)

%.o: %.c $(INC)
	$(CC) $(CFLAGS) -c $< -o $@

all : $(NAME)

$(NAME) : $(OBJS) FORCE
	 $(CC) $(CFLAGS) $(MAIN) $(OBJS) $(ENV) $(LIBFT) -o $(NAME)
FORCE:

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all
