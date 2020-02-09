/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dispatcher.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thbeaumo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/23 13:33:55 by thbeaumo          #+#    #+#             */
/*   Updated: 2020/02/09 18:44:00 by thbeaumo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Libft/libft.h"
#include "../headers/ft_printf.h"

t_struct	ft_disp(va_list ap, t_struct datas, int i, const char *s)
{
	static char		conve[9] = {'s', 'd', 'i', 'x', 'X', 'p', 'c', 'u', '%'};
	int				j;
	int				size;
	static t_struct	(*fct[9])(va_list, t_struct, int i, const char *s) =
	{pf_s, pf_d, pf_d, pf_x, pf_xu, pf_p, pf_c, pf_u, pf_pct};

	j = 0;
	size = ft_strlen(conve);
	while (j < size)
	{
		if (conve[j] == s[i])
		{
			datas.flag[conv] = conve[j];
			break ;
		}
		j++;
	}
	if (j >= 0 && j < size)
		return (fct[j](ap, datas, i, s));
	else
		datas.flag[temp]++;
	return (datas);
}
