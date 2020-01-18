/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thbeaumo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/21 12:08:27 by thbeaumo          #+#    #+#             */
/*   Updated: 2020/01/17 14:37:20 by thbeaumo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Libft/libft.h"
#include "../headers/ft_printf.h"

static void test_all_flag()
{
	printf("-----------------BASIC---Test-------------------------\n");
	printf("FOR d :: ---------------------------\n");
	printf("bonjour %d \n", 12);
	printf("-1.5 : %-1.5dbonjour\n", 12);
	printf("01.5 : %01.5dbonjour\n", 12);
	printf("-5.1 : %-5.1dbonjour\n", 12);
	printf("05.2 : %05.2dbonjour\n", 12);
	printf("-10.5 : %-10.5dbonjour\n", 12);
	printf("010.5 : %010.5dbonjour\n", 12);
	printf("10d : %10dbonjour\n", 12);
	printf("0*.*d : %0*.*d\n", -5, 10, 12);
	printf("FOR x :: ---------------------------\n");
	printf("bonjour %x \n", 12);
	printf("0*.*x : %0*.*xbonjour\n", 10, 5, 12);
	printf("-*.*x : %-*.*xbonjour\n", 10, 5, 12);
	printf("010.5x : %010.5xbonjour\n", 12);
	printf("-10.5x : %-10.5xbonjour\n", 12);
	printf("0*x : %0*xbonjour\n", 10, 12);
	printf("-*x : %-*xbonjour\n", 10, 12);
	printf("FOR X :: ---------------------------\n");
	printf("bonjour %X \n", 12);
	printf("0*.*X : %0*.*Xbonjour\n", 10, 5, 12);
	printf("-*.*X : %-*.*Xbonjour\n", 10, 5, 12);
	printf("010.5X : %010.5Xbonjour\n", 12);
	printf("-10.5X : %-10.5Xbonjour\n", 12);
	printf("0*X : %0*Xbonjour\n", 10, 12);
	printf("-*X : %-*Xbonjour\n", 10, 12);
	printf("FOR u :: ---------------------------\n");
	printf("bonjour 12 %u \n", 12);
	printf("bonjour -12 %u \n", -12);
	printf("0*.*u : %0*.*ubonjour\n", 10, 5, 12);
	printf("-*.*u : %-*.*ubonjour\n", 10, 5, 12);
	printf("010.5u : %010.5ubonjour\n", 12);
	printf("-10.5u : %-10.5ubonjour\n", 12);
	printf("0*u : %0*ubonjour\n", 10, 12);
	printf("-*u : %-*ubonjour\n", 10, 12);
	printf("FOR s :: ---------------------------\n");
	printf("simple test : %s \n", "bonjour");
	printf(".5s : %.5s \n", "bonjour");
	printf(".*s : %.*s \n", 5, "bonjour");
	printf("-10.5s : %-5.5s \n", "bonjour");
	printf("-*.*s : %-10.5s \n", "bonjour");
	printf("-*s : %-*s \n", 5, "bonjour");
	printf("5s : %12s \n", "bonjour");
	printf("*s : %*s \n", 12, "bonjour");
	printf("\n ---------MY-PRINTF---------- \n");
	ft_printf("-----------------BASIC---Test-------------------------\n");
	ft_printf("FOR d :: ---------------------------\n");
	printf("return : %d\n",ft_printf("-1.5 : %-1.5dbonjour\n", 12));
	printf("return : %d\n",ft_printf("01.5 : %01.5dbonjour\n", 12));
	printf("return : %d\n",ft_printf("-5.1 : %-5.1dbonjour\n", 12));
	printf("return : %d\n",ft_printf("05.2 : %05.2dbonjour\n", 12));
	printf("return : %d\n",ft_printf("-10.5 : %-10.5dbonjour\n", 12));
	printf("return : %d\n",ft_printf("010.5 : %010.5dbonjour\n", 12));
	printf("return : %d\n",ft_printf("10d : %10dbonjour\n", 12));
	printf("return : %d\n",ft_printf("0*.*d : %0*.*d\n", -5, 10, 12));
	printf("return : %d\n",ft_printf("FOR x :: ---------------------------\n"));
	printf("return : %d\n",ft_printf("bonjour %x \n", 12));
	printf("return : %d\n",ft_printf("0*.*x : %0*.*xbonjour\n", 10, 5, 12));
	printf("return : %d\n",ft_printf("-*.*x : %-*.*xbonjour\n", 10, 5, 12));
	printf("return : %d\n",ft_printf("010.5x : %010.5xbonjour\n", 12));
	printf("return : %d\n",ft_printf("-10.5x : %-10.5xbonjour\n", 12));
	printf("return : %d\n",ft_printf("0*x : %0*xbonjour\n", 10, 12));
	printf("return : %d\n",ft_printf("-*x : %-*xbonjour\n", 10, 12));
	printf("return : %d\n",ft_printf("FOR X :: ---------------------------\n"));
	printf("return : %d\n",ft_printf("bonjour %X \n", 12));
	printf("return : %d\n",ft_printf("0*.*X : %0*.*Xbonjour\n", 10, 5, 12));
	printf("return : %d\n",ft_printf("-*.*X : %-*.*Xbonjour\n", 10, 5, 12));
	printf("return : %d\n",ft_printf("010.5X : %010.5Xbonjour\n", 12));
	printf("return : %d\n",ft_printf("-10.5X : %-10.5Xbonjour\n", 12));
	printf("return : %d\n",ft_printf("0*X : %0*Xbonjour\n", 10, 12));
	printf("return : %d\n",ft_printf("-*X : %-*Xbonjour\n", 10, 12));
	printf("return : %d\n",ft_printf("FOR u :: ---------------------------\n"));
	printf("return : %d\n",ft_printf("bonjour 12 %u \n", 12));
	printf("return : %d\n",ft_printf("bonjour -12 %u \n", -12));
	printf("return : %d\n",ft_printf("0*.*u : %0*.*ubonjour\n", 10, 5, 12));
	printf("return : %d\n",ft_printf("-*.*u : %-*.*ubonjour\n", 10, 5, 12));
	printf("return : %d\n",ft_printf("010.5u : %010.5ubonjour\n", 12));
	printf("return : %d\n",ft_printf("-10.5u : %-10.5ubonjour\n", 12));
	printf("return : %d\n",ft_printf("0*u : %0*ubonjour\n", 10, 12));
	printf("return : %d\n",ft_printf("-*u : %-*ubonjour\n", 10, 12));
	printf("return : %d\n",ft_printf("FOR s  :: ---------------------------\n"));
	printf("return : %d\n",ft_printf("simple test : %s \n", "bonjour"));
	printf("return : %d\n",ft_printf(".5s : %.5s \n", "bonjour"));
	printf("return : %d\n",ft_printf(".*s : %.*s \n", 5, "bonjour"));
	printf("return : %d\n",ft_printf("-10.5s : %-5.5s \n", "bonjour"));
	printf("return : %d\n",ft_printf("-*.*s : %-10.5s \n", "bonjour"));
	printf("return : %d\n",ft_printf("-*s : %-*s \n", 5, "bonjour"));
	printf("return : %d\n",ft_printf("5s : %12s \n", "bonjour"));
	printf("return : %d\n",ft_printf("*s : %*s \n", 12, "bonjour"));
	ft_printf("-*.*s : %-*.*s \n", 90, 5, "bonjour");
}
int main()
{
	ft_printf(" check %.5d\n", 12);
	printf(" check %.5d\n", 12);
	test_all_flag();
	return 0;
}
