/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanghan <sanghan@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/18 04:41:35 by sanghan           #+#    #+#             */
/*   Updated: 2022/05/20 13:50:15 by sanghan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*lst_temp;

	if (lst == NULL || del == NULL)
		return ;
	while (*lst)
	{
		lst_temp = (*lst)->next;
		del((*lst)->content);
		free((*lst));
		*lst = lst_temp;
	}
	*lst = NULL;
}
