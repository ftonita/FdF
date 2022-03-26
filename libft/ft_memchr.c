/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ftonita <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/02 00:14:06 by ftonita           #+#    #+#             */
/*   Updated: 2021/11/02 00:14:08 by ftonita          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t	i;
	char	*d;

	d = (char *)s;
	i = 0;
	while (i < n)
	{
		if (d[i] == (char)c)
			return ((void *)&d[i]);
		i++;
	}
	return (NULL);
}
