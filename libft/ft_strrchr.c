/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ftonita <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/02 00:13:45 by ftonita           #+#    #+#             */
/*   Updated: 2021/11/02 00:13:46 by ftonita          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	char	*t;

	t = 0;
	if (*s == (unsigned char)c)
		t = (char *)s;
	while (*s++)
	{
		if (*s == (unsigned char)c)
			t = (char *)s;
	}
	return (t);
}
