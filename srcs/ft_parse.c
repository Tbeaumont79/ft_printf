/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thbeaumo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/20 18:19:33 by thbeaumo          #+#    #+#             */
/*   Updated: 2020/02/06 17:08:10 by thbeaumo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "../Libft/libft.h"
#include "../headers/ft_printf.h"


// checker aussi la precision !
/*
static int ft_get_int(t_struct datas, const char *s, int i)
{
	int nb;
    static int preci = 0;

	nb = 0;
    if (datas.flag[prec] == '.')
        preci++;
	if (ft_isdigit(s[i]))
	{
		nb = nb * 10 + ft_atoi(&s[i]);
		while (ft_isdigit(s[i]))
			i++;
	}
    if (preci == 1)
        datas.flag[size_prec] = nb;
    else
        datas.flag[size] = nb;
	return (i);
}

static int ft_get_flag(t_struct datas, const char *s, int i)
{
	static char flag[4] = {'-', '0', '.', '*'};
	int j;
	int tmp;
	int size_of_flag_array;

	j = 0;
	tmp = 0;
	size_of_flag_array = ft_strlen(flag);
	while (s[tmp])
    {
        if (s[tmp] == '.' && ft_isdigit(s[tmp + 1]))
        {
            datas.flag[prec] = s[tmp];
            i = ft_get_int(datas, s, tmp + 1);
        }
		tmp++;
    }
	while (j < size_of_flag_array && s[i + 1] != flag[j])
		j++;
    if (s[i + 1] == flag[j] && !ft_isdigit(s[i + 2]))
	{
		datas.flag[flags] = flag[j];
		i++;
	}
    if (s[i + 1] == flag[j] && ft_isdigit(s[i + 2]))
    {
        printf("je passe ici");
	    i = ft_get_int(datas, s, i + 2);
    }
    else
        return (-1);
    return (i);
}
*/
t_struct is_conv(t_struct datas, int i, const char *s)
{
    static char conve[8] = {'x', 'X', 'd', 'i', 'c', 's', '%', 'u'};
    int j;
    int len;

    len = ft_strlen(conve);
    while (s[i])
    {
        j = 0;
        while (j < len)
        {
            if (conve[j] == s[i])
            {
                datas.flag[conv] = conve[j];
                break ;
            }
            j++;
        }
        i++;
    }
    return (datas);
}
int ft_parse(va_list ap, t_struct datas, const char *s)
{
	int i;
	int val;
	int j;
	int tmp;

	j = 0;
	i = 0;
	val = 0;
	ft_bzero(datas.buf, ft_strlen(s) + 1);
	while (s[i])
	{
		if (s[i] && s[i] != '%')
			datas = ft_buffer(s[i], datas);
		if (s[i] == '%')
		{
			tmp = i + 1;
			datas = is_conv(datas, tmp, s);
            datas.flag[temp] = i;
            datas = get_flag(ap, datas, s, i);
            i = s[datas.flag[temp]] ? datas.flag[temp] : i;
            datas = ft_dispatcher(ap, datas, i, s);
		}
		i++;
	}
	return (datas.buf_index);
}
