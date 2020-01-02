/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thbeaumo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/21 12:08:27 by thbeaumo          #+#    #+#             */
/*   Updated: 2020/01/02 17:02:25 by thbeaumo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>

int main()
{
   printf("Characters: %c %c \n", 'a', 65);
   printf("Some different radices: %d %x %#x %#X \n", 100, 100, 100, 100);
   printf("Width trick: %*d \n", 5, 10);
   printf("string :: %.5s   \n", "coucou");
   return 0;
}
