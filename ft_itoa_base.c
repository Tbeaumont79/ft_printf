/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thbeaumo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/20 16:54:19 by thbeaumo          #+#    #+#             */
/*   Updated: 2019/10/20 18:11:31 by thbeaumo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_itoa_base(long long nb, int base)
{
	long long nbr;
	char *str;
	char *tab;
	int	size;
	int lim;

	tab = "0123456789ABCDEF";
	lim = 0;
	nbr = (long long)nb;
	size = nb_len(nbr, base);
	if (base < 2 || base > 16)
		return (0);
	if (!(str = (char *)malloc(sizeof(char) * (size + 1))))
		return (0);
	str[size] = '\0';
	if (nb < 0 && base == 10)
	{
		str[0] = '-';
		ft_abs(nb);
		lim = 1;
	}
	while (size > lim)
	{
		size--;
		str[size] = tab[nb % base];
		nb = nb / base;
	}
	return (str);
}
