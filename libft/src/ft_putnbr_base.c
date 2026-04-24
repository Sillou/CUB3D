/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alubrano <alubrano@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/19 12:32:06 by alubrano          #+#    #+#             */
/*   Updated: 2025/12/19 12:56:52 by alubrano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_putnbr_base(unsigned long long n, char type)
{
	int			len;
	char		pos;
	int			c;
	const char	*decimal;

	len = 0;
	if (type == 'X')
		decimal = "0123456789ABCDEF";
	else
		decimal = "0123456789abcdef";
	if (n == 0)
		return (ft_int_putchar('0'));
	if (n >= 16)
	{
		c = ft_putnbr_base((n / 16), type);
		if (c == -1)
			return (-1);
		len += c;
	}
	pos = decimal[n % 16];
	if (write(1, &pos, 1) == -1)
		return (-1);
	len += 1;
	return (len);
}
