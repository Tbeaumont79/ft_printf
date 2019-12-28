#include "ft_printf.h"
#include "libft/libft.h"

int pf_c(va_list ap, t_struct datas, int i, const char *s)
{
    int val;
    int j;
    (void)s;

    j = 0;
    val = va_arg(ap, int);
    ft_buffer(val, datas);
    return (i);
}