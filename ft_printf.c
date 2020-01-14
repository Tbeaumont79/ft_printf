/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thbeaumo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/23 14:06:41 by thbeaumo          #+#    #+#             */
/*   Updated: 2020/01/14 16:29:22 by thbeaumo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "ft_printf.h"
#include <stdio.h>
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
	(void)ac;
	(void)av;
   ft_printf("0*d :: %0*d\n", 12);
   printf("-1.5 : %-1.5dbonjour\n", 12);
   printf("01.5 : %01.5dbonjour\n", 12);
   printf("-5.1 : %-5.1dbonjour\n", 12);
   printf("05.2 : %05.2dbonjour\n", 12);
   printf("-10.5 : %-10.5dbonjour\n", 12);
   printf("010.5 : %010.5dbonjour\n", 12);
   printf("\n--------------------------------\n");
   ft_printf("-1.5 : %-1.5dbonjour\n", 12);
   ft_printf("01.5 : %01.5dbonjour\n", 12);
   ft_printf("-5.1 : %-5.1dbonjour\n", 12);
   ft_printf("05.2 : %05.2dbonjour\n", 12);
   ft_printf("-10.5 : %-10.5dbonjour\n", 12);
   ft_printf("010.5 : %010.5dbonjour\n", 12);
   //ft_printf("other test1 ft_printf: %.4d\n", 12);
   //ft_printf("other test2 ft_printf: %00.4d\n", 12);
	return (0);
}
