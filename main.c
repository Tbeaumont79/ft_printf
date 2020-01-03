/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thbeaumo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/21 12:08:27 by thbeaumo          #+#    #+#             */
/*   Updated: 2020/01/03 10:31:29 by thbeaumo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>

int main()
{
   printf("Characters: %c %c \n", 'a', 65);
   printf("Width trick: %*d \n", 5, 10);
   printf("other test: %015.4d\n", 12);
   printf("string :: %.5s   \n", "coucou");
   return 0;
}
