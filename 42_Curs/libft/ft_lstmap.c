/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sedere <sedere@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/11 12:21:17 by sedere            #+#    #+#             */
/*   Updated: 2023/07/11 12:21:18 by sedere           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*ad;
	t_list	*ap;

	ad = NULL;
	while (lst)
	{
		ap = ft_lstnew(f(lst -> content));
		if (!ap)
		{
			ft_lstclear(&ad, del);
			return (NULL);
		}
		ft_lstadd_back(&ad, ap);
		lst = lst -> next;
	}
	return (ad);
}