/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thbeaumo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/11 14:14:09 by thbeaumo          #+#    #+#             */
/*   Updated: 2019/10/17 13:05:16 by thbeaumo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	needle_size;
	size_t	i;

	i = 0;
	needle_size = ft_strlen((char *)needle);
	if (!needle[i])
		return ((char *)haystack);
	while (haystack[i] && len >= needle_size)
	{
		if (!ft_memcmp(&haystack[i++], needle, needle_size))
			return ((char *)(&haystack[i - 1]));
		len--;
	}
	return (0);
}
