/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thbeaumo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/23 14:06:41 by thbeaumo          #+#    #+#             */
/*   Updated: 2020/01/03 11:23:22 by thbeaumo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "ft_printf.h"

int		ft_printf(const char *s, ...)
{
	va_list ap;
	va_start(ap, s);
	t_struct datas;
	
    ft_bzero(datas.buf, 1);
	ft_parse(ap, datas, s);
	va_end(ap);
	return (0);
}

int main(int ac, char **av)
{
	int c;
	(void)ac;
	(void)av;
	
	c = 12;
	ft_printf("bonjour %05.d\n", c);
	return (0);
}
