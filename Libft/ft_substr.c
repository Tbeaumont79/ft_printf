/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thbeaumo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/10 14:02:03 by thbeaumo          #+#    #+#             */
/*   Updated: 2019/10/17 19:03:49 by thbeaumo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	i;
	size_t	slen;
	char	*ptr;

	if (!s || start < 0)
		return (0);
	slen = ft_strlen(s);
	i = 0;
	if (start >= slen)
		len = 0;
	else
		len = slen - start < len ? slen - start : len;
	if (!(ptr = (char *)malloc(len + 1)))
		return (0);
	while (len)
	{
		ptr[i] = s[start];
		i++;
		start++;
		len--;
	}
	ptr[i] = '\0';
	return (ptr);
}
