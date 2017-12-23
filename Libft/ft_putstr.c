/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_putstr.c                                      .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: clcreuso <clcreuso@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2017/11/24 22:05:28 by clcreuso     #+#   ##    ##    #+#       */
/*   Updated: 2017/11/24 22:05:28 by clcreuso    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

int		ft_putstr(char const *s)
{
	int i;

	i = 0;
	if (!s)
		return (0);
	while (*s)
		i += ft_putchar(*s++);
	return (i);	
}