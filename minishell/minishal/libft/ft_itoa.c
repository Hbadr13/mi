/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbadr <hbadr@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/23 19:41:54 by hbadr             #+#    #+#             */
/*   Updated: 2021/11/26 14:45:19 by hbadr            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"libft.h"

static int	nmpr(int n)
{
	int	i;

	i = 1;
	if (n == 0)
		return (2);
	if (n < 0)
		i++;
	while (n)
	{
		n = n / 10;
		i++;
	}
	return (i);
}

char	*ft_itoa(int n)
{
	int		m;
	int		len;
	long	x;
	char	*p;

	x = n;
	len = nmpr(n) - 1;
	p = (char *)malloc(sizeof(char) * (len + 1));
	if (p == NULL)
		return (0);
	if (n == 0)
		p[0] = '0';
	if (x < 0)
	{
		x = -1 * x;
		p[0] = '-';
	}
	while (x)
	{
		m = x;
		x = x / 10;
		p[--len] = m - x * 10 + '0';
	}
	p[nmpr(n) - 1] = '\0';
	return (p);
}
