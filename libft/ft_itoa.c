/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ftonita <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/02 00:16:00 by ftonita           #+#    #+#             */
/*   Updated: 2021/11/02 00:16:01 by ftonita          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*ft_mitoa(long int n, int i, char *s)
{
	s[i] = '\0';
	if (n > 0)
	{
		while (i != 0)
		{
			s[i - 1] = n % 10 + 48;
			n = n / 10;
			i--;
		}
	}
	else if (n == 0)
		s[0] = '0';
	else
	{
		while (i != 0)
		{
			s[i - 1] = -(n % 10) + '0';
			n = n / 10;
			i--;
		}
		s[0] = '-';
	}
	return (s);
}

int	ft_len(long int n)
{
	int	i;

	i = 0;
	if (n == 0)
		return (1);
	if (n < 0)
		i++;
	while (n != 0)
	{
		i++;
		n = n / 10;
	}
	return (i);
}

char	*ft_itoa(int n)
{
	char		*a;
	int			i;
	long int	c;

	c = (long)n;
	i = ft_len(n);
	a = (char *)malloc((i + 1) * sizeof(char));
	if (!a)
		return (NULL);
	a = ft_mitoa(c, i, a);
	return (a);
}
