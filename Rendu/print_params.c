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

int		ft_print_prefix(t_type a, t_params flags, char type)
{
	if (flags.flag_hashtag == TRUE && (type == 'x' || type == 'X') && a.d > 0)
	{
		if (type == 'X')
			ft_putstr("0X");
		else
			ft_putstr("0x");
		return (2);
	}
	if (flags.flag_hashtag == TRUE && type == 'o')
	{
		ft_putchar('0');
		return (1);
	}
	if (flags.flag_more == TRUE && a.d >= 0)
	{
		if (flags.flag_space == TRUE && flags.len_arg >= flags.size_width)
			ft_putchar('+');
		if (flags.flag_space == FALSE)
			ft_putchar('+');
		return (1);
	}
	return (0);
}

int		ft_print_width(t_type all_type, t_params *flags, char type, int zero)
{
	int ret;
	int print;

	ret = 0;
	flags->size_width -= flags->len_arg;
	if (ft_strchr("udioxX", type) && zero && (flags->size_width <= 0 || flags->flag_zero == TRUE))
		ret += ft_print_prefix(all_type, *flags, type);
	print = ret;
	while (flags->flag_less != zero && flags->size_width-- > 0 )
	{
		if (flags->flag_zero == TRUE && zero == 1)
			ft_putchar('0');
		else
			ft_putchar(' ');
		ret++;
	}
	if (ft_strchr("udioxX", type) && zero && print == 0)
		ret += ft_print_prefix(all_type, *flags, type);
	if (flags->flag_less == TRUE)
		flags->size_width += flags->len_arg;
	return (ret);
}

int		ft_print_flags(t_type all_type, t_params flags, char type)
{
	int ret;

	ret = 0;
	ret += ft_print_width(all_type, &flags, type, 1);
	ret += ft_print_arg(all_type, flags, type);
	ret += ft_print_width(all_type, &flags, type, 0);
	return (ret);
}

int		ft_print_params(va_list ap, t_params flags, char type)
{
	t_type all_type;

	reset_all_type(&all_type);
	ft_search_arg(ap, &all_type, &flags, type);
	return (ft_print_flags(all_type, flags, type));
}