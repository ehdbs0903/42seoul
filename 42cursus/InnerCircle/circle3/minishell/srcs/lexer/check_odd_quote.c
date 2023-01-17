/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_odd_quote.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jungeun <jungeun@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/26 09:58:22 by hajeong           #+#    #+#             */
/*   Updated: 2023/01/14 18:51:16 by jungeun          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	check_odd_quote(t_list *lexer_token)
{
	int	len;

	while (lexer_token != NULL)
	{
		if (lexer_token->label % 9 == DOUBLE_QUOTE \
		|| lexer_token->label % 9 == SINGLE_QUOTE)
		{
			len = ft_strlen(lexer_token->content);
			if (len < 2)
				return (1);
			if (lexer_token->content[0] != lexer_token->content[len - 1])
				return (1);
		}
		lexer_token = lexer_token->next;
	}
	return (0);
}
