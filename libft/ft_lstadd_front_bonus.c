/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_front_bonus.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsylvain <dsylvain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/10 10:44:57 by dsylvain          #+#    #+#             */
/*   Updated: 2023/11/16 08:41:41 by dsylvain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_front(t_list **lst, t_list *new)
{
	if (!lst || !new)
		return ;
	if (*lst)
	{
		(*lst)->prev->next = new;
		new->next = *lst;
		new->prev = (*lst)->prev;
		(*lst)->prev = new;
	}
	else
	{
		new->next = new;
		new->prev = new;
	}
	*lst = new;
}
