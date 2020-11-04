NAME		= unset

SRCS		= unset.c

OBJ_DIR		= ./objects/
LIBFT_DIR	= ../../libft/
ENV_DIR		= ../../env/
INC_DIR		= ../../include/
LIBFT_A		= $(addprefix $(LIBFT_DIR), libft.a)
ENV_A		= $(addprefix $(ENV_DIR), env.a)
OBJ			= $(addprefix $(OBJ_DIR),$(SRCS:.c=.o))

CC			= gcc
CFLAGS		= -Wall -Werror -Wextra
RM			= rm -f
RM_DIR		= rm -rf

all:
	mkdir -p $(OBJ_DIR)
	$(MAKE) $(NAME) --no-print-directory

$(OBJ_DIR)%.o:$(MSH_DIR)%.c $(INC_DIR)*.h
	$(CC) -c $< -o $@

$(NAME):$(OBJ) $(INC_DIR) $(ENV_A) $(LIBFT_A)
	$(CC) -g $(OBJ) $(ENV_A) $(LIBFT_A) -o $(NAME)

clean:
	$(RM_DIR) $(OBJ_DIR)

fclean: clean
	$(RM) $(NAME)

re:fclean all

.PHONY:all clean fclean re