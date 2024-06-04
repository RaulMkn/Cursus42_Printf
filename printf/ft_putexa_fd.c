/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putexa_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmakende <rmakende@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/29 23:11:25 by rmakende          #+#    #+#             */
/*   Updated: 2024/05/30 19:32:18 by rmakende         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putexa_fd(unsigned int num, int fd, char c)
{
	const char	*hex_digits = "0123456789abcdef";
	char		buffer[9];
	int			i;

	buffer[8] = '\0';
	i = 7;
	while (i >= 0)
	{
		buffer[i] = hex_digits[num % 16];
		num /= 16;
		i--;
	}
	i = 0;
	while (buffer[i])
	{
		if (c == 'x')
			buffer[i] = ft_tolower(buffer[i]);
		else if (c == 'X')
			buffer[i] = ft_toupper(buffer[i]);
		i++;
	}
	ft_putstr_fd(buffer, fd);
}
