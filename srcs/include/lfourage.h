#ifndef		LFOURAGE_H
# define	LFOURAGE_H

# include	"./minishell.h"

# define PIPE	1
# define SEMI	2
# define LFT	3
# define RGT	4
# define DRGT	5

typedef	struct		s_cmd
{
	int				sep;
	char			*str;
	struct s_cmd	*next;
}					t_cmd;

int		get_cmd_lst(char **str, t_cmd **src);

# endif
