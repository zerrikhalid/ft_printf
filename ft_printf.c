/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kzerri <kzerri@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/21 13:41:22 by kzerri            #+#    #+#             */
/*   Updated: 2022/11/24 02:11:33 by kzerri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	get_printed(const char fs, va_list arg)
{
	int	printed;

	printed = 0;
	if (fs == 'c')
		printed += ft_putchar(va_arg(arg, int));
	else if (fs == 's')
		printed += ft_putstr(va_arg(arg, char *));
	else if (fs == 'p')
		printed += ft_putstr("0x") + ft_put_ptr(va_arg(arg, UNS_LL));
	else if (fs == 'd' || fs == 'i')
		printed += ft_putnbr_base(va_arg(arg, int), DIGITS, fs);
	else if (fs == 'u')
		printed += ft_put_unsigned(va_arg(arg, unsigned int));
	else if (fs == 'x')
		printed += ft_putnbr_base(va_arg(arg, unsigned int), HEX_LOW, fs);
	else if (fs == 'X')
		printed += ft_putnbr_base(va_arg(arg, unsigned int), HEX_UPP, fs);
	return (printed);
}

int	print_flags(const char fl, const char fs, va_list arg)
{
	int			printed;
	long long	nbr;

	printed = 0;
	if (fl == '#' && ft_strchr("xX", fs))
	{
		nbr = va_arg(arg, unsigned int);
		if (fs == 'x')
			return ((2 * (nbr && ft_putstr("0x")))
				+ ft_putnbr_base(nbr, HEX_LOW, fs));
		return ((2 * (nbr && ft_putstr("0X")))
			+ ft_putnbr_base(nbr, HEX_UPP, fs));
	}
	if (ft_strchr("id", fs) && ft_strchr(" +", fl))
	{
		nbr = va_arg(arg, int);
		if (nbr >= 0)
			printed += ft_putchar(fl);
		return (printed + ft_putnbr_base(nbr, DIGITS, fs));
	}
	return (get_printed(fs, arg));
}

int	ft_printf(const char *str, ...)
{
	int		printed;
	int		i;
	va_list	arg;

	printed = 0;
	i = 0;
	va_start(arg, str);
	while (str[i])
	{
		if (str[i] != '%')
			printed += write(1, &str[i], 1);
		else if (str[i] == '%' && str[i + 1] == '%')
			printed += write(1, &str[i++], 1);
		else if (str[i] == '%' && ft_strchr("# +", str[i + 1]))
		{
			printed += print_flags(str[i + 1], str[i + 2], arg);
			i += 2;
		}
		else if (str[i] == '%' && str[i + 1] != '%')
			printed += get_printed(str[++i], arg);
		i++;
	}
	return (printed);
}
