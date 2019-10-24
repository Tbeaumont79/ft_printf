/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thbeaumo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/20 18:19:33 by thbeaumo          #+#    #+#             */
/*   Updated: 2019/10/24 16:13:06 by thbeaumo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft/libft.h"

int		ft_parse(va_list ap, t_struct *datas, const char *s)
{
	size_t		i;
	size_t		j;
	size_t		k;
	static char *conv= "s"; //ect
//malloc data dans main
	i = 0;
	j = 0;
	k = 0;
	if (!(datas->buf = (char *)malloc(sizeof(char) * (ft_strlen(s) + 1))))
		return (0);
	while (s[k])
	{
		if (s[k] == '%')
		{
			while (conv[j])
			{
				if (conv[j] == s[k + 1])
					i += ft_dispatcher(ap, datas);
				j++;
			}
			k++;
		}
		datas->buf[i++] = s[k++];
	}
	printf("THE ENND !!\n");
	ft_putstr(datas->buf);
	return (0);
}
