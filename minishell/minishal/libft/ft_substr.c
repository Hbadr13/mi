/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbadr <hbadr@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/24 03:24:56 by hbadr             #+#    #+#             */
/*   Updated: 2021/11/26 14:42:35 by hbadr            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*p;
	size_t	j;
	size_t	i;

	i = start;
	j = 0;
	if (!s)
		return (0);
	if (ft_strlen(s + start) < len)
		p = (char *)malloc(sizeof(char) * (ft_strlen(s + start) + 1));
	else
		p = (char *)malloc(sizeof(char) * (len + 1));
	if (p == NULL)
		return (0);
	while (i < ft_strlen(s) && j < len)
		p[j++] = s[i++];
	p[j] = '\0';
	return (p);
}
