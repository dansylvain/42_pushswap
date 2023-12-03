/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsylvain <dsylvain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/11 12:59:01 by dsylvain          #+#    #+#             */
/*   Updated: 2023/11/16 11:58:44 by dsylvain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst)
{
	t_list	*next;
	t_list	*current;

	if (!lst)
		return ;
	current = *lst;
	if (!current)
		return ;
	while (1)
	{
		next = current->next;
		ft_lstdelone(current);
		current = next;
		if (current == *lst)
			break ;
	}
	*lst = NULL;
}
