/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thbeaumo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/11 15:58:39 by thbeaumo          #+#    #+#             */
/*   Updated: 2019/10/18 16:56:14 by thbeaumo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		ft_countword(const char *str, char c)
{
	int i;
	int word;

	i = 0;
	word = 0;
	if (*str && str[i] != c)
	{
		word++;
		i++;
	}
	if (*str)
		i++;
	while (str[i])
	{
		if (str[i - 1] == c && str[i] != c)
			word++;
		i++;
	}
	return (word);
}

static int		l(const char *s, char c, int i)
{
	int len;

	len = 0;
	while (*s && s[i] && s[i] != c)
	{
		len++;
		i++;
	}
	return (len);
}

static void		*ft_free(char **s, int k)
{
	while (k >= 0)
		free(s[k--]);
	free(s);
	return (NULL);
}

char			**ft_split(char const *s, char c)
{
	int		i;
	int		j;
	int		k;
	char	**tab;

	i = 0;
	k = 0;
	if (!s)
		return (0);
	if (!(tab = (char **)malloc(sizeof(char*) * (ft_countword(s, c) + 1))))
		return (0);
	while (k < ft_countword(s, c))
	{
		j = 0;
		while (s[i] && s[i] == c)
			i++;
		if (!(tab[k] = (char *)malloc(sizeof(char) * (l(s, c, i) + 1))))
			return (ft_free(tab, k));
		while (s[i] && s[i] != c)
			tab[k][j++] = s[i++];
		tab[k++][j] = '\0';
	}
	tab[k] = 0;
	return (tab);
}
