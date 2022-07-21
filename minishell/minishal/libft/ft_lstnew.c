/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbadr <hbadr@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/23 23:06:59 by hbadr             #+#    #+#             */
/*   Updated: 2021/11/26 14:35:02 by hbadr            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(void *content)
{
	t_list	*n_node;

	n_node = (t_list *)malloc(sizeof(t_list *));
	if (!n_node)
		return (0);
	n_node->content = content;
	n_node->next = NULL;
	return (n_node);
}
