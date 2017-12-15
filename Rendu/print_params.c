/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   print_params.c                                   .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: clcreuso <clcreuso@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2017/12/15 21:27:49 by clcreuso     #+#   ##    ##    #+#       */
/*   Updated: 2017/12/15 21:27:49 by clcreuso    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

# include "ft_printf.h"

int		ft_print_width(t_type all_type, t_params flags, char type, char first)
{
	int ret;

	ret = 0;
	while (flags.size_width > 0 && flags.size_width > flags.size_precision && first == flags.flag_less)
	{
		ret++;
		if (flags.flag_zero == TRUE)
			ft_putchar('0');
		else
			ft_putchar(' ');
		flags.size_width--;
	}
	while ((flags.len_arg + ret) < flags.size_precision && flags.flag_less == FALSE)
	{
		ft_putchar('0');
		ret++;
	}
	return (ret);
}

int 	ft_print_prefix(char type)
{
	if (type == 'X' || type == 'x')
	{
		if (type == 'x')
			ft_putstr("0x");
		else
			ft_putstr("0X");
		return (2);
	}
	ft_putchar('0');
	return (1);
}

int		ft_print_flags(t_type all_type, t_params flags, char type)
{
	int ret;

	ret = 0;
	flags.size_width -= ft_len_arg(all_type, flags, type);
	if (flags.flag_hashtag == TRUE && ft_strchr("OoXx", type) && all_type.d != 0 && flags.flag_zero == TRUE)
		ret += ft_print_prefix(type);
	if (flags.size_width > 0)
		ret += ft_print_width(all_type, flags, type, 0);
	if (flags.flag_hashtag == TRUE && ft_strchr("OoXx", type) && all_type.d != 0 && flags.flag_zero == FALSE)
		ret += ft_print_prefix(type);
	if (ft_strchr("Ddi", type) && flags.flag_space && !flags.flag_less && all_type.d >= 0 && !ret && !ret++)
		ft_putchar(' ');
	ret += ft_print_arg(all_type, flags, type);
	if (flags.size_width > 0)
		ret += ft_print_width(all_type, flags, type, 1);
	return (ret);
}

int		ft_print_params(va_list ap, t_params flags, char type)
{
	t_type all_type;

	reset_all_type(&all_type);
	ft_search_arg(ap, &all_type, &flags, type);
	return (ft_print_flags(all_type, flags, type));
}