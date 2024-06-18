/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putexa_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmakende <rmakende@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/29 23:11:25 by rmakende          #+#    #+#             */
/*   Updated: 2024/06/12 13:44:08 by rmakende         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putexa_fd(unsigned int num, int fd, char c)
{
	const char		*hex_digits_lower;
	const char		*hex_digits_upper;
	char			buffer[9];
	int				i;
	int				result;

	hex_digits_lower = "0123456789abcdef";
	hex_digits_upper = "0123456789ABCDEF";
	buffer[8] = '\0';
	i = 7;
	while (i >= 0)
	{
		if (c == 'x')
			buffer[i] = hex_digits_lower[num % 16];
		else if (c == 'X')
			buffer[i] = hex_digits_upper[num % 16];
		num /= 16;
		i--;
	}
	i = 0;
	while (buffer[i] == '0')
		i++;
	result = ft_putstr_fd(&buffer[i], fd);
	return (result);
}
