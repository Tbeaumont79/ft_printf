#include "ft_printf.h"
#include "libft/libft.h"

int pf_c(va_list ap, t_struct datas, int i)
{
    int val;
    int j;
    char *stringValue;

    j = 0;
    val = va_arg(ap, int);
    ft_buffer(val, datas);
    return (i);
}