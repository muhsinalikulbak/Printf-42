/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkulbak <mkulbak@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/09 02:02:19 by mkulbak           #+#    #+#             */
/*   Updated: 2024/11/11 18:06:50 by mkulbak          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	args_check(va_list args, char type)
{
	unsigned long	ptr;

	if (type == 's')
		return (ft_putstr(va_arg(args, char *)));
	if (type == 'c')
		return (ft_putchar(va_arg(args, int)));
	if (type == '%')
		return (ft_putchar('%'));
	if (type == 'i' || type == 'd')
		return (int_print(va_arg(args, int)));
	if (type == 'u')
		return (convert_to_base(va_arg(args, unsigned int),
				"0123456789", 0));
	if (type == 'x' || type == 'X')
		return (convert_to_base(va_arg(args, unsigned int), "", type));
	if (type == 'p')
	{
		ptr = va_arg(args, unsigned long);
		if (!ptr)
			return (ft_putstr("(nil)"));
		ft_putstr("0x");
		return (convert_to_base(ptr, "0123456789abcdef", 0) + 2);
	}
	return (0);
}

int	ft_printf(const char *format, ...)
{
	int		count;
	va_list	args;

	count = 0;
	va_start(args, format);
	while (*format)
	{
		if (*format != '%')
		{
			count += write(1, format, 1);
		}
		else if (*(format + 1))
		{
			count += args_check(args, *(format + 1));
			format++;
		}
		format++;
	}
	va_end(args);
	return (count);
}
