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

# include "ft_printf.h"

int 	ft_wstrlen(wchar_t *wstr)
{
	int cur;

	cur = 0;
	while (wstr[cur])
		cur++;
	return (cur);
}

int		ft_len_conv(t_type all_type, t_params flags, char type)
{
	if (flags.size_type == 'H' && (type == 'x' || type == 'X'))
		return (ft_len_base_llu((uintmax_t)all_type.c, "0123456789ABCDEF"));
	if (flags.size_type == 'H' && (type == 'o' || type == 'O'))
		return (ft_len_base_llu((uintmax_t)all_type.c, "01234567"));
	if (type == 'x' || type == 'X')
		return (ft_len_base_llu((uintmax_t)all_type.d, "0123456789ABCDEF"));
	if (type == 'o' || type == 'O')
		return (ft_len_base_llu((uintmax_t)all_type.d, "01234567"));
	return (0);
}

int		ft_len_arg(t_type all_type, t_params flags, char type)
{
	int prefix;

	prefix = 0;
	if (type == '%')
		return (1);
	if ((type == 'X' || type == 'x') && flags.flag_hashtag == TRUE)
		prefix = 2;
	if ((((type == 'O' || type == 'o') && flags.flag_hashtag == TRUE)) ||
	 (flags.flag_more == TRUE || all_type.d < 0))
		prefix = 1;
	if (type == 'S')
		return (ft_wstrlen(all_type.wstr));
	if (type == 's' && all_type.str != NULL)
		return (ft_strlen(all_type.str));
	if (type == 'c' || type == 'C')
		return (1);
	if (ft_strchr("OoXx", type))
		return ((ft_len_conv(all_type, flags, type)) + prefix);
	if (ft_strchr("Ddi", type))
	{
		if (flags.flag_point == TRUE && all_type.d == 0)
			return (0);
		return (ft_lenint_max(all_type.d, 0) + prefix);
	}
	if (type == 'U' || type == 'u')
		return (ft_lenuint_max(all_type.ud));
	return (0);
}