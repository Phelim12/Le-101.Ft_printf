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
		if (all_type.str == NULL)
		{
			ft_putstr("(null)");
			return (6);
		}
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
		ft_putnbr_ll(all_type.d);
		ret = ft_lenint_max(all_type.d);	
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