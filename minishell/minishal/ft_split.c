/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbadr <hbadr@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/20 15:53:26 by hbadr             #+#    #+#             */
/*   Updated: 2022/02/20 16:02:23 by hbadr            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header/minishell.h"
size_t	ft_ssstrlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i])
		i++; 
	return (i);
}

static char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*p;
	size_t	j;
	size_t	i;

	i = start;
	j = 0;
	if (!s)
		return (0);
	if (ft_ssstrlen(s + start) < len)
		p = (char *)malloc(sizeof(char) * (ft_ssstrlen(s + start) + 1));
	else
		p = (char *)malloc(sizeof(char) * (len + 1));
	if (p == NULL)
		return (0);
	while (i < ft_ssstrlen(s) && j < len)
		p[j++] = s[i++];
	p[j] = '\0';
	return (p);
}

static int	num(char const *str, char c)
{
	int	i;
	int	k;
	int	ret;

	i = 0;
	k = 0;
	ret = 0;
	while (str[i])
	{
		while (str[i] == c && str[i] != '\0')
			i++;
		while (str[i] != c && str[i] != '\0')
		{
			i++;
			k++;
		}
		if (k != 0)
		{
			ret++;
			k = 0;
		}
	}
	return (ret);
}

static	int	hsapp(char const *s, char c)
{
	int	i;

	i = 0;
	while (s[i] != '\0')
	{
		if (s[i] == c)
			return (i);
		i++;
	}
	return (i);
}

static	char	**freemem(char **s)
{
	int	i;

	i = 0;
	while (s[i])
	{
		free(s[i]);
		i++;
	}
	free(s);
	return (NULL);
}

char	**ft_split(char const *s, char c)
{
	char			**p;
	unsigned int	i;
	size_t			len;
	int				k;

	i = 0;
	k = 0;
	if (!s)
		return (0);
	p = (char **)malloc((sizeof(char *) * (num(s, c) + 1)));
	if (!p)
		return (0);
	while (s[i])
	{
		while (s[i] == c)
			i++;
		len = hsapp(&s[i], c);
		if (len != 0)
			p[k++] = ft_substr(s, i, len);
		if (len != 0 && !p[k - 1])
			return (freemem(p));
		i = i + len;
	}
	p[k] = 0;
	return (p);
}
