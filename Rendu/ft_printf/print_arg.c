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

	ret = cur;
	while (cur >= 0)
		write(1, &str[cur--], 1);
	return (ret);
}

int 	ft_wchar_two(wchar_t w)
{
	unsigned char *tmp;

	tmp = (unsigned char *)ft_strnew(2);
	tmp[1] = ((w >> 6) | 192);
	if (w)
		tmp[0] = ((w ^ ((w >> 6) << 6)) | 128);
	return (ft_print_utf(tmp, 2));
}

int 	ft_wchar_three(wchar_t w)
{
	unsigned char *tmp;

	tmp = (unsigned char *)ft_strnew(3);
	tmp[2] = ((w >> 12) | 224);
	if (w >> 6)
		tmp[1] = ((((w >> 6) ^ ((w >> 12) << 6))) | 128);
	if (w)
		tmp[0] = ((w ^ ((w >> 6) << 6)) | 128);
	return (ft_print_utf(tmp, 3));
}

int 	ft_wchar_four(wchar_t w)
{
	unsigned char *tmp;

	tmp = (unsigned char *)ft_strnew(4);
	tmp[3] = ((w >> 18) | 240);
	if (w >> 12)
		tmp[2] = ((((w >> 12) ^ ((w >> 18) << 6))) | 128);
	if (w >> 6)
		tmp[1] = ((((w >> 6) ^ ((w >> 12) << 6))) | 128);
	if (w)
		tmp[0] = ((w ^ ((w >> 6) << 6)) | 128);
	return (ft_print_utf(tmp, 4));
}

int 	ft_putwchar(wchar_t w)
{
	if (w >= 1 && w <= 127)
	{
		ft_putchar((char)w);
		return (1);
	}
	else if (w >= 128 && w <= 2047)
		return (ft_wchar_two(w));
	else if (w >= 2048 && w <= 65535)
		return (ft_wchar_three(w));
	else if (w >= 65536 && w <= 2097151)
		return (ft_wchar_four(w));
	return (0);
}

int 	ft_putwstr(wchar_t *wstr)
{
	int ret;
	int cur;

	ret = 0;
	cur = 0;
	while (wstr[cur])
	{
		ret += ft_putwchar(wstr[cur]);
		cur++;
	}
	return (ret);
}

int 	ft_print_str(t_type all_type, char type)
{
	if (type == 's')
	{
		if (all_type.str == NULL)
		{
			ft_putstr("(null)");
			return (6);
		}
		ft_putstr(all_type.str);
		return (ft_strlen(all_type.str));
	}
	if (type == 'S')
		return (ft_putwstr(all_type.wstr));
	return (0);
}

int 	ft_print_char(t_type all_type, char type)
{
	if (type == 'c')
	{
		ft_putchar(all_type.c);
		return (1);
	}
	if (type == 'C')
		return (ft_putwchar(all_type.wc));
	return (0);
}

int 	ft_print_majx(intmax_t d, t_params flags)
{
	int ret;

	ret = 1;
	if (d == 0 && flags.flag_point == FALSE)
		ft_putchar('0');
	else if (flags.size_type == 'L' || flags.size_type == 'j')
	{
		ft_putnbr_base_llu((uintmax_t)d, "0123456789ABCDEF");
		ret = ft_len_base_llu((uintmax_t)d, "0123456789ABCDEF");
	}
	else
	{
		ft_putnbr_base_u((unsigned int)d, "0123456789ABCDEF");
		ret = ft_len_base_u((unsigned int)d, "0123456789ABCDEF");
	}
	return (ret);
}

int 	ft_print_minx(intmax_t d, t_params flags)
{
	int ret;

	ret = 1;
	if (d == 0 && flags.flag_point == FALSE)
		ft_putchar('0');
	else if (flags.size_type == 'L' || flags.size_type == 'j' || flags.size_type == 'l')
	{
		ft_putnbr_base_llu((uintmax_t)d, "0123456789abcdef");
		ret = ft_len_base_llu((uintmax_t)d, "0123456789abcdef");
	}
	else
	{
		ft_putnbr_base_u((unsigned long int)d, "0123456789abcdef");
		ret = ft_len_base_u((unsigned int)d, "0123456789abcdef");
	}
	return (ret);
}

int 	ft_print_octal(intmax_t d, t_params flags)
{
	int ret;

	ret = 1;
	if (d == 0 && flags.flag_point == FALSE)
		ft_putchar('0');
	else if (flags.size_type == 'L' || flags.size_type == 'j')
	{
		ft_putnbr_base_llu((uintmax_t)d, "01234567");
		ret = ft_len_base_llu((uintmax_t)d, "01234567");
	}
	else
	{
		ft_putnbr_base_u((unsigned int)d, "01234567");
		ret = ft_len_base_u((unsigned int)d, "01234567");
	}
	return (ret);
}

int 	ft_print_int(t_type all_type, t_params flags, char type, int ret)
{
	if (type == 'd' || type == 'i')
	{
		if (flags.flag_point == TRUE && all_type.d == 0)
			return (0);
		if (flags.size_type == 'h')
			ft_putnbr_hd(all_type.d, 0);
		else
			ft_putnbr_ll(all_type.d, 0);
		ret = ft_lenint_max(all_type.d, 0);	
	}
	else if (type == 'u')
	{
		ft_putnbr_llu(all_type.ud);
		ret = ft_lenuint_max(all_type.ud);
	}
	else if (type == 'o')
		ret = ft_print_octal(all_type.d, flags);
	else if (type == 'x')
		ret = ft_print_minx(all_type.d, flags);
	else if (type == 'X')
		ret = ft_print_majx(all_type.d, flags);
	return (ret);
}

int		ft_print_arg(t_type all_type, t_params flags, char type)
{
	int ret;

	ret = 0;
	if (type == '%')
	{
		ft_putchar('%');
		return (1);
	}
	if (flags.new_type)
		type = flags.new_type;
	if (type == 's' || type == 'S')
		ret = ft_print_str(all_type, type);
	else if (type == 'c' || type == 'C')
		ret = ft_print_char(all_type, type);
	else if (ft_strchr("diouxX", type))
		ret = ft_print_int(all_type, flags, type, 0);
	return (ret);
}