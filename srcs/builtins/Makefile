NAME		= builtins.a

SRCS		= $(addprefix $(ECHO_DIR), echo.c)
SRCS		+= $(addprefix $(ENV_DIR), env.c)
SRCS		+= $(addprefix $(EXPORT_DIR), export.c)
SRCS		+= $(addprefix $(EXPORT_DIR), add_to_lst.c)
SRCS		+= $(addprefix $(CD_DIR), cd.c)
SRCS		+= $(addprefix $(CD_DIR), msh_cd.c)
SRCS		+= $(addprefix $(PWD_DIR), pwd.c)
SRCS		+= $(addprefix $(UNSET_DIR), unset.c)

OBJS 		= $(SRCS:.c=.o)
CD_DIR		= ./cd/
ECHO_DIR	= ./echo/
ENV_DIR		= ./env/
EXPORT_DIR	= ./export/
PWD_DIR		= ./pwd/
UNSET_DIR	= ./unset/

CC = gcc
FLAGS = -Wall -Wextra -Werror

all: $(NAME)

%.o: %.c $(INC)
	$(CC) $(FLAGS) -c $< -o $@ -I ../include

$(NAME): $(OBJS) $(INC)
	ar rc $(NAME) $(OBJS) $(INC)

clean:
	rm -rf $(OBJS)
	rm -rf $(BONUS_OBJS)

fclean: clean
	rm -rf $(NAME)

re: fclean all

.PHONY:all clean fclean re
