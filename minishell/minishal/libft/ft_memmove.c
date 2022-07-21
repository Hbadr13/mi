/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbadr <hbadr@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/05 08:51:38 by ebouabba          #+#    #+#             */
/*   Updated: 2021/11/26 14:46:23 by hbadr            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	char	*d;
	char	*s;

	d = dst;
	s = (char *)src;
	if (dst == src)
		return (dst);
	else if (src < dst)
	{
		while (len--)
		{
			*(d + len) = *(s + len);
		}
	}
	else
		ft_memcpy(dst, src, len);
	return (dst);
}
