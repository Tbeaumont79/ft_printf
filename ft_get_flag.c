/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_flag.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thbeaumo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/02 17:18:14 by thbeaumo          #+#    #+#             */
/*   Updated: 2020/01/02 17:18:19 by thbeaumo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft/libft.h"

int ft_get_flag(t_struct datas, const char *s, int i)
{
	static char flag[4] = {'-', '0', '.', '*'};
	int j;
	int size_of_flag_array;

	j = 0;
	size_of_flag_array = ft_strlen(flag);
	while (j < size_of_flag_array && s[i] != flag[j])
		j++;
	if (j == size_of_flag_array && ft_isdigit(s[i + 1]))
		return (ft_get_int(datas, s, i + 2));
	// le point correspond a une precision faire un traitement apart !
	if (j == size_of_flag_array && s[i] == flag[j])
		datas.flag[flags] = flag[j];
	else
		return (i + 1); 
	return (++i);
}
