/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jungchoi <jungchoi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/18 15:41:02 by jungchoi          #+#    #+#             */
/*   Updated: 2022/10/20 17:06:50 by jungchoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*lst_ptr;

	lst_ptr = *lst;
	if (!(*lst))
		*lst = new;
	else
	{
		while (lst_ptr->next)
			lst_ptr = lst_ptr->next;
		lst_ptr->next = new;
	}
}
