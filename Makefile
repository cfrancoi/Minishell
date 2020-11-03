NAME		= Minishell

SRCS		= main.c
SRCS		+= ft_prompt.c
SRCS		+= msh_parsing.c
SRCS		+= msh_get_cmd.c
SRCS		+= get_cmd_lst.c

OBJ_DIR		= ./srcs/objects/
MSH_DIR		= ./srcs/minishell/
LIBFT_DIR	= ./srcs/libft/
INC_DIR		= ./srcs/include/
LIBFT_A		= $(addprefix $(LIBFT_DIR), libft.a)
OBJ			= $(addprefix $(OBJ_DIR),$(SRCS:.c=.o))

CC			= gcc
CFLAGS		= -Wall -Werror -Wextra
RM			= rm -f
RM_DIR		= rm -rf

all:
	mkdir -p $(OBJ_DIR)
	make -C $(LIBFT_DIR)
	$(MAKE) $(NAME) --no-print-directory

$(OBJ_DIR)%.o:$(MSH_DIR)%.c $(INC_DIR)*.h
	$(CC) -c $< -o $@

$(NAME):$(OBJ) $(INC_DIR) $(LIBFT_A)
	$(CC) -g $(OBJ) $(MSH_DIR)env.a $(LIBFT_A)  -o $(NAME)

clean:
	$(RM_DIR) $(OBJ_DIR)
	$(MAKE) clean -C $(LIBFT_DIR)

fclean:
	$(RM_DIR) $(OBJ_DIR)
	$(RM) $(NAME)
	$(MAKE) fclean -C $(LIBFT_DIR)

re:fclean all

.PHONY:all clean fclean re
