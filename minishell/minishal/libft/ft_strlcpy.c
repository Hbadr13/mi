/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbadr <hbadr@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/24 02:14:37 by hbadr             #+#    #+#             */
/*   Updated: 2021/11/26 14:39:00 by hbadr            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
	size_t	i;
	size_t	j;
	char	*src1;

	src1 = (char *)src;
	i = 0;
	j = ft_strlen(src);
	if (dstsize == 0)
		return (j);
	while (src[i] != '\0' && dstsize - 1 > i)
	{
		dst[i] = src1[i];
		i++;
	}
	dst[i] = '\0';
	return (j);
}
