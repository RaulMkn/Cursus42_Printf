/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmakende <rmakende@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/02 14:36:22 by rmakende          #+#    #+#             */
/*   Updated: 2024/06/12 13:41:49 by rmakende         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putstr_fd(char *s, int fd)
{
	int		i;
	int		j;
	int		result;

	i = 0;
	j = 0;
	while (s[i] != '\0')
	{
		result = ft_putchar_fd(s[i], fd);
		if (result == -1)
		{
			return (-1);
		}
		j += result;
		i++;
	}
	return (j);
}
