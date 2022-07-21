/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbadr <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/24 01:50:17 by hbadr             #+#    #+#             */
/*   Updated: 2021/11/26 15:59:36 by hbadr            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c )
{
	char	*ss;

	ss = (char *)s;
	if ((unsigned char)c == 0)
		return (ss + ft_strlen(s));
	while (*ss)
	{
		if (*ss == (unsigned char)c)
			return (ss);
		ss++;
	}
	return (NULL);
}
