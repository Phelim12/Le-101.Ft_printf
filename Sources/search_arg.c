/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_printf.c                                      .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: clcreuso <clcreuso@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2017/12/08 19:51:08 by clcreuso     #+#   ##    ##    #+#       */
/*   Updated: 2017/12/08 19:51:08 by clcreuso    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "ft_printf.h"

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

void	ft_arg_str(va_list ap, t_type *all_type, char size_type, char *type)
{
	if (*type == 'S')
		all_type->wstr = va_arg(ap, wchar_t*);
	else if (*type == 's')
		all_type->str = va_arg(ap, char*);
}

void	ft_arg_char(va_list ap, t_type *all_type, char size_type, char *type)
{
	if (*type == 'C')
		all_type->wc = va_arg(ap, wchar_t);
	else if (*type == 'c')
		all_type->c = (char)va_arg(ap, int);
	else if (ft_strchr("di", *type))
		all_type->d = (char)va_arg(ap, int);
	else if (ft_strchr("ouxX", *type))
		all_type->ud = (unsigned char)va_arg(ap, unsigned int);
}

void	ft_arg_int(va_list ap, t_type *all_type, char size_type, char type)
{
	if (ft_strchr("jlL", size_type) && ft_strchr("di", type))
		all_type->d = va_arg(ap, intmax_t);
	else if (ft_strchr("jlL", size_type) && ft_strchr("ouxX", type))
		all_type->ud = va_arg(ap, uintmax_t);
	else if (size_type == 'h' && ft_strchr("di", type))
		all_type->d = (short)va_arg(ap, int);
	else if (size_type == 'h' && ft_strchr("ouxX", type))
		all_type->ud = (unsigned short)va_arg(ap, unsigned int);
	else if (size_type == 'z' && ft_strchr("di", type))
		all_type->d = (ssize_t)va_arg(ap, ssize_t);
	else if (size_type == 'z' && ft_strchr("ouxX", type))
		all_type->ud = (size_t)va_arg(ap, size_t);
	else if (ft_strchr("di", type))
		all_type->d = (int)va_arg(ap, int);
	else if (ft_strchr("ouxX", type))
		all_type->ud = (unsigned int)va_arg(ap, unsigned int);
}

void	ft_search_arg(va_list ap, t_type *all_type, t_params *p, char *type)
{
	ft_modify_params(p, type);
	if (p->size_type == 'H' && ft_strchr("diouxXcC", *type))
		ft_arg_char(ap, all_type, p->size_type, type);
	else if (ft_strchr("cC", *type))
		ft_arg_char(ap, all_type, p->size_type, type);
	else if (ft_strchr("sS", *type))
		ft_arg_str(ap, all_type, p->size_type, type);
	else if (ft_strchr("diouxX", *type))
		ft_arg_int(ap, all_type, p->size_type, *type);
	else if (!(ft_strchr(PRINTF_TYPE, *type)) && *type)
	{
		*type = 'C';
		all_type->wc = (wchar_t)*type;
	}
	p->len_arg = ft_len_arg(*all_type, *p, *type);
}
