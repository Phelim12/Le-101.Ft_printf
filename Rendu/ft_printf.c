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
# include <stdio.h>

void	ft_arg_modifiy(char *size_type, char *type)
{
	*size_type = 'l';
	*type += 32;
}

void	ft_arg_char(va_list ap, t_type *all_type, char type)
{
	if (type == 'C')
		all_type->wc = (wchar_t)va_arg(ap, int);
	if (type == 'u')
		all_type->ud = (uintmax_t)va_arg(ap, int);
	if (ft_strchr("cdioxX", type))
		all_type->c = (char)va_arg(ap, int);
}

void	ft_arg_str(va_list ap, t_type *all_type, char type)
{
	if (type == 'S')
		all_type->wstr = (wchar_t*)va_arg(ap, wchar_t*);
	if (type == 's')
		all_type->str = (char*)va_arg(ap, char*);
}

void	ft_arg_ptr(va_list ap, t_type *all_type, char type)
{
	return ;
}

void	ft_arg_ll(va_list ap, t_type *all_type, char size_type, char type)
{
	if (size_type == 'L' && type == 'u')
		all_type->ud = (uintmax_t)va_arg(ap, unsigned long long);
	if (size_type == 'L' && type != 'u')
		all_type->d = (intmax_t)va_arg(ap, long long);
	if (size_type == 'j' && type == 'u')
		all_type->ud = (uintmax_t)va_arg(ap, uintmax_t);
	if (size_type == 'j' && type != 'u')
		all_type->d = (intmax_t)va_arg(ap, intmax_t);
}

void	ft_arg_int(va_list ap, t_type *all_type, char size_type, char type)
{
	if (size_type == 'L' || size_type == 'j')
		ft_arg_ll(ap, all_type, size_type, type);
	else if (size_type == 'l' && type == 'u')
		all_type->ud = (uintmax_t)va_arg(ap, unsigned long);
	else if (size_type == 'l' && type != 'u')
		all_type->d = (intmax_t)va_arg(ap, long);
	else if (ft_strchr("diouxX", type))
		all_type->ud = (uintmax_t)va_arg(ap, unsigned int);
	else if (size_type == 'z')
		all_type->ud = (uintmax_t)va_arg(ap, size_t);
	else 
		all_type->d = (intmax_t)va_arg(ap, int);
}

void	ft_search_arg(va_list ap, t_type *all_type, char size_type, char type)
{
	if (type == 'D' || type == 'O' || type == 'U')
		ft_arg_modifiy(&size_type, &type);
	if (size_type == 'H' || type == 'c' || type == 'C')
		ft_arg_char(ap, all_type, type);
	if (type == 's' || type == 'S')
		ft_arg_str(ap, all_type, type);
	if (type == 'p')
		ft_arg_ptr(ap, all_type, type);
	if (ft_strchr("diouxX", type))
		ft_arg_int(ap, all_type, size_type, type);
}

int		ft_print_params(va_list ap, t_params params, char type)
{
	t_type all_type;

	ft_search_arg(ap, &all_type, params.size_type, type);
	return (0);
}

int		ft_printf(const char *format, ...)
{
	va_list	ap;
	char	*str;
	int		a;

	va_start(ap, format);
	a = ft_vdprintf(1, format, ap);
	va_end(ap);
	return (0);
}

int 	ft_vdprintf(int fd, const char *format, va_list ap)
{
	t_params	params;
	int 		cur;
	int			ret;

	ret = 0;
	cur = 0;
	while (format[cur])
	{
		if (format[cur] == '%')
		{
			while (format[++cur] && !(ft_strchr(PRINTF_TYPE, format[cur])))
				cur += ft_find_params((char *)(format + cur), &params);
			ret += ft_print_params(ap, params, format[cur]);
			//reset_params(&params);
		}
		else
			ft_putchar(format[cur++]);
	}
	return (ret);
}

int main(int argc, char const *argv[])
{
	char 	*tab;
	long long int test = 5559;

	tab = ft_strdup("lldasdfadsf adsf asdfas ");
 	ft_printf("salut je c'est compter jusqu'a %#d\n", 8);
	return 0;
}