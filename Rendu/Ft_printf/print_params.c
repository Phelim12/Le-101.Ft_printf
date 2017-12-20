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

int		ft_print_precision(t_type *all_type, t_params *flags, char type)
{
	int ret;

	ret = 0;
	if (!(ft_strchr("diouxX", type)))
		return (0);
	flags->size_precision -= flags->len_arg;
	if (flags->flag_more == TRUE || all_type->d < 0)
		flags->size_precision++;
	while (flags->size_precision-- > 0)
		ret += ft_putchar('0');
	flags->len_arg += ret;
	return (ret);
}

int ft_print_sign(t_type all_type, t_params *flags, char type)
{
	char sign;

	if (flags->print_sign == FALSE)
		return (0);
	if (type == 'd' || type == 'i')
	{
		if (all_type.d >= 0)
			sign = '+';
		if (all_type.d < 0)
			sign = '-';
		flags->print_sign = FALSE;
		return (ft_putchar(sign));
	}
	return (0);
}

int	ft_check_sign(t_type all_type, t_params *flags, char type, int first)
{
	int len_width;

	if (!(ft_strchr("diu", type)))
		return (0);
	len_width = (flags->size_width - flags->len_arg);
	if (first == TRUE && flags->flag_zero == FALSE && len_width > 0)
		return (0);
	if (first == TRUE && flags->flag_zero == TRUE && (flags->flag_more == TRUE || all_type.d < 0))
		return (ft_print_sign(all_type, flags, type));
	if (flags->flag_more == TRUE || all_type.d < 0)
		return (ft_print_sign(all_type, flags, type));
	if (flags->flag_space == TRUE && (type == 'd' || type == 'i') && !(first) && flags->size_precision <= 0)
		return (ft_putchar(' '));
	return (0);
}

int		ft_print_prefix(t_type a, t_params *flags, char type)
{
	if (flags->print_prefix == 0 || !(ft_strchr("oxX", type)))
		return (0);
	if (flags->flag_hashtag == TRUE)
	{
		if (flags->print_prefix == 1 && flags->flag_zero == FALSE)
		{
			flags->print_prefix++;
			return (0);
		}
		flags->print_prefix = 0;
		if (type == 'X' && a.d > 0)
			return (ft_putstr("0X"));
		if (type == 'x' && a.d > 0)
			return (ft_putstr("0x"));
		if (type == 'o')
			return (ft_putchar('0'));
	}
	flags->print_prefix = 0;
	return (0);
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

int		ft_print_width(t_type all_type, t_params *flags, char type)
{
	int ret;
	int sub;

	sub = 0;
	ret = 0;
	if ((flags->size_width + flags->len_arg) <= (flags->size_precision))
		flags->size_width = 0;
	else if ((type == 'd' || type == 'i') && flags->len_arg < flags->size_precision)
		sub = flags->size_precision;
	else
		sub = (flags->len_arg + (ft_len_precision(all_type, *flags, type)));
	flags->size_width -= sub;
	while (flags->flag_less == FALSE && flags->size_width-- > 0)
	{
		if (flags->flag_zero == TRUE)
			ft_putchar('0');
		else
			ft_putchar(' ');
		ret++;
	}
	if (flags->flag_less == TRUE)
	{
		flags->size_width += sub;
		flags->flag_zero = FALSE;
		flags->flag_less = FALSE;
	}
	return (ret);
}

int		ft_print_flags(t_type all_type, t_params flags, char type)
{
	int ret;

	ret = 0;
	if ((flags.size_precision) > 0 && (type == 's'))
	{
		all_type.str[flags.size_precision] = 0;
		flags.len_arg = ft_strlen(all_type.str);
	}
	ret += ft_check_sign(all_type, &flags, type, 1);
	ret += ft_print_prefix(all_type, &flags, type);
	ret += ft_print_width(all_type, &flags, type);
	ret += ft_print_prefix(all_type, &flags, type);
	ret += ft_check_sign(all_type, &flags, type, 0);
	ret += ft_print_precision(&all_type, &flags, type);
	ret += ft_print_arg(all_type, flags, type);
	ret += ft_print_width(all_type, &flags, type);
	return (ret);
}

int		ft_print_params(va_list ap, t_params flags, char type)
{
	t_type all_type;

	reset_all_type(&all_type);
	ft_search_arg(ap, &all_type, &flags, type);
	return (ft_print_flags(all_type, flags, type));
}