/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   print_arg.c                                      .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: clcreuso <clcreuso@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2017/12/15 16:17:55 by clcreuso     #+#   ##    ##    #+#       */
/*   Updated: 2017/12/15 16:17:55 by clcreuso    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "ft_printf.h"

int 	ft_putwstr(wchar_t *wstr, int stop)
{
	int ret;
	int cur;

	ret = 0;
	cur = 0;
	while (wstr[cur])
	{
		if (ret >= stop && stop > 0)
			break ;
		ret += ft_putwchar(wstr[cur]);
		cur++;
	}
	return (ret);
}

int 	ft_print_nchar(t_type all_type, t_params flags, char type)
{
	if (type == 'c')
		return (ft_putchar(all_type.c));
	if (type == 'C')
		return (ft_putwchar(all_type.wc));
	if (type == 's')
	{
		if (!(all_type.str) && flags.flag_point == FALSE)
			return (ft_putstr("(null)"));
		return (ft_putstr(all_type.str));
	}
	if (type == 'S')
	{
		if (!(all_type.wstr) && flags.flag_point == FALSE)
			return (ft_putstr("(null)"));
		return (ft_putwstr(all_type.wstr, flags.size_precision));
	}
	return (0);
}

int 	ft_print_conv(char *base, uintmax_t ud, t_params flags, char type)
{
	int ret;

	if (ft_strchr("jlzL", flags.size_type))
		ret = ft_putnbr_base_llu(ud, base);
	else
		ret = ft_putnbr_base_u(ud, base);
	if (ret == -1 && flags.flag_point == FALSE)
	{
		if (flags.flag_hashtag == TRUE && type == 'o')
			return (0);
		else
			return (ft_putchar('0'));
	}
	if (ret == -1 && flags.flag_point == TRUE)
		return (0);
	return (ret);
}

int 	ft_print_int(t_type all_type, t_params flags, char type, int ret)
{
	if (type == 'd' || type == 'i')
	{
		if (flags.flag_point == TRUE && all_type.d == 0)
			return (0);
		if (flags.size_type == 'h')
			ft_putnbr_hd((short int)all_type.d, 0);
		else
			ft_putnbr_ll(all_type.d, 0);
		ret = ft_lenint_max(all_type.d, 0);	
	}
	else if (type == 'u')
	{
		if (flags.flag_point > 0 && all_type.ud == 0)
			return (0);
		ft_putnbr_llu(all_type.ud);
		ret = ft_lenuint_max(all_type.ud);
	}
	else if (type == 'o')
		ret = ft_print_conv("01234567", all_type.ud, flags, type);
	else if (type == 'x')
		ret = ft_print_conv("0123456789abcdef", all_type.ud, flags, type);
	else if (type == 'X')
		ret = ft_print_conv("0123456789ABCDEF", all_type.ud, flags, type);
	return (ret);
}

int		ft_print_arg(t_type all_type, t_params flags, char type)
{
	int ret;

	ret = 0;
	if (type == '%')
		return (ft_putchar('%'));
	if (ft_strchr("cCsS", type))
		ret = ft_print_nchar(all_type, flags, type);
	else if (ft_strchr("diouxX", type))
		ret = ft_print_int(all_type, flags, type, 0);
	return (ret);
}