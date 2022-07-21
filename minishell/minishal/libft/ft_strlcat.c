/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbadr <hbadr@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/24 02:17:43 by hbadr             #+#    #+#             */
/*   Updated: 2021/11/26 14:47:09 by hbadr            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	i;
	size_t	d;
	size_t	ret;
	char	*s;

	s = (char *)src;
	d = ft_strlen(dst);
	i = 0;
	if (dstsize <= ft_strlen(dst))
		ret = ft_strlen(src) + dstsize;
	else
		ret = ft_strlen(src) + ft_strlen(dst);
	while ((d + 1 < dstsize) && (s[i] != '\0'))
	{
		dst[d] = s[i];
		i++;
		d++;
	}
	dst[d] = '\0';
	return (ret);
}
