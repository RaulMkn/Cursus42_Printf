/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmakende <rmakende@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/27 17:13:18 by rmakende          #+#    #+#             */
/*   Updated: 2024/06/12 18:20:51 by rmakende         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <string.h>
# include <stdio.h>
# include <stddef.h>
# include <stdlib.h>
# include <stdarg.h>

int		ft_printf(char const *format, ...);
int		ft_putchar_fd(char c, int fd);
int		ft_putstr_fd(char *s, int fd);
int		ft_putnbr_fd(int n, int fd);
int		ft_putpointer_fd(void *ptr, int fd);
int		ft_putexa_fd(unsigned int num, int fd, char c);
int		ft_putunsigned_fd(unsigned int nb, int fd);

#endif