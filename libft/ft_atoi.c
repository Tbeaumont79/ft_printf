/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thbeaumo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/09 10:33:16 by thbeaumo          #+#    #+#             */
/*   Updated: 2019/10/17 13:54:31 by thbeaumo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_atoi(const char *s1)
{
	int					neg;
	unsigned long int	val;
	int					i;

	neg = 1;
	val = 0;
	i = 0;
	while ((s1[i] >= 9 && s1[i] <= 13) || s1[i] == 32)
		i++;
	if (s1[i] == '-')
		neg = -1;
	if (s1[i] == '-' || s1[i] == '+')
		i++;
	while ((ft_isdigit(s1[i])) && s1[i] != '\0')
		val = val * 10 + ((const char)s1[i++] - '0');
	return (val * neg);
}
