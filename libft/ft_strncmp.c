/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ftonita <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/02 00:13:56 by ftonita           #+#    #+#             */
/*   Updated: 2021/11/02 00:13:57 by ftonita          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	while (n--)
	{
		if (*s1 == '\0' && *s2 == '\0')
			return (0);
		if (*s1++ != *s2++)
		{
			s1--;
			s2--;
			return ((unsigned char)*s1 - (unsigned char)*s2);
		}
	}
	return (0);
}
