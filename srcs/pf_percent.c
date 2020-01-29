#include "../Libft/libft.h"
#include "../headers/ft_printf.h"

t_struct    pf_pct(va_list ap, t_struct datas, int i, const char *s)
{
    int j;
    int prec_len;
    int stringValue;
    int len;

    (void)s;
    (void)ap;
    j = 0;
    datas.flag[temp] = i;
    stringValue = '%';
    len = ((datas.flag[prec] == '.' &&
                datas.flag[size_prec] == 0) ? 0 : 1);
    prec_len = datas.flag[size_prec] - len;
    if ((!datas.flag[flags] && datas.flag[size] > 0) ||
            (!datas.flag[flags] && datas.flag[size_prec] > 0))
        datas = fill_size(datas, len);
    if (datas.flag[flags] == '0')
        datas = ft_left_justify(datas, len);
    if (datas.flag[flags] == '-' && datas.flag[prec] == '.')
        datas = fill_right_justify_prec(datas, len, prec_len);
    if (stringValue && len > 0)
        datas = ft_buffer(stringValue, datas);
    if (datas.flag[flags] == '-')
        datas = ft_right_justify(datas, len, prec_len);
    return (datas);
}
