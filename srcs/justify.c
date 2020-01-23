/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   justify.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thbeaumo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/02 17:18:48 by thbeaumo          #+#    #+#             */
/*   Updated: 2020/01/23 14:28:00 by thbeaumo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Libft/libft.h"
#include "../headers/ft_printf.h"

t_struct     fill_if_prec(t_struct datas, int len_arg, int prec_len)
{
	while (datas.flag[size] - len_arg > 0 && datas.flag[size] - len_arg > prec_len)
	{
		datas = ft_buffer(' ', datas);
		datas.flag[size]--;
	}
	if (datas.flag[neg] == 0)
	{
		datas = ft_buffer('-', datas);
		datas.flag[neg] = 1;
	}
	while (prec_len > 0)
	{
		datas = ft_buffer('0', datas);
		prec_len--;
	}
	return (datas);
}

t_struct		fill_with_char(char c, t_struct datas, int final_length)
{
	int j;
	int tmp;

	j = 0;
	tmp = final_length; // probleme quand datas.size == 1 !
	// pour le moment je mets 0 par supposition mais besoin de faire plus de test !
	while (j < final_length)
	{
		datas = ft_buffer(c, datas);
		j++;
	}
	return (datas);
}

static int		ft_get_final_length(int len_arg, t_struct datas)
{
	return (len_arg > datas.flag[size] ? 
			0 : (datas.flag[size] - len_arg));
}

t_struct	ft_left_justify(t_struct datas, int len_arg)
{
	int final_length;
	int prec_len;

	prec_len = datas.flag[size_prec] > len_arg ? datas.flag[size_prec] - len_arg : 0;
	final_length = ft_get_final_length(len_arg, datas);
	if (datas.flag[flags] == '0')
	{
		if (datas.flag[prec] == '.')
			datas = fill_if_prec(datas, len_arg, prec_len);
		else
			datas = fill_with_char('0', datas, final_length);
	}
	else
	{
		if (datas.flag[prec] == '.')
			datas = fill_if_prec(datas, len_arg, prec_len);
		else
			datas = fill_with_char(' ', datas, final_length);
	}
	return (datas);
}

t_struct	ft_right_justify(t_struct datas, int len_arg, int prec_len)
{
	int final_length;
	int sizes;

	final_length = ft_get_final_length(len_arg, datas);
	sizes = (prec_len > 0 ? final_length - prec_len : final_length);
	if (datas.flag[flags] == '-')
	{
		datas = fill_with_char(' ', datas, sizes);
	}
	return (datas);
}
