NAME		= Minishell

SRCS		= main.c
SRCS		+= edit_qmrk.c
SRCS		+= ft_prompt.c
SRCS		+= msh_parsing.c
SRCS		+= msh_parsing_utils.c
SRCS		+= msh_get_cmd.c
SRCS		+= get_args_ptr.c
SRCS		+= get_args_lst.c
SRCS		+= get_cmd_lst.c
SRCS		+= msh_execve.c
SRCS		+= msh_exit.c
SRCS		+= msh_dup_fd.c
SRCS		+= msh_push_cmd.c
SRCS		+= builtins_alloc.c
SRCS		+= get_builtin.c
SRCS		+= msh_get_path.c


OBJ_DIR		= ./srcs/objects/
MSH_DIR		= ./srcs/minishell/
LIBFT_DIR	= ./srcs/libft/
ENV_DIR		= ./srcs/env/
INC_DIR		= ./srcs/include/
BUILT_DIR	= ./srcs/builtins/
ECHO_A		= $(addprefix $(BUILT_DIR), echo/echo.a)
EXPORT_A	= $(addprefix $(BUILT_DIR), export/export.a)
LIBFT_A		= $(addprefix $(LIBFT_DIR), libft.a)
ENV_A		= $(addprefix $(ENV_DIR), env.a)
OBJ			= $(addprefix $(OBJ_DIR),$(SRCS:.c=.o))

CC			= gcc
CFLAGS		= -Wall -Werror -Wextra
RM			= rm -f
RM_DIR		= rm -rf

all:
	mkdir -p $(OBJ_DIR)
	make -C $(LIBFT_DIR)
	make -C $(BUILT_DIR)
	make -C $(ENV_DIR)
	$(MAKE) $(NAME) --no-print-directory

$(OBJ_DIR)%.o:$(MSH_DIR)%.c $(INC_DIR)*.h
	$(CC) $(CFLAGS) -c $< -o $@

$(NAME):$(OBJ) $(INC_DIR) $(LIBFT_A) $(ENV_A) $(ECHO_A) $(EXPORT_A)
	$(CC) $(CFLAGS) -g $(OBJ) $(ECHO_A) srcs/builtins/env/env.a $(ENV_A) $(EXPORT_A) $(LIBFT_A) -o $(NAME)

clean:
	$(RM_DIR) $(OBJ_DIR)
	$(MAKE) clean -C $(LIBFT_DIR)
	$(MAKE) clean -C $(ENV_DIR)
	$(MAKE) clean -C $(BUILT_DIR)

fclean:
	$(RM_DIR) $(OBJ_DIR)
	$(RM) $(NAME)
	$(MAKE) fclean -C $(LIBFT_DIR)
	$(MAKE) fclean -C $(ENV_DIR)
	$(MAKE) fclean -C $(BUILT_DIR)

re:fclean all

.PHONY:all clean fclean re
