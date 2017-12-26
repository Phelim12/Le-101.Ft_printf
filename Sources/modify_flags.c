/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   modify_flags.c                                   .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: clcreuso <clcreuso@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2017/12/23 17:46:02 by clcreuso     #+#   ##    ##    #+#       */
/*   Updated: 2017/12/23 17:46:02 by clcreuso    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_modify_string(t_type *all_type, t_params *flags, char type)
{
	int pre;

	pre = flags->size_precision;
	if (type == 's' && flags->flag_point > 0 && all_type->str)
	{
		if (pre > 0)
			all_type->str = ft_strsub(all_type->str, 0, pre);
		else
			all_type->str = ft_strsub(all_type->str, 0, 0);
		flags->len_arg = ft_strlen(all_type->str);
	}
	if (type == 'S' && flags->flag_point > 0 && all_type->wstr)
	{
		if (pre > 0)
			all_type->wstr = ft_wstrsub(all_type->wstr, 0, pre);
		else
			all_type->wstr = ft_wstrsub(all_type->wstr, 0, 0);
		flags->len_arg = ft_wstrlen(all_type->wstr);
	}
}

int		ft_check_sign(t_type all_type, t_params *flags, char type, int first)
{
	if (!(ft_strchr("diu", type)))
		return (0);
	if (first && !(flags->flag_zero) &&
		(flags->size_width - flags->len_arg) > 0)
		return (0);
	if (first && flags->flag_zero && (flags->flag_more || all_type.d < 0))
		return (ft_print_sign(all_type, flags, type));
	if (flags->flag_more == TRUE || all_type.d < 0)
		return (ft_print_sign(all_type, flags, type));
	if (first && flags->flag_space && ft_strchr("di", type) &&
		flags->size_precision < 0)
		return (ft_putchar(' '));
	return (0);
}

int		ft_modify_width(t_type all_type, t_params flags, char type)
{
	int pre;

	pre = flags.size_precision;
	if ((flags.size_width + flags.len_arg) <= pre && !(ft_strchr("sS", type)))
		return (flags.size_width);
	else if (ft_strchr("di", type) && flags.len_arg < pre)
		return ((all_type.d < 0) ? (pre + 1) : (pre));
	else
		return (flags.len_arg + (ft_len_precision(all_type, flags, type)));
}

void	ft_modify_params(t_params *p, char *type)
{
	if (ft_strchr("DOU", *type))
	{
		*type += 32;
		p->size_type = 'L';
	}
	if (*type == 'p')
	{
		*type = 'x';
		p->size_type = 'L';
		p->flag_hashtag = 2;
	}
	if (*type == 'c' && p->size_type == 'l')
		*type = 'C';
	if (*type == 's' && p->size_type == 'l')
		*type = 'S';
}
