/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thbeaumo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/20 18:19:33 by thbeaumo          #+#    #+#             */
/*   Updated: 2019/11/08 14:08:37 by bod              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft/libft.h"

int		ft_parse(va_list ap, t_struct datas, const char *s)
{
	int i;
	int tmp;
	int j;

	j = 0;
	tmp = 0;
	i = 0;
	if (!(datas.str = (char *)malloc(sizeof(char) * (ft_strlen(s) + 1))))
		return (0);
	while (s[i])
	{
		if (s[i] == '%')
		{
			tmp = ft_dispatcher(ap, datas, i);
			i = i + 1;
			//probleme avec le i dans certains cas voir comment ne pas recrire la string
		}
		else
		{
			// analyse tmp en fonction de j
			// cette boucle sert juste a pas ecraser la concatenation de multiple arg par la chaine de char s
			// mettre la chaine de char s en parametre du dispatcher ? afin de traiter le tout dans le pf_s ? 
			while (j < tmp)
			{
				j++;
			}
			datas.str[j] = s[i];
			//printf("datas.str[j] = %c et s[i] = %c \n", datas.str[i], s[i]);
		}
		j++;
		i++;
	}
	if (s[i] == '\0')
	{
		ft_buffer(datas);
	}
	return (i);
}
