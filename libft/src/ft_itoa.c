/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alubrano <alubrano@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/05 16:50:23 by alubrano          #+#    #+#             */
/*   Updated: 2025/12/19 13:14:20 by alubrano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*ft_autofill(char *result, long int ln, int sign, int total)
{
	result[total] = '\0';
	if (sign == 1)
		result[0] = '-';
	total -= 1;
	while (total >= sign)
	{
		result[total] = '0' + ln % 10;
		ln /= 10;
		total --;
	}
	return (result);
}

static int	ft_counter(long int ln)
{
	int	i;

	i = 0;
	while (ln != 0)
	{
		ln /= 10;
		i++;
	}
	return (i);
}

char	*ft_itoa(int n)
{
	char		*result;
	int			i;
	int			total;
	int			sign;
	long int	ln;

	sign = 0;
	ln = (long)n;
	i = 0;
	if (ln == 0)
		i = 1;
	if (ln < 0)
	{
		sign = 1;
		ln = -ln;
	}
	if (i == 0)
		i = ft_counter(ln);
	total = i + sign;
	result = malloc(sizeof(char) * (total + 1));
	if (result == NULL)
		return (NULL);
	return (result = ft_autofill(result, ln, sign, total));
}
