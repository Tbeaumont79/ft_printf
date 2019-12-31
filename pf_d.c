#include "ft_printf.h"
#include "libft/libft.h"

t_struct get_int(t_struct datas, int tmp, const char *s)
{
    int nb;

    nb = 0;
    if (ft_isdigit(s[tmp]))
    {
        nb = nb * 10 + ft_atoi(&s[tmp]);
        while (ft_isdigit(s[tmp]))
            tmp++;
    }
    datas.flag[size] = nb;
    datas.flag[temp] = tmp++;
    return (datas);
}

t_struct get_flag(t_struct datas, int tmp, const char *s)
{
    static char flag[4] = {'0', '-', '*', '.'};
    int i;
    int flag_len;

    i = 0;
    flag_len = ft_strlen(flag);
    while (s[tmp - 1] != '%')
        tmp--;
    while (i < flag_len && s[tmp] != flag[i])
        i++;
    if (s[tmp] == flag[i] && ft_isdigit(s[tmp + 1]))
    {
        datas.flag[flags] = flag[i];
        return (get_int(datas, tmp, s));
    }
    if (s[tmp] != flag[i] && ft_isdigit(s[tmp]))
        return (get_int(datas, tmp, s));
    return (datas);
}

int pf_d(va_list ap, t_struct datas, int i, const char *s)
{
    int val;
    int j;
    int tmp;
    char *stringValue;

    tmp = i + 1;
    j = 0;
    val = va_arg(ap, int);
    stringValue = ft_itoa_base(val, 10);
    datas = get_flag(datas, tmp, s);
    if (datas.flag[flags] == '0' || datas.flag[size] > 0)
        ft_left_justify(datas, ft_strlen(stringValue));
    while (stringValue[j])
        ft_buffer(stringValue[j++], datas);
    return (i);
}
