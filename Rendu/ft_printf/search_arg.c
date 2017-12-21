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

# include "ft_printf.h"

void	ft_arg_char(va_list ap, t_type *all_type, char type)
{
	if (type == 'C')
		all_type->wc = va_arg(ap, wchar_t);
	else if (type == 'c')
		all_type->c = (char)va_arg(ap, int);
	else if (type == 'u')
		all_type->ud = (unsigned char)va_arg(ap, int);
	else if (ft_strchr("dioxX", type))
		all_type->d = (char)va_arg(ap, int);
}

void	ft_arg_str(va_list ap, t_type *all_type, char type)
{
	if (type == 'S')
		all_type->wstr = va_arg(ap, wchar_t*);
	else if (type == 's')
		all_type->str = va_arg(ap, char*);
}

void	ft_arg_ll(va_list ap, t_type *all_type, char size_type, char type)
{
	if (size_type == 'L' && type == 'u')
		all_type->ud = va_arg(ap, uintmax_t);
	else if (size_type == 'L' && type != 'u')
		all_type->d = va_arg(ap, intmax_t);
	else if (size_type == 'j' && type == 'u')
		all_type->ud = va_arg(ap, uintmax_t);
	else if (size_type == 'j' && type != 'u')
		all_type->d = va_arg(ap, intmax_t);
}

void	ft_arg_int(va_list ap, t_type *all_type, char size_type, char type)
{
	if (size_type == 'L' || size_type == 'j')
		ft_arg_ll(ap, all_type, size_type, type);
	else if (size_type == 'l' && type == 'u')
		all_type->ud = va_arg(ap, unsigned long);
	else if (size_type == 'l' && type != 'u')
		all_type->d = va_arg(ap, long);
	else if (size_type == 'h' && type == 'u')
		all_type->ud = (unsigned short)va_arg(ap, unsigned int);
	else if (size_type == 'h' && type != 'u')
		all_type->d = (short)va_arg(ap, int);
	else if (size_type == 'z' && type == 'u')
		all_type->ud = va_arg(ap, size_t);
	else if (size_type == 'z' && type != 'u')
		all_type->d = va_arg(ap, ssize_t);
	else if (ft_strchr("dioxX", type))
		all_type->d = va_arg(ap, int);
	else if (type == 'u')
		all_type->ud = va_arg(ap, unsigned int);
}

void	ft_search_arg(va_list ap, t_type *all_type, t_params *p, char type)
{
	if (type == 'D' || type == 'O' || type == 'U')
	{
		type += 32;
		p->size_type = 'l';
		p->new_type = type;
	}
	if (p->size_type == 'H' || type == 'c' || type == 'C')
		ft_arg_char(ap, all_type, type);
	else if (type == 's' || type == 'S')
		ft_arg_str(ap, all_type, type);
	else if (ft_strchr("diouxX", type))
		ft_arg_int(ap, all_type, p->size_type, type);
	else if (type == 'p')
		all_type->ud = (uintmax_t)va_arg(ap, void *);
	p->len_arg = ft_len_arg(*all_type, *p, type);
}
