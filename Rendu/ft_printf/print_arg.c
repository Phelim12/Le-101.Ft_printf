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

int 	ft_print_str(t_type all_type, char type)
{
	if (type == 's')
	{
		ft_putstr(all_type.str);
		return (ft_strlen(all_type.str));
	}
	if (type == 'S')
	{
		//ft_putstr(all_type.wstr);
		//return (ft_strlen(all_type.wstr));
	}
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
	{
		//ft_putchar(all_type.wc);
		return (4);
	}
	return (0);
}

int 	ft_print_int(t_type all_type, char type, int ret)
{
	if (type == 'd' || type == 'i')
	{
		ft_putnbr_ll(all_type.d);
		ret = ft_lenint_max(all_type.d);	
	}
	else if (type == 'u')
	{
		ft_putnbr_llu(all_type.ud);
		ret = ft_lenuint_max(all_type.ud);
	}
	else if (type == 'o')
	{
		ft_putnbr_base_ll(all_type.d, "01234567");
		ret = ft_len_base_ll(all_type.d, "01234567");
	}
	else if (type == 'x')
	{
		ft_putnbr_base_ll(all_type.d, "0123456789abcdef");
		ret = ft_len_base_ll(all_type.d, "0123456789abcdef");
	}
	else if (type == 'X')
	{
		ft_putnbr_base_ll(all_type.d, "0123456789ABCDEF");
		ret = ft_len_base_ll(all_type.d, "0123456789ABCDEF");
	}
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
		ret = ft_print_int(all_type, type, 0);
	return (ret);
}

int		ft_print_width(t_params flags)
{
	int ret;

	ret = 0;
	while (flags.size_width > 0)
	{
		ret++;
		if (flags.flag_zero == TRUE)
			ft_putchar('0');
		else
			ft_putchar(' ');
		flags.size_width--;
	}
	return (ret);
}

int 	ft_print_prefix(char type)
{
	if (type == 'X')
	{
		ft_putstr("0X");
		return (2);
	}
	if (type == 'x')
	{
		ft_putstr("0x");
		return (2);
	}
	if (type == 'o')
		ft_putchar('0');
	if (type == 'O')
		ft_putchar('0');
	return (1);
}

int		ft_print_flags(t_type all_type, t_params flags, char type)
{
	int ret;

	ret = 0;
	flags.size_width -= ft_len_arg(all_type, flags, type);
	if (flags.flag_less == FALSE && flags.size_width > 0)
		ret += ft_print_width(flags);
	if (flags.flag_hashtag == TRUE && ft_strchr("OoXx", type))
		ret += ft_print_prefix(type);
	if (ft_strchr("Ddi", type) && flags.flag_space && !flags.flag_less && all_type.d >= 0 && !ret && !ret++)
		ft_putchar(' ');
	ret += ft_print_arg(all_type, flags, type);
	if (flags.flag_less == TRUE && flags.size_width > 1)
		ret += ft_print_width(flags);
	return (ret);
}

int		ft_print_params(va_list ap, t_params flags, char type)
{
	t_type all_type;

	reset_all_type(&all_type);
	ft_search_arg(ap, &all_type, &flags, type);
	return (ft_print_flags(all_type, flags, type));
}