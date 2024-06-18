/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putunsigned_fd.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmakende <rmakende@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/02 14:43:11 by rmakende          #+#    #+#             */
/*   Updated: 2024/06/12 18:23:33 by rmakende         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putunsigned_fd(unsigned int n, int fd)
{
	char	str[10];
	int		i;
	int		result;

	if (n == 0)
	{
		return (ft_putchar_fd('0', fd));
	}
	i = 0;
	while (n != 0)
	{
		str[i++] = (n % 10) + '0';
		n /= 10;
	}
	result = 0;
	while (i > 0)
	{
		result += ft_putchar_fd(str[--i], fd);
	}
	return (result);
}
