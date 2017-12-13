/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_printf.h                                      .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: clcreuso <clcreuso@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2017/12/08 19:51:38 by clcreuso     #+#   ##    ##    #+#       */
/*   Updated: 2017/12/08 19:51:38 by clcreuso    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include "libft/libft.h"

# define PRINTF_TYPE "sSpdDioOuUxXcC%"

typedef struct	s_params
{
	char		flags_hashtag;
	char		flags_zero;
	char		flags_less;
	char		flags_more;
	char		flags_space;
	char		size_type;
	int			size_width;
	int			size_precision;
}				t_params;

typedef struct	s_type
{
	char		c;
	char		*str;
	wchar_t		wc;
	wchar_t		*wstr;
	intmax_t	d;
	uintmax_t	ud;
}				t_type;

int 			ft_vdprintf(int fd, const char *format, va_list ap);

/*
**---------------------------find_params.c-----------------------------------
*/

void			ft_find_flags(char specs, t_params *ptr);
int				ft_find_width(char *specs, t_params *ptr);
int				ft_find_precision(char *specs, t_params *ptr);
int				ft_find_size(char *specs, t_params *ptr);
int				ft_find_params(char *specs, t_params *ptr);


#endif