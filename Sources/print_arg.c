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

# include "ft_printf.h"
# include <stdio.h>

int		ft_print_utf(unsigned char *str, int cur)
{
	int ret;

	ret = 0;
	while (str[ret])
		write(1, &str[ret++], 1);
	free(str);
	return (ret);
}
//3 octet
// 2048 a 4095 = 101 o2
// 53248 a 55295 = 100
// 4 octet
// 65536 a 131071 = 1001
// 131072 a 262143 = 101
// 1048576 a 1114111 = 1000
int 	ft_wchar_two(wchar_t w)
{
	unsigned char *tmp;

	tmp = (unsigned char *)ft_strnew(2);
	tmp[0] = ((w >> 6) | 192);
	tmp[1] = ((w ^ ((w >> 6) << 6)) | 128);
	return (ft_print_utf(tmp, 2));
}

int 	ft_wchar_three(wchar_t w)
{
	unsigned char *tmp;

	tmp = (unsigned char *)ft_strnew(3);
	tmp[0] = ((w >> 12) | 224);
	if (w >= 2048 && w <= 4095)
		tmp[1] = ((w >> 6) | 160);
	else if (w >= 53248 && w <= 55295)
		tmp[1] = (((w >> 6) ^ 832) | 128);
	else
		tmp[1] = ((((w >> 6) ^ ((w >> 12) << 6))) | 128);
	tmp[2] = ((w ^ ((w >> 6) << 6)) | 128);
	return (ft_print_utf(tmp, 3));
}

int 	ft_wchar_four(wchar_t w)
{
	unsigned char *tmp;

	tmp = (unsigned char *)ft_strnew(4);
	tmp[0] = ((w >> 18) | 240);
	if (w >= 65536 && w <= 131071)
		tmp[1] = (((w >> 12) ^ 32) | 128);
	else if (w >= 131072 && w <= 262143)
		tmp[1] = (((w >> 12) ^ 64) | 128);
	else if (w >= 1048576 && w <= 1114111)
		tmp[1] = ((((w >> 12) ^ 256)) | 128);
	else
		tmp[1] = ((((w >> 12) ^ ((w >> 18) << 6))) | 128);
	tmp[2] = ((((w >> 6) ^ ((w >> 12) << 6))) | 128);
	tmp[3] = ((w ^ ((w >> 6) << 6)) | 128);
	return (ft_print_utf(tmp, 4));
}

int 	ft_putwchar(wchar_t w)
{
	if (w >= 0 && w <= 127)
		return (ft_putchar((char)w));
	else if (w >= 128 && w <= 2047)
		return (ft_wchar_two(w));
	else if (w >= 2048 && w <= 65535)
		return (ft_wchar_three(w));
	else if (w >= 65536 && w <= 2097151)
		return (ft_wchar_four(w));
	return (0);
}

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

int 	ft_print_str(t_type all_type, t_params flags, char type)
{
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

int 	ft_print_char(t_type all_type, char type)
{
	if (type == 'c')
		return (ft_putchar(all_type.c));
	if (type == 'C')
		return (ft_putwchar(all_type.wc));
	return (0);
}

int 	ft_print_minx(uintmax_t ud, t_params flags)
{
	int ret;

	if (flags.size_type == 'j' || flags.size_type == 'l' || flags.size_type == 'L')
		ret = ft_putnbr_base_llu(ud, "0123456789abcdef");
	else
		ret = ft_putnbr_base_u(ud, "0123456789abcdef");
	if (ret == -1 && flags.flag_point == FALSE)
		return (ft_putchar('0'));
	if (ret == -1 && flags.flag_point == TRUE)
		return (0);
	return (ret);
}

int 	ft_print_majx(uintmax_t ud, t_params flags)
{
	int ret;

	if (flags.size_type == 'j' || flags.size_type == 'l' || flags.size_type == 'L')
		ret = ft_putnbr_base_llu(ud, "0123456789ABCDEF");
	else
		ret = ft_putnbr_base_u(ud, "0123456789ABCDEF");
	if (ret == -1 && flags.flag_point == FALSE)
		return (ft_putchar('0'));
	if (ret == -1 && flags.flag_point == TRUE)
		return (0);
	return (ret);
}


int 	ft_print_octal(uintmax_t ud, t_params flags)
{
	int ret;

	if (flags.size_type == 'j' || flags.size_type == 'l' || flags.size_type == 'L')
		ret = ft_putnbr_base_llu(ud, "01234567");
	else
		ret = ft_putnbr_base_u(ud, "01234567");
	if (ret == -1 && flags.flag_point == FALSE)
	{
		if (flags.flag_hashtag == TRUE)
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
		ret = ft_print_octal(all_type.ud, flags);
	else if (type == 'x')
		ret = ft_print_minx(all_type.ud, flags);
	else if (type == 'X')
		ret = ft_print_majx(all_type.ud, flags);
	return (ret);
}

int		ft_print_arg(t_type all_type, t_params flags, char type)
{
	int ret;

	ret = 0;
	if (type == '%')
		return (ft_putchar('%'));
	if (type == 's' || type == 'S')
		ret = ft_print_str(all_type, flags, type);
	else if (type == 'c' || type == 'C')
		ret = ft_print_char(all_type, type);
	else if (ft_strchr("diouxX", type))
		ret = ft_print_int(all_type, flags, type, 0);
	return (ret);
}