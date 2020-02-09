/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_int.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thbeaumo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/02 17:18:24 by thbeaumo          #+#    #+#             */
/*   Updated: 2020/02/09 15:37:58 by thbeaumo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Libft/libft.h"
#include "../headers/ft_printf.h"

t_struct	get_int(t_struct datas, int tmp, const char *s)
{
	int nb;
	int preci;

	nb = 0;
	preci = 0;
	if (datas.flag[prec] == '.' && s[tmp - 1] == '.')
		preci = 1;
	if (ft_isdigit(s[tmp]))
	{
		nb = nb * 10 + ft_atoi(&s[tmp]);
		while (ft_isdigit(s[tmp]))
		{
			datas.flag[temp]++;
			tmp++;
		}
	}
	if (preci == 1)
		datas.flag[size_prec] = nb;
	else
		datas.flag[size] = nb;
	return (datas);
}
