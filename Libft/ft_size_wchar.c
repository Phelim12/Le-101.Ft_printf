/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_size_wchar.c                                  .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: clcreuso <clcreuso@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2017/12/26 15:06:29 by clcreuso     #+#   ##    ##    #+#       */
/*   Updated: 2017/12/26 15:06:29 by clcreuso    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

int		ft_size_wchar(wchar_t w)
{
	if (w >= 0 && w <= 127)
		return (1);
	if (w >= 128 && w <= 2047)
		return (2);
	if (w >= 2048 && w <= 65535)
		return (3);
	if (w >= 65536 && w <= 2097151)
		return (4);
	return (0);
}