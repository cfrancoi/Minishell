NAME		= env.a

SRCS		= env.c

OBJ_DIR		= ./objects/
INC_DIR		= ../../include/
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

$(NAME):$(OBJ) $(INC_DIR) 
	ar rc $(NAME) $(OBJ)

clean:
	$(RM_DIR) $(OBJ_DIR)

fclean: clean
	$(RM) $(NAME)

re:fclean all

.PHONY:all clean fclean re
