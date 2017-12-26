/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   len_arg.c                                        .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: clcreuso <clcreuso@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2017/12/15 16:24:13 by clcreuso     #+#   ##    ##    #+#       */
/*   Updated: 2017/12/15 16:24:13 by clcreuso    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_wstrlen(wchar_t *wstr)
{
	int cur;
	int ret;

	ret = 0;
	cur = 0;
	while (wstr[cur])
	{
		ret += ft_size_wchar(wstr[cur]);
		cur++;
	}
	return (ret);
}

int		ft_len_precision(t_type all_type, t_params flags, char type)
{
	int ret;

	ret = 0;
	if (!(ft_strchr("diouxX", type)))
		return (0);
	flags.size_precision -= flags.len_arg;
	if (flags.flag_more == TRUE || all_type.d < 0)
		flags.size_precision++;
	while (flags.size_precision-- > 0)
		ret++;
	return (ret);
}

int		ft_size_prefix(t_type all_type, t_params flags, char type)
{
	if (type == '%')
		return (1);
	if ((type == 'X' || type == 'x') && flags.flag_hashtag > 0 &&
		(flags.size_precision < 1 || flags.flag_hashtag == 2))
		return (2);
	if ((((type == 'O' || type == 'o') && flags.flag_hashtag == TRUE)))
		return (1);
	if ((flags.flag_more == TRUE || all_type.d < 0))
		return (1);
	if (flags.flag_space == TRUE && flags.flag_more == FALSE &&
		(flags.size_precision < ft_lenint_max(all_type.d, 0)) &&
		(flags.flag_point == TRUE || flags.flag_point == FALSE))
		return (1);
	return (0);
}

int		ft_len_conv(t_type all_type, t_params flags, char type)
{
	if (flags.size_type == 'H' && (type == 'x' || type == 'X'))
		return (ft_len_base_llu(all_type.c, "0123456789ABCDEF"));
	if (flags.size_type == 'H' && (type == 'o' || type == 'O'))
		return (ft_len_base_llu(all_type.c, "01234567"));
	if ((type == 'x' || type == 'X') && flags.flag_hashtag != 2)
		return (ft_len_base_llu(all_type.ud, "0123456789ABCDEF"));
	if (type == 'o' || type == 'O')
		return (ft_len_base_llu(all_type.ud, "01234567"));
	if (flags.flag_hashtag == 2)
	{
		if (!(ft_len_base_llu(all_type.ud, "0123456789ABCDEF")))
			return (1);
		return (ft_len_base_llu(all_type.ud, "0123456789ABCDEF"));
	}
	return (0);
}

int		ft_len_arg(t_type all_type, t_params flags, char type)
{
	int prefix;

	if (type == 'x' && flags.flag_hashtag == 2 && all_type.ud == 0
		&& flags.flag_point && flags.size_precision >= 1)
		return (0);
	prefix = ft_size_prefix(all_type, flags, type);
	if (type == 'S' && all_type.wstr)
		return (ft_wstrlen(all_type.wstr));
	if (type == 's' && all_type.str)
		return (ft_strlen(all_type.str));
	if (type == 'c' || type == 'C')
		return (1);
	if (ft_strchr("OoXx", type))
		return ((ft_len_conv(all_type, flags, type)) + prefix);
	if (ft_strchr("Ddi", type) && flags.flag_point && !(all_type.d))
		return (0);
	if (ft_strchr("Ddi", type))
		return (ft_lenint_max(all_type.d, 0) + prefix);
	if (type == 'U' || type == 'u')
		return (ft_lenuint_max(all_type.ud));
	if (!(ft_strchr(PRINTF_TYPE, type)) && type)
		return (1);
	else
		return (prefix);
}
