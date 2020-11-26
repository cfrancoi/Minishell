#ifndef CFRANCOI_H
#define CFRANCOI_H

#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/wait.h>
#include <fcntl.h>

typedef struct          s_tfrk {
	int                 pid;
	t_cmd               *cmd;
	int                 pfd[2];
	struct s_tfrk        *prev; // to get previous pipe
	struct s_tfrk        *next;
}                       t_tfrk;

t_tfrk   *crt_lst(t_cmd *cmd);
int	child(t_cmd *ptr, char *path, char **envp);

#endif
