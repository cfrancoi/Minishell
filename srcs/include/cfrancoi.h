



#ifndef CFRANCOI_H
#define CFRANCOI_H

#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/wait.h>
#include <fcntl.h>

int		msh_push_cmd(t_cmd **ptr);
int		msh_execve(t_cmd *ptr, int *p_fd, int *p_rd);
int		msh_dup_fd(t_cmd *ptr);

#endif
