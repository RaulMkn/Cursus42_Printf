/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmakende <rmakende@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/02 14:43:11 by rmakende          #+#    #+#             */
/*   Updated: 2024/06/12 18:23:42 by rmakende         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_putnbr(int nb, int fd)
{
	int		result;
	char	str[10];
	int		i;

	result = 0;
	i = 0;
	if (nb < 0)
	{
		result += ft_putchar_fd('-', fd);
		nb = -nb;
	}
	while (nb != 0)
	{
		str[i++] = (nb % 10) + '0';
		nb /= 10;
	}
	while (i > 0)
	{
		result += ft_putchar_fd(str[--i], fd);
	}
	return (result);
}

int	ft_putnbr_fd(int n, int fd)
{
	if (n == 0)
	{
		return (ft_putchar_fd('0', fd));
	}
	else if (n == 2147483647)
	{
		return (ft_putstr_fd("2147483647", fd));
	}
	else if (n == -2147483648)
	{
		return (ft_putstr_fd("-2147483648", fd));
	}
	else
	{
		return (ft_putnbr(n, fd));
	}
}
