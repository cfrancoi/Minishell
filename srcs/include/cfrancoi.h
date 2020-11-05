



#ifndef CFRANCOI_H
#define CFRANCOI_H

#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/wait.h>
#include <fcntl.h>

int		msh_execve(char **av, t_cmd **ptr);

#endif
