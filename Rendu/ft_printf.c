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

int		ft_arg_c(const char *str, va_list ap, int ret)
{
	unsigned char 	u;
	char			c;

	str += ret;
	if (*str == 'u')
		u = (unsigned char)va_arg(ap, unsigned int);
	else if (*str == 'd' || *str == 'i' || *str == 'o' || *str == 'x' 
		|| *str == 'X' || *str == 'c')
		c = (char)va_arg(ap, int);
	else
		return (0);
	if (*str == 'c')
		ft_putchar(c);
	if (*str == 'i' || *str == 'd')
		ft_putnbr(c);
	if (*str == 'u')
		ft_putnbr(u);
	if (*str == 'o')
		ft_putnbr_base(c, "01234567");
	if (*str == 'x')
		ft_putnbr_base(c, "0123456789abcdef");
	if (*str == 'X')
		ft_putnbr_base(c, "0123456789ABCDEF");
	str++;
	return (ret + 1);
}

int		ft_check_type(const char *str, va_list ap)
{
	int ret;

	ret = 0;
	if (*str == 'c')
		ret = ft_arg_c(str, ap, 0);
	else if (*str == 'd' || *str == 'i' || *str == 'o' || *str == 'u' ||
	 *str == 'x' || *str == 'X')
		ret = ft_arg_d(str, ap, 0);
	return (ret);
}

int		ft_arg_d(const char *str, va_list ap, int ret)
{
	long long int d;
	unsigned long long int u;	

	str += ret;
	printf("%c\n", *(str - 1));
	if (*(str - 1) == 'j' && *str != 'u')
		d = (long long int)va_arg(ap, intmax_t);
	else if (*(str - 1) == 'j' && *str == 'u')
		d = (long long int)va_arg(ap, uintmax_t);
	else if ((ret == 0 || ret == 1) && *str != 'u')
		d = (long long int)va_arg(ap, int);
	else if ((ret == 0 || ret == 1) && *str == 'u')
		d = (long long int)va_arg(ap, unsigned int);
	else if (ret == 2 && *str != 'u')
		d = (long long int)va_arg(ap, long long int);
	else if (ret == 2 && *str == 'u')
		u = (unsigned long long int)va_arg(ap, unsigned long long int);
	if (*str == 'd' || *str == 'i' || *str == 'D')
		ft_putnbr_ll(d);
	if (*str == 'u' || *str == 'U')
		ft_putnbr_llu(u);
	if (*str == 'o' || *str == 'O')
		ft_putnbr_base_ll(d, "01234567");
	if (*str == 'x')
		ft_putnbr_base_ll(d, "0123456789abcdef");
	if (*str == 'X')
		ft_putnbr_base_ll(d, "0123456789ABCDEF");
	return (ret + 1);
}
/*
int		ft_arg_st(const char **str, va_list ap, int ret)
{
	
}

int		ft_check_type(const char **str, va_list ap, int ret)
{

}*/

int		ft_check_size(const char *str, va_list ap)
{
	int ret;
	
	str++;
	ret = 0;
	if (*str == 'h' && *(str + 1) == 'h')
		ret = ft_arg_c(str, ap, 2);
	else if (*str == 'l' && *(str + 1) == 'l')
		ret = ft_arg_d(str, ap, 2);
	else if (*str == 'l')
		ret = ft_arg_d(str, ap, 1);
	else if (*str == 'h')
		ret = ft_arg_d(str, ap, 1);
	else if (*str == 'j')
		ret = ft_arg_d(str, ap, 1);
	/*else if (*str == 'z')
		ret = ft_arg_st(str, ap, 1);*/
	else
		ret = ft_check_type(str, ap);
	return (ret);
}

int		ft_printf(const char *format, ...)
{
	va_list	ap;
	char	*str;
	int		a;

	va_start(ap, format);
	a = ft_vdprintf(1, format, ap);
	return (0);
}

int 	ft_vdprintf(int fd, const char *format, va_list ap)
{
	int		jump;

	while (*format)
	{
		jump = 0;
		if (*format == '%' && *(format + 1) == '%')
		{
			ft_putchar('%');
			format += 2;
		}
		else if (*format == '%')
		{
			if (!(jump = ft_check_size(format, ap)))
				return (0);
			format += (jump + 1);
		}
		else
			ft_putchar(*format++);
	}
	return (0);
}

int main(int argc, char const *argv[])
{
	char 	*tab;
	long long int test = 5559;

	tab = ft_strdup("lldasdfadsf adsf asdfas ");
 	ft_printf("salut le nom de mon ecole est le %jd ien !\n", test);
	return 0;
}