/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_redirection.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jungeun <jungeun@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/26 09:58:22 by hajeong           #+#    #+#             */
/*   Updated: 2023/01/14 18:50:48 by jungeun          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	move_front_in_redirection(t_parser_token *parser_token)
{
	t_list	*prev;

	parser_token->in = parser_token->cmd;
	prev = parser_token->cmd->next;
	while (prev->next != NULL && \
	(prev->next->label == REDIR_IN || prev->next->label == REDIR_HEREDOC))
		prev = prev->next->next;
	parser_token->cmd = prev->next;
	prev->next = NULL;
}

static void	move_in_redirection(t_parser_token *parser_token)
{
	t_list	*temp;
	t_list	*prev;

	if (parser_token->cmd != NULL && (parser_token->cmd->label == REDIR_IN \
	|| parser_token->cmd->label == REDIR_HEREDOC))
		move_front_in_redirection(parser_token);
	if (parser_token->cmd == NULL)
		return ;
	prev = parser_token->cmd;
	temp = parser_token->cmd->next;
	while (temp != NULL)
	{
		if (temp->label == REDIR_IN || temp->label == REDIR_HEREDOC)
		{
			prev->next = temp->next->next;
			ft_lstadd_back(&(parser_token->in), temp);
			temp->next->next = NULL;
			temp = prev;
			continue ;
		}
		prev = temp;
		temp = temp->next;
	}
}

static void	move_front_out_redirection(t_parser_token *parser_token)
{
	t_list	*prev;

	parser_token->out = parser_token->cmd;
	prev = parser_token->cmd->next;
	while (prev->next != NULL && \
	(prev->next->label == REDIR_OUT || prev->next->label == REDIR_DOUBLE_OUT))
		prev = prev->next->next;
	parser_token->cmd = prev->next;
	prev->next = NULL;
}

static void	move_out_redirection(t_parser_token *parser_token)
{
	t_list	*temp;
	t_list	*prev;

	if (parser_token->cmd != NULL && (parser_token->cmd->label == REDIR_OUT \
	|| parser_token->cmd->label == REDIR_DOUBLE_OUT))
		move_front_out_redirection(parser_token);
	if (parser_token->cmd == NULL)
		return ;
	prev = parser_token->cmd;
	temp = parser_token->cmd->next;
	while (temp != NULL)
	{
		if (temp->label == REDIR_OUT || temp->label == REDIR_DOUBLE_OUT)
		{
			prev->next = temp->next->next;
			ft_lstadd_back(&(parser_token->out), temp);
			temp->next->next = NULL;
			temp = prev;
			continue ;
		}
		prev = temp;
		temp = temp->next;
	}
}

void	sort_redirection(t_parser_token *parser_token, int len)
{
	int				i;
	t_parser_token	*temp;

	i = 0;
	while (i < len)
	{
		temp = &parser_token[i];
		move_in_redirection(temp);
		move_out_redirection(temp);
		i++;
	}
}
