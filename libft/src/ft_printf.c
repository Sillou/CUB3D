/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alubrano <alubrano@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/23 16:23:58 by alubrano          #+#    #+#             */
/*   Updated: 2025/12/19 13:15:03 by alubrano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_convertion(va_list vargs, const char type)
{
	int	len;

	len = 0;
	if (type == 'c')
		len += ft_int_putchar(va_arg(vargs, int));
	else if (type == 's')
		len += ft_int_putstr(va_arg(vargs, char *));
	else if (type == 'p')
		len += ft_int_putptr((uintptr_t)va_arg(vargs, void *));
	else if ((type == 'd') || (type == 'i'))
		len += ft_ll_putnbr(va_arg(vargs, int));
	else if (type == 'u')
		len += ft_ll_putnbr(va_arg(vargs, unsigned int));
	else if ((type == 'x') || (type == 'X'))
		len += ft_putnbr_base(va_arg(vargs, unsigned int), type);
	else if (type == '%')
		len += ft_int_putchar('%');
	return (len);
}

int	ft_printf(const char *str, ...)
{
	va_list	vargs;
	int		len;
	int		i;

	va_start(vargs, str);
	len = 0;
	i = 0;
	while (str[i])
	{
		if (str[i] == '%')
		{
			if (str[i + 1] != '\0')
			{
				len += ft_convertion(vargs, str[i + 1]);
				i++;
			}
			else
				break ;
		}
		else
			len += ft_int_putchar(str[i]);
		i++;
	}
	va_end (vargs);
	return (len);
}

char	*ft_print_autofill(char *result, long int ln, int sign, int total)
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

int	ft_int_putchar(int c)
{
	if (write(1, &c, 1) == -1)
		return (-1);
	return (1);
}

int	ft_int_putstr(char *str)
{
	int	i;

	i = 0;
	if (str == NULL)
	{
		write(1, "(null)", 6);
		return (6);
	}
	while (str[i])
	{
		write(1, &str[i], 1);
		i++;
	}
	return (i);
}
