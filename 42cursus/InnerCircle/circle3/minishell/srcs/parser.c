/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: doykim <doykim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/22 18:49:34 by doykim            #+#    #+#             */
/*   Updated: 2022/12/23 03:21:23 by doykim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	init_parser_tokens(t_parser_tokens *parser_tokens)
{
	parser_tokens->type = NULL;
	parser_tokens->cmd = NULL;
	parser_tokens->word = NULL;
	parser_tokens->pipe = NULL;
	parser_tokens->redirect = NULL;
}

void	parser(t_list *lexer_token, t_parser_tokens *parser_tokens)
{
	//int i;

	//i = 0;
	init_parser_tokens(parser_tokens);
	while (lexer_token != NULL)
	{
		if (iscmd(lexer_token->content))
		{
			ft_lstadd_back(&parser_tokens->type, ft_lstnew("cmd"));
			ft_lstadd_back(&parser_tokens->cmd, ft_lstnew(lexer_token->content));
		}
		else
		{
			ft_lstadd_back(&parser_tokens->type, ft_lstnew("???"));
		}
		lexer_token = lexer_token->next;
	}
}
