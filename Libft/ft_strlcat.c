/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thbeaumo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/14 12:24:00 by thbeaumo          #+#    #+#             */
/*   Updated: 2019/10/17 10:53:49 by thbeaumo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*ft_strncat(char *s1, const char *s2, size_t n)
{
	size_t i;
	size_t j;

	i = 0;
	j = 0;
	while (s1[i])
		i++;
	while (s2[j] && j < n)
	{
		s1[i + j] = s2[j];
		j++;
	}
	s1[i + j] = '\0';
	return (s1);
}

size_t		ft_strlcat(char *dst, const char *src, size_t dst_size)
{
	size_t	src_len;
	size_t	dest_len;

	src_len = ft_strlen((char *)src);
	dest_len = ft_strlen(dst);
	if (dest_len >= dst_size)
		return (dst_size + src_len);
	ft_strncat(dst, src, dst_size - dest_len - 1);
	return (dest_len + src_len);
}
