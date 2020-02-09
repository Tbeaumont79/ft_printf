/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thbeaumo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/14 10:36:01 by thbeaumo          #+#    #+#             */
/*   Updated: 2019/10/17 15:20:42 by thbeaumo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_get_size(char const *s1, char const *set)
{
	int len;
	int slen;
	int i;

	i = 0;
	len = 0;
	slen = ft_strlen(s1);
	while (i < slen && ft_strchr(set, s1[i]))
	{
		i++;
		len++;
	}
	i = slen - 1;
	while (i >= 0 && ft_strchr(set, s1[i]))
	{
		i--;
		len++;
	}
	if (slen < len)
		return (len - slen);
	return (slen - len);
}

char		*ft_strtrim(char const *s1, char const *set)
{
	char	*tab;
	size_t	i;
	int		size;

	i = 0;
	if (!s1 || !set)
		return (0);
	size = ft_get_size(s1, set);
	if (!(tab = (char *)malloc(sizeof(char) * (size + 1))))
		return (0);
	while (i < ft_strlen(s1) && ft_strchr(set, s1[i]))
		i++;
	ft_strlcpy(tab, &s1[i], size + 1);
	return (tab);
}
