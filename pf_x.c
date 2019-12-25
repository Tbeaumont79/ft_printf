#include "libft/libft.h"
#include "ft_printf.h"

int pf_x(va_list ap, t_struct datas, int i)
{
    int val;
    int j;
    char *stringValue;

    j = 0;
    val = va_arg(ap, int);
    stringValue = ft_itoa_base(val, 16);
    string_lower(stringValue);
    while (stringValue[j])
        ft_buffer(stringValue[j++], datas);
    return (i);
}