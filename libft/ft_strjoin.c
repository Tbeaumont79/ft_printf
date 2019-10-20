/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thbeaumo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/14 13:14:30 by thbeaumo          #+#    #+#             */
/*   Updated: 2019/10/17 10:55:59 by thbeaumo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char *s2)
{
	int		i;
	int		j;
	char	*tab;
	int		count;

	i = 0;
	j = 0;
	count = 0;
	if (!s1 || !s2)
		return (0);
	if (!(tab = (char*)malloc(sizeof(char) *
		((ft_strlen(s1) + ft_strlen((char const *)s2)) + 1))))
		return (0);
	while (s1[i])
		tab[count++] = s1[i++];
	while (s2[j])
		tab[count++] = s2[j++];
	tab[count] = '\0';
	return (tab);
}
