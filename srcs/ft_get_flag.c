/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_flag.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thbeaumo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/02 17:18:14 by thbeaumo          #+#    #+#             */
/*   Updated: 2020/02/09 15:07:02 by thbeaumo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Libft/libft.h"
#include "../headers/ft_printf.h"

static t_struct	check_for_size(va_list ap, t_struct datas, const char *s)
{
	datas = (s[datas.flag[temp]] == '*' ?
			datas = ft_width(ap, datas, s, datas.flag[temp]) : datas);
	if (ft_isdigit(s[datas.flag[temp]]) || (s[datas.flag[temp]] == '0' &&
				datas.flag[flags] == '0'))
		datas = get_int(datas, datas.flag[temp], s);
	return (datas);
}

t_struct		get_flag(va_list ap, t_struct datas, const char *s, int i)
{
	static char f[3] = {'0', '-'};
	int			j;

	j = 0;
	datas.flag[temp] = i + 1;
	datas.flag[size] = 0;
	datas.flag[size_prec] = 0;
	datas.flag[neg] = 0;
	while (j < (int)ft_strlen(f) && f[j] != s[datas.flag[temp]])
		j++;
	datas.flag[flags] = s[datas.flag[temp]] == f[j] ? s[datas.flag[temp]] : 0;
	if (datas.flag[flags] == '-' && s[datas.flag[temp] + 1] == '-')
		datas.flag[temp] += 2;
	datas = check_for_size(ap, datas, s);
	j = 0;
	while (j < (int)ft_strlen(f) && f[j] != s[datas.flag[temp]])
		j++;
	datas.flag[flags] = (s[datas.flag[temp]] == f[j] ?
			s[datas.flag[temp]] : datas.flag[flags]);
	datas.flag[temp] += (s[datas.flag[temp]] == f[j] ? 1 : 0);
	datas = check_for_size(ap, datas, s);
	datas.flag[prec] = (s[datas.flag[temp]] == '.' ? '.' : '\0');
	datas.flag[temp] += (s[datas.flag[temp]] == '.' ? 1 : 0);
	datas = check_for_size(ap, datas, s);
	return (datas);
}
