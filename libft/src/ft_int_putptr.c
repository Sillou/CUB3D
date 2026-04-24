/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putptr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alubrano <alubrano@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/19 12:33:22 by alubrano          #+#    #+#             */
/*   Updated: 2025/12/19 13:00:48 by alubrano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_int_putptr(uintptr_t ptr)
{
	int	len;
	int	c;

	len = 0;
	c = 0;
	if (!ptr)
	{
		c = ft_int_putstr("(nil)");
		return (c);
	}
	c = ft_int_putstr("0x");
	if (c == -1)
		return (-1);
	len += c;
	c = ft_putnbr_base(ptr, 'x');
	if (c == -1)
		return (-1);
	len += c;
	return (len);
}
