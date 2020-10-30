/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   run_prgm.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfrancoi <cfrancoi@student.le-101.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/29 16:26:13 by cfrancoi          #+#    #+#             */
/*   Updated: 2020/10/29 17:08:27 by cfrancoi         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

#include <unistd.h>
#include <stdio.h>
#include <sys/types.h>

#include <sys/wait.h>

#include <signal.h>

void sighandler(int signum) {
   printf("\nCaught signal %d, coming out... on %i\n", signum, getpid());
   //_exit(1);
  return;
}

void sigleave(int signum) {
   printf("\nCaught signal %d, coming out... on %i\n", signum, getpid());
   exit(1);
   }

int		run_prgm(char **av)
{
	pid_t	pid;
	int		status;


	printf("%s:\n", av[0]);

	if ((pid = fork()) == -1)
	{
		/* fork fail */
		perror("fork");
		return (-1);
	}
	else if (pid == 0)
	{
		/* processus fils */ 
		printf("fils pid : %i\n", getpid());
		execve(av[0], av, NULL);
	}
	else
	{
		/* processus pere */
		printf("pere pid : %i\n", getpid());
		wait(&status);
	}
	printf("return status : [%i]\n", status);
	return (status);
}

int	main(int ac, char **av)
{
	signal(SIGINT, &sighandler);
	if (ac >= 2)
		run_prgm(&av[1]);
	
	signal(SIGINT, &sigleave);
	while (1)
	 ;
	printf("sortie\n");
	return (0);
}
