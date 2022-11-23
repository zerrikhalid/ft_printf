/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kzerri <kzerri@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/21 13:40:45 by kzerri            #+#    #+#             */
/*   Updated: 2022/11/24 00:13:12 by kzerri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# define HEX_LOW "0123456789abcdef"
# define HEX_UPP "0123456789ABCDEF"
# define UNS_LL unsigned long long
# define BASE &"0123456789abcdef"
# define DIGITS "0123456789"

# include <stdio.h>
# include <stdarg.h>
# include <unistd.h>
# include <limits.h>
# include <stdlib.h>

char	*ft_strchr(const char *s, int c);
int		ft_printf(const char *str, ...);
int		get_printed(const char fs, va_list arg);
int		ft_putchar(char c);
int		ft_putstr(char *s);
int		ft_put_ptr(UNS_LL data);
int		ft_putnbr_base(long long data, char *bs, char fs);
int		ft_put_unsigned(unsigned int data);

#endif