#include "ft_printf.h"
#include "libft/libft.h"

int pf_XU(va_list ap, t_struct datas, int i)
{
    int val;
    int j;
    char *stringValue;

    j = 0;
    val = va_arg(ap, int);
    stringValue = ft_itoa_base(val, 16);
    while (stringValue[j])
        ft_buffer(stringValue[j++], datas);
    return (i);
}