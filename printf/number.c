/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   number.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkulbak <mkulbak@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/09 02:02:29 by mkulbak           #+#    #+#             */
/*   Updated: 2024/11/11 18:14:12 by mkulbak          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	int_print(int num)
{
	if (num == -2147483648)
		return (ft_putstr("-2147483648"));
	else if (num < 0)
	{
		ft_putchar('-');
		num = -1 * num;
		return (convert_to_base(num, "0123456789", 0) + 1);
	}
	return (convert_to_base(num, "0123456789", 0));
}

int	convert_to_base(size_t num, char *base, char type)
{
	int		len;
	int		i;
	char	buff[50];

	if (num == 0)
		return (ft_putchar('0'));
	if (type == 'x')
		base = "0123456789abcdef";
	if (type == 'X')
		base = "0123456789ABCDEF";
	i = 50;
	len = ft_strlen(base);
	buff[--i] = '\0';
	while (num > 0)
	{
		buff[--i] = base[num % len];
		num /= len;
	}
	return (ft_putstr((buff + i)));
}
