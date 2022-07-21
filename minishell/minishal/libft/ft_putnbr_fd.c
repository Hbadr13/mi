/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbadr <hbadr@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/23 23:56:04 by hbadr             #+#    #+#             */
/*   Updated: 2021/11/26 14:37:29 by hbadr            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_fd(int n, int fd)
{
	long	var;

	var = n;
	if (var < 0)
	{
		ft_putchar_fd('-', fd);
		var = var * -1;
	}
	if (var < 10)
		ft_putchar_fd(var + '0', fd);
	else
	{
		ft_putnbr_fd(var / 10, fd);
		ft_putnbr_fd(var % 10, fd);
	}
}
