/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jungchoi <jungchoi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/18 16:15:56 by jungchoi          #+#    #+#             */
/*   Updated: 2022/03/25 22:20:08 by jungchoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*ret;
	t_list	*temp;

	if (!lst)
		return (0);
	ret = ft_lstnew(f(lst->content));
	lst = lst->next;
	temp = ret;
	while (lst)
	{
		temp->next = ft_lstnew(f(lst->content));
		if (!(temp->next))
		{
			ft_lstclear(&ret, del);
			return (0);
		}
		lst = lst->next;
		temp = temp->next;
	}
	return (ret);
}
