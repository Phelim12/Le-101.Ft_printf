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

int		ft_len_precision(t_type all_type, t_params flags, char type)
{
	int ret;

	ret = 0;
	if (!(ft_strchr("diouxX", type)))
		return (0);
	flags.size_precision -= flags.len_arg;
	if (flags.flag_more == TRUE || all_type.d < 0)a
		flags.size_precision++;
	while (flags.size_precision-- > 0)
		ret++;
	return (ret);
}

int	ft_check_sign(t_type all_type, t_params *flags, char type, int first)
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