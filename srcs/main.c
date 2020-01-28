/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thbeaumo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/21 12:08:27 by thbeaumo          #+#    #+#             */
/*   Updated: 2020/01/27 08:13:02 by thbeaumo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Libft/libft.h"
#include "../headers/ft_printf.h"

//check si datas de size < 0 alors datas.flag[flags] == '-' !! 

static void s()
{
	ft_printf("FOR s  :: ---------------------------\n");
	printf("my return : %d\n",ft_printf("simple test : %s \n", "bonjour"));
    printf("printf return %d\n", printf("simple test : %s \n", "bonjour"));
	printf("my return : %d\n",ft_printf(".5s : %.5s \n", "bonjour"));
    printf("printf return %d\n", printf(".5s : %.5s \n", "bonjour"));
	printf("my return : %d\n",ft_printf(".*s : %.*s \n", 5, "bonjour"));
    printf("printf return %d\n", printf(".*s : %.*s \n", 5, "bonjour"));
	printf("my return : %d\n",ft_printf("-10.5s : %-5.5s \n", "bonjour"));
    printf("printf return %d\n", printf("-10.5s : %-5.5s \n", "bonjour"));
	printf("my return : %d\n",ft_printf("-*.*s : %-10.5s \n", "bonjour"));
    printf("printf return %d\n", printf("-*.*s : %-10.5s \n", "bonjour"));
	printf("my return : %d\n",ft_printf("-*s : %-*s \n", 5, "bonjour"));
    printf("printf return %d\n", printf("-*s : %-*s \n", 5, "bonjour"));
	printf("my return : %d\n",ft_printf("5s : %12s \n", "bonjour"));
    printf("printf return %d\n", printf("5s : %12s \n", "bonjour"));
	printf("my return : %d\n",ft_printf("*s : %*s \n", 12, "bonjour"));
    printf("printf return %d\n", printf("*s : %*s \n", 12, "bonjour"));
	printf("my return : %d\n",ft_printf("double arg : %s%s\n", "bonjour", "paul"));
}

static void d()
{
	printf("basic neg :: %d\n", -14);
	ft_printf("basic neg :: %d\n", -14);
	printf("010.5d %010.5d\n", 14);
	ft_printf("010.5d %010.5d\n", 14);
	printf("05.10d %05.10d\n", 14);
	ft_printf("05.10d %05.10d\n", 14);
	printf(".10d %.10d\n", 14);
	ft_printf(".10d %.10d\n", 14);
	printf("-10.5d %-10.5d\n", 14);
	ft_printf("-10.5d %-10.5d\n", 14);
	printf("-5.d %-5.de\n", 14);
	ft_printf("-5.d %-5.de\n", 14);
	printf("-5.1d %-5.1de\n", -14);
	ft_printf("-5.1d %-5.1de\n", -14);
	printf("5.1d %-5.1de\n", 14);
	ft_printf("5.1d %-5.1de\n", 14);
	printf(".6d %.6d\n", -3);
	ft_printf(".6d %.6d\n", -3);
	printf("10.5d %10.5d\n", -216);
	ft_printf("10.5d %10.5d\n", -216);
	printf("8.3d %8.3d\n", -8473);	
	ft_printf("8.3d %8.3d\n", -8473);
	printf("3.7d %3.7d\n", -2375);
	ft_printf("3.7d %3.7d\n", -2375);
	printf("010.5d %010.5d\n", -1543);
	ft_printf("010.5d %010.5d\n", -1543);
	printf("-10.5 %-10.5d\n", -1540);
	ft_printf("-10.5 %-10.5d\n", -1540);
	printf("-8.5d %-8.5d\n",34);
	ft_printf("-8.5d %-8.5d\n",34);
	printf("-5.10d %-5.10d\n",35);
	ft_printf("-5.10d %-5.10d\n", 35);
	printf("*.5d %*.5d \n", -5, 12);
	ft_printf("*.5d %*.5d \n", -5, 12);
	/*
	   printf("-----------------BASIC---Test-------------------------\n");
	   printf("FOR d :: ---------------------------\n");
	   printf("return :: %d\n", printf("bonjour -7d %-7d \n", -14));
	   printf("return : %d\n",ft_printf("bonjour -7d :: %-7d\n", -14));
	   printf("return :: %d\n", printf("test1 -4d %-4d \n", -94827));
	   printf("return : %d\n",ft_printf("test 1 -4d :: %-4de\n", -94827));
	   printf("return :: %d\n", printf("bonjour %d \n", 12));
	   printf("return : %d\n",ft_printf("basic 12 :: %d\n", 12));
	   printf("return :: %d\n", printf("basic 12 :: %d\n", 12));
	   printf("return :: %d\n", printf("basic 0 :: %d\n", 0));
	   printf("return : %d\n",ft_printf("basic 7 0 :: %7d\n", 0));
	   printf("return :: %d\n", printf("%7d\n", 12));
	   printf("return :: %d\n", printf("-1.5 : %-1.5dbonjour\n", 12));
	   printf("return :: %d\n", printf("01.5 : %01.5dbonjour\n", 12));
	   printf("return : %d\n",ft_printf("01.5 : %01.5dbonjour\n", 12));
	   printf("return :: %d\n", printf("-5.1 : %-5.1dbonjour\n", 12));
	   printf("return :: %d\n", printf("05.2 : %05.2dbonjour\n", 12));
	   printf("return : %d\n",ft_printf("05.2 : %05.2dbonjour\n", 12));
	   printf("return :: %d\n", printf("-10.5 : %-10.5dbonjour\n", 12));
	   printf("return :: %d\n", printf("010.5 : %010.5dbonjour\n", 12));
	   printf("return :: %d\n", printf("10d : %10dbonjour\n", 12));
	   printf("return :: %d\n", printf("0*.*d : %0*.*d\n", -5, 10, 12));
	   printf("return :: %d\n", printf("05d with neg : %05d\n", -12));
	   printf("return :: %d\n", printf("05d with neg : %05.8d\n", -12));
	   printf("return : %d\n", printf("05.8d with neg : %05.8d\n", -12));
	   printf("return :: %d\n", printf("-5d with neg : %-5d\n", -12));
	   printf("return :: %d\n", printf("05d with neg : %05d\n", 12));
	   printf("\n ---------MY-PRINTF---------- \n");
	   ft_printf("-----------------BASIC---Test-------------------------\n");
	   ft_printf("FOR d :: ---------------------------\n");
	   printf("return : %d\n", ft_printf("05d with neg : %05d\n", -12));
	   printf("return : %d\n", ft_printf("-5d with neg : %-5d\n", -12));
	   printf("return : %d\n", ft_printf("-5.8d with neg : %-5.8d\n", -12));
	   printf("return : %d\n", ft_printf("05d with neg : %05d\n", 12));
	   printf("return : %d\n",ft_printf("-1.5 : %-1.5dbonjour\n", 12));
	   printf("return : %d\n",ft_printf("-5.1 : %-5.1dbonjour\n", 12));
	   printf("return : %d\n",ft_printf("-10.5 : %-10.5dbonjour\n", 12));
	   printf("return : %d\n",ft_printf("010.5 : %010.5dbonjour\n", 12));
	   printf("return : %d\n",ft_printf("10d : %10dbonjour\n", 12));
	   printf("return : %d\n",ft_printf("0*.*d : %0*.*d\n", -5, 10, 12));
	   */
}

/*static void test_all_flag()
{
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
	printf("double arg : %s%s\n", "bonjour", "paul");
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

}
*/
int main(int ac, char **av)
{
	if (ac - 1 > 0)
	{
		if(av[1][0] == 'd')
			d();
        if(av[1][0] == 's')
            s();
	}
	else
		ft_putstr("You can use ./a.out d for instance");
	return 0;
}
