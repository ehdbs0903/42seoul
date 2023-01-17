/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   remove_quote.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jungeun <jungeun@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/26 09:58:22 by hajeong           #+#    #+#             */
/*   Updated: 2023/01/14 18:50:11 by jungeun          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	remove_quote(t_list **lexer_token)
{
	t_list	*temp;

	temp = *lexer_token;
	while (temp != NULL)
	{
		if (temp->label % 9 == SINGLE_QUOTE || temp->label % 9 == DOUBLE_QUOTE)
		{
			ft_memmove(temp->content, temp->content + 1, \
			ft_strlen(temp->content) - 2);
			temp->content[ft_strlen(temp->content) - 2] = '\0';
			temp->label = 9 * (temp->label / 9);
		}
		temp = temp->next;
	}
}
