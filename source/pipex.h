/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ljylhank <ljylhank@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/26 17:13:43 by ljylhank          #+#    #+#             */
/*   Updated: 2024/11/29 19:08:20 by ljylhank         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

// "Libft" is mostly standard libc functions, but made by me.
# include "libft/libft.h"
# include <stdio.h>
# include <sys/wait.h>
# include <errno.h>
# include <fcntl.h>

void	execute_cmnd(char *command, char **envp);
void	pipexit(char *str, int use_perror);
void	free_strarr(char **strarr);
char	**ft_csplit(char const *s, char c);
#endif
