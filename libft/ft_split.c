/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ftonita <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/02 00:15:47 by ftonita           #+#    #+#             */
/*   Updated: 2021/11/02 00:15:49 by ftonita          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	int	ft_count_word(const char *s, int c)
{
	int	k;
	int	i;

	k = 0;
	i = 0;
	while (s[i])
	{
		if (s[i] != c && (s[i + 1] == c || s[i + 1] == '\0'))
			k++;
		i++;
	}
	return (k);
}

static int	ft_wlen(const char *s, char c)
{
	int	b;

	b = 0;
	while (s[b] != c && s[b])
		b++;
	return (b);
}

static char	**ft_msplit(char const *s, char c, int i, char **a)
{
	size_t	j;

	j = 0;
	while (s[i])
	{
		a[j] = (char *)malloc((ft_wlen(s + i, c) + 1) * sizeof(char));
		if (!a[j])
		{
			while (*(a + j))
				free(a[j--]);
			free(a);
			return (NULL);
		}
		ft_bzero(a[j], ft_wlen(s + i, c) + 1);
		ft_strlcat(a[j], s + i, (size_t)ft_wlen(s + i, c) + 1);
		j++;
		i += ft_wlen(s + i, c);
		while (s[i] && s[i] == c && c != '\0')
			i++;
	}
	a[j] = (0);
	return (a);
}

char	**ft_split(char const *s, char c)
{
	char	**a;
	int		i;

	if (!s)
		return (NULL);
	a = (char **)malloc(sizeof(char *) * (ft_count_word(s, c) + 1));
	if (!a)
		return (0);
	i = 0;
	while (s[i] && s[i] == c && c != '\0')
		i++;
	return (ft_msplit(s, c, i, a));
}
