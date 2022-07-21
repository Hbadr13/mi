/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbadr <hbadr@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/24 02:37:41 by hbadr             #+#    #+#             */
/*   Updated: 2021/11/26 14:39:35 by hbadr            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	i;
	size_t	l;

	i = 0;
	l = ft_strlen(needle);
	if (needle[i] == 0)
		return ((char *)haystack);
	while ((haystack[i]) && (i + l - 1) < len)
	{
		if (haystack[i] == needle[0])
		{
			if (ft_strncmp(haystack + i, needle, l) == 0)
				return ((char *)haystack + i);
		}
		i++;
	}
	return (NULL);
}
