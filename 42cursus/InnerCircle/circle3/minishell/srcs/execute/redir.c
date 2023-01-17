/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redir.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jungeun <jungeun@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/14 18:53:49 by jungeun           #+#    #+#             */
/*   Updated: 2023/01/14 18:54:44 by jungeun          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	set_redir(t_exec_token *token)
{
	t_list	*in;
	t_list	*out;

	in = token->parser_token->in;
	while (in != NULL)
	{
		set_redir_in(token, in->content, in->next->content);
		in = in->next->next;
	}
	out = token->parser_token->out;
	while (out != NULL)
	{
		set_redir_out(out->content, out->next->content);
		out = out->next->next;
	}
}

char	*replace_env_heredoc(char *str, t_env *env_list)
{
	char	*key;
	char	*key_end;
	char	*temp;

	while (ft_strchr(str, '$'))
	{
		key = ft_strchr(str, '$');
		key_end = key + 1;
		while (ft_isalnum(*key_end))
			key_end++;
		key = ft_substr(key, 1, (int)(key_end - key - 1));
		temp = join_env(str, get_env_value(env_list, key), key_end);
		free(str);
		str = temp;
		free(key);
	}
	return (str);
}

char	*replace_env_heredoc_exit_status(char *str)
{
	char	*key;
	char	*key_end;
	char	*temp;

	while (ft_strnstr(str, "$?", ft_strlen(str)))
	{
		key = ft_strchr(str, '$');
		key_end = key + 2;
		key = ft_substr(key, 1, (int)(1));
		temp = join_env_free(str, ft_itoa(g_info.exit_status), key_end);
		free(str);
		str = temp;
		free(key);
	}
	return (str);
}

void	set_redir_in(t_exec_token *token, char *redir_sign, char *filename)
{
	int		fd;
	char	*heredoc_filename;

	fd = -1;
	if (ft_strncmp(redir_sign, "<", 2) == 0)
		fd = open(filename, O_RDONLY);
	else if (ft_strncmp(redir_sign, "<<", 3) == 0)
	{
		heredoc_filename = ft_join_and_free("/tmp/", \
		ft_itoa(token->heredoc_num));
		token->heredoc_num++;
		fd = open(heredoc_filename, O_RDONLY);
		free(heredoc_filename);
	}
	if (fd == -1)
		error_exit("no such file or directory\n", 1);
	if (dup2(fd, STDIN_FILENO) == -1)
		error_exit("dup2 error\n", 1);
	close(fd);
}

void	set_redir_out(char *redir_sign, char *filename)
{
	int	fd;

	fd = -1;
	if (ft_strncmp(redir_sign, ">", 2) == 0)
		fd = open(filename, O_WRONLY | O_CREAT | O_TRUNC, 0644);
	else if (ft_strncmp(redir_sign, ">>", 3) == 0)
		fd = open(filename, O_WRONLY | O_CREAT | O_APPEND, 0644);
	if (fd == -1)
		error_exit("open error\n", 1);
	if (dup2(fd, STDOUT_FILENO) == -1)
		error_exit("dup2 error\n", 1);
	close(fd);
}
