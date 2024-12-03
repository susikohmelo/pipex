/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_pipex.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ljylhank <ljylhank@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/26 20:39:39 by ljylhank          #+#    #+#             */
/*   Updated: 2024/11/29 19:07:35 by ljylhank         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

// - [ Append 2 paths together, in our case the envp path and the command ]
// eg. path1=/usr/bin path2=cat will return /usr/bin/cat
static inline char	*append_paths(char *path1, char *path2)
{
	char	*new_path;
	int		i;
	int		i2;

	i = ft_strlen(path1);
	new_path = malloc((i + ft_strlen(path2) + 2) * sizeof(char));
	if (!new_path)
		pipexit("path appending failed", 0);
	i = 0;
	while (path1[i])
	{
		new_path[i] = path1[i];
		i++;
	}
	new_path[i++] = '/';
	i2 = 0;
	while (path2[i2])
		new_path[i++] = path2[i2++];
	new_path[i] = '\0';
	return (new_path);
}

// - [ Frees an array of character pointers ]
// Slightly redundant as we are using exit() but it's good practice
void	free_strarr(char **strarr)
{
	int	index;

	index = 0;
	while (strarr[index])
		free(strarr[index++]);
	free(strarr[index]);
	free(strarr);
}

// - [ Finds the path from envp and retuns array containing each directory ]
static inline char	**get_all_paths(char **envp, char *keyword)
{
	char	**all_paths;
	int		found;
	int		index;
	int		i;

	index = 0;
	found = 0;
	while (envp[index] && !found)
	{
		i = 0;
		while (envp[index][i] == keyword[i] && envp[index][i] && keyword[i])
		{
			if (keyword[i + 1] == '\0')
				found = 1;
			i++;
		}
		if (!found)
			index++;
	}
	if (!found)
		pipexit("no matching path", 0);
	all_paths = ft_split(envp[index] + i, ':');
	if (!all_paths)
		pipexit("separating env paths failed", 0);
	return (all_paths);
}

// - [ Find path of the command from the environment variables ]
static inline char	*get_cmnd_path(char *cmd, char **envp)
{
	char	**all_paths;
	char	*appended_path;
	int		index;

	index = 0;
	all_paths = get_all_paths(envp, "PATH=");
	while (all_paths[index])
	{
		appended_path = append_paths(all_paths[index], cmd);
		if (access(appended_path, F_OK) == 0)
		{
			if (access(appended_path, X_OK) == 0)
			{
				free_strarr(all_paths);
				return (appended_path);
			}
			else
				pipexit("no permissions to execute command", 1);
		}
		free(appended_path);
		index++;
	}
	pipexit(ft_strjoin("command not found: ", cmd), 0);
	return (0);
}

// - [ Executes desired command from ]
// Searches the folder we are in currently, then searches through-
// the environment path if it's not found
void	execute_cmnd(char *raw_command_input, char **envp)
{
	char	*command_path;
	char	**command_fields;

	command_fields = ft_csplit(raw_command_input, ' ');
	if (access(command_fields[0], F_OK) == 0)
	{
		if (access(command_fields[0], X_OK) == 0)
		{
			command_path = command_fields[0];
		}
		else
			pipexit("no permissions to execute command", 1);
	}
	else
		command_path = get_cmnd_path(command_fields[0], envp);
	if (execve(command_path, command_fields, envp) < 0)
		pipexit("executing command failed", 0);
}
