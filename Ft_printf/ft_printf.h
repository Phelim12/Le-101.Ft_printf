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

# include <stdio.h>
# include <stdarg.h>
# include "../Libft/libft.h"

# define PRINTF_TYPE "sSpdDioOuUxXcC%"
# define PRINTF_SPECS "#0-+ 123456789.hljz"


/*┏━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┓*/
/*┃         This structure groups all the parameters of the argument        ┃*/
/*┃                           passed to ft_printf                           ┃*/
/*┗━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┛*/

typedef struct	s_params
{
	char		flag_hashtag;
	char		flag_space;
	char		flag_zero;
	char		flag_less;
	char		flag_more;
	char		flag_point;
	char		size_type;
	char        new_type;
	int			print_sign;
	int			print_prefix;
	int			size_width;
	int			size_precision;
	int			len_arg;
}				t_params;

/*┏━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┓*/
/*┃      This structure groups all the types of variables that will be      ┃*/
/*┃                        used when using ft_printf                        ┃*/
/*┗━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┛*/

typedef struct	s_type
{
	char		c;
	char		*str;
	wchar_t		wc;
	wchar_t		*wstr;
	intmax_t	d;
	uintmax_t	ud;
}				t_type;

int 	ft_putwchar(wchar_t w);

/*┏━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┓*/
/*┃                               ft_printf.c                               ┃*/
/*┗━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┛*/

int				ft_printf(const char *format, ...);
int				ft_vdprintf(int fd, const char *format, va_list ap);

/*┏━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┓*/
/*┃                              find_params.c                              ┃*/
/*┗━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┛*/

void			ft_find_flags(char specs, t_params *ptr);
int				ft_find_width(char *specs, t_params *ptr);
int				ft_find_precision(char *specs, t_params *ptr);
int				ft_find_size(char *specs, t_params *ptr);
int				ft_find_params(char *specs, t_params *ptr);

/*┏━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┓*/
/*┃                              search_arg.c                               ┃*/
/*┗━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┛*/

void			ft_arg_int(va_list ap, t_type *all_type, char size_type, char type);
void			ft_search_arg(va_list ap, t_type *all_type, t_params *p, char type);
void			ft_arg_ll(va_list ap, t_type *all_type, char size_type, char type);
void			ft_arg_char(va_list ap, t_type *all_type, char type);
void			ft_arg_str(va_list ap, t_type *all_type, char type);

/*┏━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┓*/
/*┃                                 reset.c                                 ┃*/
/*┗━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┛*/

void			reset_all_type(t_type *all_type);
t_params		reset_params(int *ptr1, int *ptr2, int first);

/*┏━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┓*/
/*┃                               print_arg.c                               ┃*/
/*┗━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┛*/

int 			ft_print_str(t_type all_type, char type);
int 			ft_print_char(t_type all_type, char type);
int				ft_print_arg(t_type all_type, t_params flags, char type);
int 			ft_print_int(t_type all_type, t_params flags, char type, int ret);

/*┏━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┓*/
/*┃                                len_arg.c                                ┃*/
/*┗━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┛*/

int				ft_len_conv(t_type all_type, t_params flags, char type);
int				ft_len_arg(t_type all_type, t_params flags, char type);

/*┏━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┓*/
/*┃                              print_params.c                             ┃*/
/*┗━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┛*/

int				ft_print_width(t_type all_type, t_params *flags, char type);
int				ft_print_prefix(t_type a, t_params *flags, char type);
int				ft_print_flags(t_type all_type, t_params flags, char tydpe);
int				ft_print_params(va_list ap, t_params flags, char type);

#endif