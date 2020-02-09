/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thbeaumo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/10 15:54:54 by thbeaumo          #+#    #+#             */
/*   Updated: 2019/10/17 14:12:39 by thbeaumo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	nb_len(long int n)
{
	int size;

	size = 0;
	if (n < 0)
	{
		size++;
		n *= -1;
	}
	if (n == 0)
		size++;
	while (n > 0)
	{
		n = n / 10;
		size++;
	}
	return (size);
}

char		*ft_itoa(int n)
{
	int		size;
	char	*res;
	int		lim;
	long	nb;

	nb = (long)n;
	size = nb_len(n);
	lim = 0;
	if (!(res = (char *)malloc(sizeof(char) * (size + 1))))
		return (0);
	res[size] = '\0';
	if (nb < 0)
	{
		res[0] = '-';
		nb *= -1;
		lim = 1;
	}
	while (size > lim)
	{
		size--;
		res[size] = nb % 10 + 48;
		nb = nb / 10;
	}
	return (res);
}
