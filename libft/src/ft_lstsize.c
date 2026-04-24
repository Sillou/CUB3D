/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alubrano <alubrano@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/11 19:02:19 by alubrano          #+#    #+#             */
/*   Updated: 2025/10/12 13:20:53 by alubrano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_lstsize(t_list *lst)
{
	int		size;
	t_list	*tmp;

	tmp = lst;
	size = 0;
	if (!tmp)
		return (size);
	while (tmp != NULL)
	{
		tmp = tmp->next;
		size++;
	}
	return (size);
}
