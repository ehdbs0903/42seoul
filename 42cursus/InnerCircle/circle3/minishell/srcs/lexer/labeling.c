/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   labeling.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jungeun <jungeun@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/26 09:58:22 by hajeong           #+#    #+#             */
/*   Updated: 2023/01/14 18:51:28 by jungeun          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	labeling(t_list *lexer_token)
{
	while (lexer_token != NULL)
	{
		if (lexer_token->content[0] == '\"')
			lexer_token->label = DOUBLE_QUOTE;
		else if (lexer_token->content[0] == '\'')
			lexer_token->label = SINGLE_QUOTE;
		else if (ft_strchr("\t\n\v\f\r ", lexer_token->content[0]))
			lexer_token->label = BLANK;
		else if (lexer_token->content[0] == '|')
			lexer_token->label = PIPE;
		else if (lexer_token->content[0] == '<'\
			|| lexer_token->content[0] == '>')
		{
			lexer_token->label = REDIR_IN;
			if (lexer_token->content[0] == '>')
				lexer_token->label = REDIR_OUT;
			if (lexer_token->content[0] == lexer_token->content[1])
				(lexer_token->label)++;
		}
		lexer_token = lexer_token->next;
	}
}

void	labeling_after_heredoc(t_list *lexer_token)
{
	int	flag;

	flag = 0;
	while (lexer_token != NULL)
	{
		if (lexer_token->label == REDIR_HEREDOC)
			flag = 1;
		else if (flag == 1 && (lexer_token->label == NORMAL_STRING || \
			lexer_token->label == DOUBLE_QUOTE \
			|| lexer_token->label == SINGLE_QUOTE))
		{
			while (lexer_token != NULL && (lexer_token->label == \
			NORMAL_STRING || lexer_token->label == DOUBLE_QUOTE \
			|| lexer_token->label == SINGLE_QUOTE))
			{
				lexer_token->label += AFTER_HEREDOC;
				lexer_token = lexer_token->next;
			}
			flag = 0;
			continue ;
		}
		lexer_token = lexer_token->next;
	}
}
