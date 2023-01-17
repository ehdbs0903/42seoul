/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_token.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jungeun <jungeun@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/26 09:58:22 by hajeong           #+#    #+#             */
/*   Updated: 2023/01/14 18:49:27 by jungeun          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	parser_token_size(t_list *lexer_token)
{
	int	len;

	len = 1;
	while (lexer_token != NULL)
	{
		if (lexer_token->label == PIPE)
			len++;
		lexer_token = lexer_token->next;
	}
	return (len);
}

t_parser_token	*init_parser_token(int size)
{
	t_parser_token	*parser_token;
	int				i;

	parser_token = (t_parser_token *)malloc(sizeof(t_parser_token) * size);
	if (parser_token == NULL)
		return (NULL);
	i = 0;
	while (i < size)
	{
		parser_token[i].cmd = NULL;
		parser_token[i].in = NULL;
		parser_token[i].out = NULL;
		i++;
	}
	return (parser_token);
}

void	make_parser_token(t_list **lexer_token, t_parser_token *parser_token)
{
	t_list	*prev;
	t_list	*temp;
	t_list	*del;
	int		i;

	temp = *lexer_token;
	prev = temp;
	parser_token[0].cmd = temp;
	i = 0;
	while (temp != NULL)
	{
		if (temp->label == PIPE)
		{
			del = temp;
			parser_token[++i].cmd = temp->next;
			prev->next = NULL;
			ft_lstdelone(del, free);
		}
		prev = temp;
		temp = temp->next;
	}
}

void	free_parser_token(t_parser_token *parser_token, int len)
{
	int		i;

	i = 0;
	while (i < len)
	{
		if (parser_token[i].cmd != NULL)
			ft_lstclear(&(parser_token[i].cmd), free);
		if (parser_token[i].in != NULL)
			ft_lstclear(&(parser_token[i].in), free);
		if (parser_token[i].out != NULL)
			ft_lstclear(&(parser_token[i].out), free);
		i++;
	}
	free(parser_token);
}
