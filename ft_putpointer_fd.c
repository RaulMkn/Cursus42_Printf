/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putpointer_fd.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmakende <rmakende@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/28 16:47:54 by rmakende          #+#    #+#             */
/*   Updated: 2024/06/12 18:17:26 by rmakende         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static char	digit_to_hex(int digit)
{
	if (digit < 10)
		return ('0' + digit);
	else
		return ('a' + (digit - 10));
}

static char	*assign_buffer(char *buffer)
{
	buffer[0] = '0';
	buffer[1] = 'x';
	buffer += 2;
	return (buffer);
}

static void	address_to_hex(char *buffer, void *ptr)
{
	unsigned long	addr;
	int				i;
	int				leading_zero;
	char			hex_digit;

	leading_zero = 1;
	addr = (unsigned long)ptr;
	i = (sizeof(addr) * 2) - 1;
	buffer = assign_buffer(buffer);
	while (i >= 0)
	{
		hex_digit = digit_to_hex((addr >> (i * 4)) & 0xF);
		if (hex_digit != '0' || !leading_zero)
		{
			*buffer++ = hex_digit;
			leading_zero = 0;
		}
		i--;
	}
	*buffer = '\0';
	if (leading_zero)
	{
		buffer[0] = '0';
		buffer[1] = '\0';
	}
}

static int	ft_putpointer_fd(void *ptr, int fd)
{
	char	buffer[2 + sizeof(ptr) * 2 + 1];

	if (ptr == NULL)
		return (ft_putstr_fd("(nil)", fd));
	address_to_hex(buffer, ptr);
	return (ft_putstr_fd(buffer, fd));
}
