/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmakende <rmakende@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/28 14:19:36 by rmakende          #+#    #+#             */
/*   Updated: 2024/05/30 19:54:10 by rmakende         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	handle_c(va_list args, char c)
{
	if (c == 'c')
		return (ft_putchar_fd(va_arg(args, int), 1));
	else if (c == 's')
		return (ft_putstr_fd(va_arg(args, char *), 1));
	else if (c == 'p')
		return (ft_putpointer_fd(va_arg(args, void *), 1));
	else if (c == 'd' || c == 'i')
		return (ft_putnbr_fd(va_arg(args, int), 1));
	else if (c == 'u')
		return (ft_putchar_fd(va_arg(args, unsigned int), 1));
	else if (c == 'x' || c == 'X')
		return (ft_putexa_fd(va_arg(args, unsigned int), 1, c));
	else if (c == '%')
		return (ft_putchar_fd('%', 1));
	else
		return ;
}

int	ft_printf(char const *c, ...)
{
	int		i;
	int		count;
	va_list	args;

	i = 0;
	count = 0;
	va_start(args, c);
	while (c[i])
	{
		if (c[i] == '%')
		{
			handle_c(args, c[i + 1]);
			i++;
			count++;
		}
		else
		{
			ft_putchar_fd(c[i], 1);
			count++;
		}
		i++;
	}
	va_end(args);
	return (count);
}
