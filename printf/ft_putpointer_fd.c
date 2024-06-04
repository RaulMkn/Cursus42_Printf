/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putpointer_fd.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmakende <rmakende@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/28 16:47:54 by rmakende          #+#    #+#             */
/*   Updated: 2024/05/30 19:52:52 by rmakende         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	digit_to_hex(int digit)
{
	if (digit < 10)
		return ('0' + digit);
	else
		return ('a' + (digit - 10));
}

void	ft_putpointer_fd(void *ptr, int fd)
{
	unsigned long		addr;
	char				buffer[2 + sizeof(addr) * 2 + 1];
	char				*buf_ptr;
	int					i;
	char				*p;

	buf_ptr = buffer;
	*buf_ptr++ = '0';
	*buf_ptr++ = 'x';
	buf_ptr = buffer;
	addr = (unsigned long)ptr;
	i = (sizeof(addr) * 2) - 1;
	while (i >= 0)
	{
		*buf_ptr++ = digit_to_hex((addr >> (i * 4)) & 0xF);
		i--;
	}
	*buf_ptr = '\0';
	p = buffer;
	while (*p != '\0')
	{
		ft_putchar_fd(*p, fd);
		p++;
	}
	ft_putchar_fd('\n', fd);
}
