/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thbeaumo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/23 14:06:41 by thbeaumo          #+#    #+#             */
/*   Updated: 2019/11/08 00:07:24 by bod              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "ft_printf.h"

int		ft_printf(const char *s, ...)
{
	va_list ap;
	va_start(ap, s);
	t_struct datas;
	size_t	 len;
	
	len = ft_strlen(s);
	if (!(datas.str = malloc(sizeof(int) * (len + 1)))) {
		return (0);
	}
    ft_bzero(datas.buf, 1);
	ft_parse(ap, datas, s);
	ft_display_buf(datas);

	va_end(ap);
	return (0);
}

int main(int ac, char **av)
{
	(void)ac;
	ft_printf("bonjour je %s suis un test %s bon%s \n", av[1], av[2], av[3]);
	return (0);
}
