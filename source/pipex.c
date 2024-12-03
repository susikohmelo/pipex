/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ljylhank <ljylhank@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/26 16:46:06 by ljylhank          #+#    #+#             */
/*   Updated: 2024/12/02 13:21:26 by ljylhank         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

// - [ Exit program and print error message ]
// set use_perror to 1 if you also want to print errno message
void	pipexit(char *str, int use_perror)
{
	int	i;

	if (use_perror)
		perror(str);
	else
	{
		ft_putstr_fd("pipex: ", STDERR_FILENO);
		ft_putstr_fd(str, STDERR_FILENO);
		i = ft_strlen(str);
		if (i != 0)
			if (str[i - 1] != '\n')
				ft_putchar_fd('\n', STDERR_FILENO);
	}
	exit(1);
}

// - [ Open given file & check if we have permissions ]
static inline int	open_this_file(char *filename, int input_or_output)
{
	int	r;

	if (input_or_output == 0)
		r = open(filename, O_RDONLY, 0777);
	else
		r = open(filename, O_CREAT | O_WRONLY | O_TRUNC, 0777);
	if (r < 0)
	{
		if (access(filename, F_OK) == 0)
			pipexit(ft_strjoin("permission denied: ", filename), 0);
		else
			pipexit(ft_strjoin("no such file or directory: ", filename), 0);
	}
	return (r);
}

// - [ Responsible for the second input command ]
// dup2 is used to make stdin/out be the pipe read end & the custom output file
static inline void	parent(char **argv, char **envp, int *pipe_fd)
{
	int		output_fd;
	char	*command;

	output_fd = open_this_file(argv[4], 1);
	dup2(pipe_fd[0], STDIN_FILENO);
	dup2(output_fd, STDOUT_FILENO);
	close(pipe_fd[1]);
	command = argv[3];
	execute_cmnd(command, envp);
}

// - [ Responsible for the first input command ]
// dup2 is used to make stdin/out be the custom input file & the pipe write end
static inline void	child(char **argv, char **envp, int *pipe_fd)
{
	int		input_fd;
	char	*command;

	input_fd = open_this_file(argv[1], 0);
	dup2(input_fd, STDIN_FILENO);
	dup2(pipe_fd[1], STDOUT_FILENO);
	close(pipe_fd[0]);
	command = argv[2];
	execute_cmnd(command, envp);
}

// - [ Main ] - //
// 1. Simple argc error check
// 2. Create a pipe
// 3. Fork & run functions for parent/child respectively
int	main(int argc, char **argv, char **envp)
{
	int		pipe_fd[2];
	pid_t	pid;

	if (argc != 5)
		pipexit("invalid input; use this format: infile cmd cmd outfile\n", 0);
	if (pipe(pipe_fd) < 0)
		pipexit("pipe creation failed", 0);
	pid = fork();
	if (pid < 0)
		pipexit("forking failed", 0);
	if (pid == 0)
		child(argv, envp, pipe_fd);
	else
		parent(argv, envp, pipe_fd);
	return (0);
}
