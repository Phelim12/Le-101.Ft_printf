/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_putwchar.c                                    .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: clcreuso <clcreuso@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2017/12/23 18:03:48 by clcreuso     #+#   ##    ##    #+#       */
/*   Updated: 2017/12/23 18:03:48 by clcreuso    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_print_utf(unsigned char *str, int cur)
{
	int ret;

	ret = 0;
	while (str[ret])
		write(1, &str[ret++], 1);
	free(str);
	return (ret);
}

int		ft_wchar_two(wchar_t w)
{
	unsigned char *tmp;

	tmp = (unsigned char *)ft_strnew(2);
	tmp[0] = ((w >> 6) | 192);
	tmp[1] = ((w ^ ((w >> 6) << 6)) | 128);
	return (ft_print_utf(tmp, 2));
}

int		ft_wchar_three(wchar_t w)
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

int		ft_wchar_four(wchar_t w)
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

int		ft_putwchar(wchar_t w)
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

int		ft_putwstr(wchar_t *wstr)
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
