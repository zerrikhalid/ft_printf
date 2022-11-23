/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utiles.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kzerri <kzerri@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/21 13:41:30 by kzerri            #+#    #+#             */
/*   Updated: 2022/11/23 23:47:53 by kzerri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putchar(char c)
{
	return (write(1, &c, 1));
}

int	ft_putstr(char *s)
{
	int	i;

	i = 0;
	if (!s)
		return (ft_putstr("(null)"));
	while (*s)
	{
		i += ft_putchar(*s);
		s++;
	}
	return (i);
}

int	ft_put_ptr(UNS_LL data)
{
	int	printed;

	printed = 0;
	if (data > 15)
	{
		printed += ft_put_ptr(data / 16);
		printed += write(1, BASE[data % 16], 1);
		return (printed);
	}
	return (write(1, BASE[data % 16], 1));
}

int	ft_putnbr_base(long long data, char *bs, char fs)
{
	int	printed;
	int	base;

	printed = 0;
	if (fs == 'd' || fs == 'i')
		base = 10;
	else
		base = 16;
	if (data < 0)
	{
		printed += write(1, "-", 1);
		data *= (-1);
	}
	if (data >= base)
	{
		printed += ft_putnbr_base(data / base, bs, fs);
		printed += write(1, &bs[data % base], 1);
		return (printed);
	}
	return (write(1, &bs[data % base], 1) + printed);
}

int	ft_put_unsigned(unsigned int data)
{
	int	printed;

	printed = 0;
	if (data > 9)
	{
		printed += ft_put_unsigned(data / 10);
		printed += ft_putchar((data % 10) + '0');
		return (printed);
	}
	return (ft_putchar((data % 10) + '0'));
}
