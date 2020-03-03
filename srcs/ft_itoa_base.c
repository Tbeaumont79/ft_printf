/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thbeaumo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/20 16:54:19 by thbeaumo          #+#    #+#             */
/*   Updated: 2020/02/13 14:18:14 by thbeaumo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/ft_printf.h"
#include "../Libft/libft.h"

char	*final_itoa_result(char *tab, long nb, int sizes, int base)
{
	char *str;

	if (!(str = (char *)malloc(sizeof(char) * (sizes + 1))))
		return (0);
	if (sizes == 0)
	{
		str[0] = '\0';
		free(str);
		return (str);
	}
	if (sizes > 0)
	{
		str[sizes] = '\0';
		while (sizes > 0)
		{
			sizes--;
			str[sizes] = tab[nb % base];
			nb = nb / base;
		}
	}
	return (str);
}

char	*ft_itoa_base(t_struct datas, long nb, int base)
{
	long long	nbr;
	char		*tab;
	int			sizes;

	tab = "0123456789ABCDEF";
	nbr = (long)nb;
	datas.flag[size] = (datas.flag[size] < 0 ? 0
			: datas.flag[size]);
	datas.flag[size_prec] = (datas.flag[size_prec] < 0 ? 0
			: datas.flag[size_prec]);
	sizes = nb_len(nbr, base);
	if (base < 2 || base > 16)
		return (0);
	return (final_itoa_result(tab, nbr, sizes, base));
}
