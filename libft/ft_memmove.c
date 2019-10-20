/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thbeaumo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/10 10:12:42 by thbeaumo          #+#    #+#             */
/*   Updated: 2019/10/19 14:46:36 by thbeaumo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	ft_cpy(char *dest, char *str, size_t len)
{
	size_t i;

	i = 0;
	if (dest < str)
	{
		while (i < len)
		{
			dest[i] = str[i];
			i++;
		}
	}
	else if (dest > str)
	{
		while (len)
		{
			dest[len - 1] = str[len - 1];
			len--;
		}
	}
}

void		*ft_memmove(void *dst, const void *src, size_t len)
{
	char		*dest;
	char		*str;

	dest = (char *)dst;
	str = (char *)src;
	ft_cpy(dest, str, len);
	return (dst);
}
