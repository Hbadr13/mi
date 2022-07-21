/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbadr <hbadr@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/24 03:32:34 by hbadr             #+#    #+#             */
/*   Updated: 2021/11/26 14:45:39 by hbadr            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_back(t_list **alst, t_list *new)
{
	t_list	*new_fin;

	if (!*alst)
	{
		*alst = new;
		return ;
	}
	new_fin = ft_lstlast(*alst);
	new_fin->next = new;
}
