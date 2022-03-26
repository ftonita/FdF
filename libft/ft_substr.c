/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ftonita <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/02 00:15:21 by ftonita           #+#    #+#             */
/*   Updated: 2021/11/02 00:15:22 by ftonita          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char			*str;
	size_t			l;
	size_t			sl;
	unsigned int	i;

	if (!s)
		return (0);
	sl = ft_strlen(s);
	if (sl + 1 <= start)
		l = 0;
	else
	{
		if (len > sl + 1 - start)
			l = sl + 1 - start;
		else
			l = len;
	}
	str = (char *)malloc((l + 1) * sizeof(char));
	if (!str)
		return (0);
	i = 0;
	while (i++ < l)
		str[i - 1] = s[start + i - 1];
	str[i - 1] = 0;
	return (str);
}
