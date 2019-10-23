/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thbeaumo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/20 16:54:43 by thbeaumo          #+#    #+#             */
/*   Updated: 2019/10/23 14:00:16 by thbeaumo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <stdarg.h>


typedef struct		s_struct
{
	char *str;
	char *buf;
}					t_struct;

int		ft_parse(va_list ap, t_struct *datas);
int		ft_dispatcher(va_list ap, t_struct *datas);
int		pf_c(va_list ap, t_struct *datas);
int		pf_s(va_list ap, t_struct *datas);
#endif
