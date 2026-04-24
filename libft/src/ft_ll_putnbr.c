/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ll_putnbr.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alubrano <alubrano@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/19 12:29:36 by alubrano          #+#    #+#             */
/*   Updated: 2025/12/19 12:55:44 by alubrano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_ll_putnbr(long long n)
{
	int		len;
	char	*c;

	len = 0;
	c = ft_ll_itoa(n);
	len = ft_int_putstr(c);
	free(c);
	return (len);
}
