/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_pipe.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jungeun <jungeun@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/14 18:53:36 by jungeun           #+#    #+#             */
/*   Updated: 2023/01/14 18:53:37 by jungeun          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	init_exec_info(pid_t **pids, int ***fds, int len)
{
	int	i;

	*pids = (pid_t *)malloc(sizeof(pid_t) * len);
	*fds = (int **)malloc(sizeof(int *) * len);
	if (*pids == NULL || *fds == NULL)
		return (free_init_exec_info(pids, fds, -1));
	i = 0;
	while (i < len)
	{
		(*fds)[i] = (int *)malloc(sizeof(int) * 2);
		if ((*fds)[i] == NULL)
			return (free_init_exec_info(pids, fds, i));
		i++;
	}
	i = 0;
	while (i < len)
	{
		if (pipe((*fds)[i]) == -1)
			return (free_init_exec_info(pids, fds, len - 1));
		i++;
	}
	return (0);
}

void	close_all_fds(int **fds, int len)
{
	int	i;

	i = 0;
	while (i < len)
	{
		close(fds[i][0]);
		close(fds[i][1]);
		i++;
	}
}

void	wait_all_childs(pid_t *pids, int len)
{
	int		status;
	pid_t	pid;

	while (1)
	{
		pid = waitpid(-1, &status, 0);
		if (pid == -1)
			break ;
		if (WIFEXITED(status))
			g_info.exit_status = WEXITSTATUS(status);
		if (pid != pids[len - 1])
			continue ;
	}
	pid = waitpid(-1, &status, 0);
	if (WIFEXITED(status))
		g_info.exit_status = WEXITSTATUS(status);
}

void	exec_pipe(t_exec_token *token, pid_t *pids, int **fds, int len)
{
	int	i;

	i = 0;
	while (i < len)
	{
		pids[i] = fork();
		if (pids[i] == -1)
			error_exit("fork error\n", 1);
		if (pids[i] == 0)
			child_process(fds, i, token[i], len);
		i++;
	}
}

void	child_process(int **fds, int i, t_exec_token token, int len)
{
	if (i != 0)
	{
		close(fds[i - 1][1]);
		dup2(fds[i - 1][0], STDIN_FILENO);
		close(fds[i - 1][0]);
	}
	if (i != len - 1)
	{
		close(fds[i][0]);
		dup2(fds[i][1], STDOUT_FILENO);
		close(fds[i][1]);
	}
	i = 0;
	while (i < len)
	{
		close(fds[i][0]);
		close(fds[i][1]);
		i++;
	}
	set_redir(&token);
	if (is_builtin(&token))
		exec_builtin(&token, g_info.env_list);
	else
		run_execve_cmd(token.cmd, g_info.env_list);
	exit(g_info.exit_status);
}
