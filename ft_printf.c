/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thbeaumo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/23 14:06:41 by thbeaumo          #+#    #+#             */
/*   Updated: 2020/01/15 13:09:25 by thbeaumo         ###   ########.fr       */
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
/*
static void test_all_flag()
{
printf("FOR d :: ---------------------------\n");
   printf("-1.5 : %-1.5dbonjour\n", 12);
   printf("01.5 : %01.5dbonjour\n", 12);
   printf("-5.1 : %-5.1dbonjour\n", 12);
   printf("05.2 : %05.2dbonjour\n", 12);
   printf("-10.5 : %-10.5dbonjour\n", 12);
   printf("010.5 : %010.5dbonjour\n", 12);
	printf("FOR x :: ---------------------------\n");
	printf("0*.*x : %0*.*xbonjour\n",10, 5, 12);
	printf("-*.*x : %-*.*xbonjour\n",10, 5, 12);
	printf("010.5x : %010.5xbonjour\n", 12);
	printf("-10.5x : %-10.5xbonjour\n", 12);
	printf("0*x : %0*xbonjour\n",10, 12);
	printf("-*x : %-*xbonjour\n",10, 12);
	printf("FOR X :: ---------------------------\n");
	printf("0*.*X : %0*.*Xbonjour\n",10, 5, 12);
	printf("-*.*X : %-*.*Xbonjour\n",10, 5, 12);
	printf("010.5X : %010.5Xbonjour\n", 12);
	printf("-10.5X : %-10.5Xbonjour\n", 12);
	printf("0*X : %0*Xbonjour\n",10, 12);
	printf("-*X : %-*Xbonjour\n",10, 12);
	printf("FOR u :: ---------------------------\n");
	printf("0*.*u : %0*.*ubonjour\n",10, 5, 12);
	printf("-*.*u : %-*.*ubonjour\n",10, 5, 12);
	printf("010.5u : %010.5ubonjour\n", 12);
	printf("-10.5u : %-10.5ubonjour\n", 12);
	printf("0*u : %0*ubonjour\n",10, 12);
	printf("-*u : %-*ubonjour\n",10, 12);
printf("\n ---------MY-PRINTF---------- \n");
printf("FOR d :: ---------------------------\n");
   ft_printf("-1.5 : %-1.5dbonjour\n", 12);
   ft_printf("01.5 : %01.5dbonjour\n", 12);
   ft_printf("-5.1 : %-5.1dbonjour\n", 12);
   ft_printf("05.2 : %05.2dbonjour\n", 12);
   ft_printf("-10.5 : %-10.5dbonjour\n", 12);
   ft_printf("010.5 : %010.5dbonjour\n", 12);
	ft_printf("FOR x :: ---------------------------\n");
	ft_printf("0*.*x : %0*.*xbonjour\n",10, 5, 12);
	ft_printf("-*.*x : %-*.*xbonjour\n",10, 5, 12);
	ft_printf("010.5x : %010.5xbonjour\n", 12);
	ft_printf("-10.5x : %-10.5xbonjour\n", 12);
	ft_printf("0*x : %0*xbonjour\n",10, 12);
	ft_printf("-*x : %-*xbonjour\n",10, 12);
	ft_printf("FOR X :: ---------------------------\n");
	ft_printf("0*.*X : %0*.*Xbonjour\n",10, 5, 12);
	ft_printf("-*.*X : %-*.*Xbonjour\n",10, 5, 12);
	ft_printf("010.5X : %010.5Xbonjour\n", 12);
	ft_printf("-10.5X : %-10.5Xbonjour\n", 12);
	ft_printf("0*X : %0*Xbonjour\n",10, 12);
	ft_printf("-*X : %-*Xbonjour\n",10, 12);
	ft_printf("FOR u :: ---------------------------\n");
	ft_printf("0*.*u : %0*.*ubonjour\n",10, 5, 12);
	ft_printf("-*.*u : %-*.*ubonjour\n",10, 5, 12);
	ft_printf("010.5u : %010.5ubonjour\n", 12);
	ft_printf("-10.5u : %-10.5ubonjour\n", 12);
	ft_printf("0*u : %0*ubonjour\n",10, 12);
	ft_printf("-*u : %-*ubonjour\n",10, 12);
}
*/
int main(int ac, char **av)
{
	(void)ac;
	(void)av;
	ft_printf("%s\n", "bonjour");
   //ft_printf("other test1 ft_printf: %.4d\n", 12);
   //ft_printf("other test2 ft_printf: %00.4d\n", 12);
	return (0);
}
