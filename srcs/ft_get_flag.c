/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_flag.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thbeaumo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/02 17:18:14 by thbeaumo          #+#    #+#             */
/*   Updated: 2020/01/20 12:43:25 by thbeaumo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Libft/libft.h"
#include "../headers/ft_printf.h"
// check if it get the good value !!
static t_struct check_for_size(va_list ap, t_struct datas, const char *s)
{
	datas = (s[datas.flag[temp]] == '*' ?
		   	datas = ft_width(ap, datas, s, datas.flag[temp]) : datas);
	if (ft_isdigit(s[datas.flag[temp]]) || (s[datas.flag[temp]] == '0' &&
			   	datas.flag[flags] == '0'))
		datas = get_int(datas, datas.flag[temp], s);
	datas.flag[size] = datas.flag[size] > 0 ? datas.flag[size] : 0;
	datas.flag[size_prec] = datas.flag[size_prec] > 0 ?
	   	datas.flag[size_prec] : 0;
	return (datas);
}

t_struct get_flag(va_list ap, t_struct datas, const char *s, int i)
{
	static char flagi[3] = {'0', '-'};
	int j;
	
	j = 0;
	datas.flag[temp] = i + 1;
	datas.flag[size] = 0;
	datas.flag[size_prec] = 0;
	if (s[datas.flag[temp]] == '0')
		datas.flag[flags] = s[datas.flag[temp]];
	datas = check_for_size(ap, datas, s);
	while (j < (int)ft_strlen(flagi) && flagi[j] != s[datas.flag[temp]])
		j++;
	datas.flag[flags] = (s[datas.flag[temp]] == flagi[j] ? s[datas.flag[temp]] : '\0');
	datas.flag[temp] += (s[datas.flag[temp]] == flagi[j] ? 1 : 0);
	datas = check_for_size(ap, datas, s);
	datas.flag[prec] = (s[datas.flag[temp]] == '.' ? '.' : '\0');
	datas.flag[temp] += (s[datas.flag[temp]] == '.' ? 1 : 0);
	datas = check_for_size(ap, datas, s);
	return (datas);
}
/*
t_struct get_flag(va_list ap, t_struct datas, const char *s, int i)
{
    static char flag[2] = {'-', '0'};
   	int j;
    int tmp;
    int size_of_flag_array;

    j = 0;
    tmp = 0;
    datas.flag[temp] = i;
    size_of_flag_array = ft_strlen(flag);
    while (s[tmp])
    {
		if (s[tmp] == '.')
            datas.flag[prec] = s[tmp];
        if (s[tmp] == '.' && ft_isdigit(s[tmp + 1]))
		{
            datas = get_int(datas, tmp + 1, s);
			datas.flag[temp]++;
		}
		if (s[tmp] == '.' && s[tmp + 1] == '*')
			datas.flag[temp]++;
		tmp++;
    }
    while (j < size_of_flag_array && s[i + 1] != flag[j])
        j++;
	if (s[i + 1] == flag[j] && s[i + 2] == '*')
	{
		datas.flag[flags] = flag[j];
		datas = ft_width(ap, datas, s, i + 2);
		if (s[i + 2] == '*')
			datas.flag[temp]++;	
		datas.flag[temp]++;
	}
	if (s[i + 1] == flag[j] && !ft_isdigit(s[i + 2]) && s[i + 2] != '*')
    {
        datas.flag[flags] = flag[j];
        datas.flag[temp]++;
    }
    if (s[i + 1] == flag[j] && ft_isdigit(s[i + 2]))
    {
        datas.flag[flags] = flag[j];
        datas = get_int(datas, i + 2, s);
    }
	if (s[i + 1] == '.' && s[i + 2] == '*')
		datas.flag[temp]++;
	if (s[i + 3] == '.' && s[i + 4] == '*')
		datas.flag[temp]++;
	if ((!datas.flag[flags] && !datas.flag[prec]) || s[datas.flag[temp]] == '*')
		datas.flag[temp]++;
	if (s[datas.flag[temp]] == '%')
		datas.flag[temp]++;
	return (datas);
}*/
// CHECK SI s[i + 1] == '.' et s[i + 2] == '*' check si s[i + 3] == '.' et s[i + 4] == '*' puis faire un max de test

//faire un check dans la boucle de decrementation si s[tmp] == '.' et que ft_isdigit[tmp + 1]
//alors prec == 1 et datas.flag[size_prec == get_int(datas, tmp + 1, s) ] et comme ca tu soustrait ca a la valeur des autres flag and its done
//
//
/*
 *     static char flag[4] = {'0', '-', '*', '.'};
 int i;
 int flag_len;

 i = 0;
 flag_len = ft_strlen(flag);
 while (s[tmp - 1] != '%')
 {
 if (s[tmp] == '.' || (s[tmp] == '.' && ft_isdigit(s[tmp + 1])))
 {
 datas.flag[prec] = s[tmp];
 datas = get_int(datas, tmp + 1, s);
 }
 tmp--;
 }
 while (i < flag_len && s[tmp] != flag[i])
 i++;
 if (s[tmp] == flag[i])
 datas.flag[flags] = flag[i];
 if (s[tmp] == flag[i] && ft_isdigit(s[tmp + 1]))
 datas = get_int(datas, tmp + 1, s);
 if (s[tmp] != flag[i] && ft_isdigit(s[tmp]))
 datas = get_int(datas, tmp + 1, s);
 return (datas);
 */
