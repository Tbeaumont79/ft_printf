/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   justify.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thbeaumo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/02 17:18:48 by thbeaumo          #+#    #+#             */
/*   Updated: 2020/01/03 15:09:58 by thbeaumo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft/libft.h"

static void		fill_with_char(char c, t_struct datas, int final_length)
{
	int j;
    int prec_len;

	j = 0;
    prec_len = (datas.flag[size_prec] -  datas.flag[size]) + final_length;
    printf("prec_len :: %d\n", prec_len);
	while (j < final_length)
	{
        if (prec_len > 0)
        {
            while (final_length - prec_len != j)
            {
                ft_buffer(' ', datas);
                j++;
            }
        }
        if (c == '0')
		    ft_buffer(c, datas);
        else
            ft_buffer(' ', datas);
		j++;
        prec_len--;
	}
}

static int		ft_get_final_length(int len_arg, t_struct datas)
{
	return (len_arg > datas.flag[size] ? 
			len_arg - datas.flag[size] : (datas.flag[size] - len_arg));
}

void	ft_left_justify(t_struct datas, int len_arg)
{
	int final_length;

	final_length = ft_get_final_length(len_arg, datas);
	if (datas.flag[flags] == '0')
		fill_with_char('0', datas, final_length);
	else
		fill_with_char(' ', datas, final_length);
}

void	ft_right_justify(t_struct datas, int len_arg)
{
	int final_length;

	final_length = ft_get_final_length(len_arg, datas);
	if (datas.flag[flags] == '-')
		fill_with_char(' ', datas, final_length);
}
