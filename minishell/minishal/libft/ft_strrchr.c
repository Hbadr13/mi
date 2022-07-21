/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbadr <hbadr@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/24 03:38:04 by hbadr             #+#    #+#             */
/*   Updated: 2021/11/26 15:57:27 by hbadr            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	char	*ss;
	size_t	len;

	ss = (char *)s;
	len = ft_strlen(s);
	if ((unsigned char)c == 0)
		return (ss + ft_strlen(s));
	while (len--)
		if (ss[len] == (unsigned char)c)
			return (ss + len);
	return (0);
}
