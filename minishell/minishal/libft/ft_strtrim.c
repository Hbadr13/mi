/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbadr <hbadr@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/24 03:06:28 by hbadr             #+#    #+#             */
/*   Updated: 2021/11/26 14:48:17 by hbadr            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	int	charch(char c, char const *str)
{
	int	i;

	i = -1;
	while (str[++i])
		if (str[i] == c)
			return (1);
	return (0);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	int		i;
	size_t	len;

	i = -1;
	len = 0;
	if (s1 == NULL)
		return (0);
	if (set == NULL)
		return (ft_strdup(s1));
	while (s1[++i])
	{
		if (charch(s1[i], set) == 0)
		{
			len = ft_strlen(s1);
			while (--len)
				if (charch((s1)[len], set) == 0)
					return (ft_substr(s1, i, len - i + 1));
		}
	}
	return (ft_strdup(""));
}
