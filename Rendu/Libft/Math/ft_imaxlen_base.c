/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_imaxlen_base.c                                .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: clcreuso <clcreuso@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/01/04 15:15:27 by clcreuso     #+#   ##    ##    #+#       */
/*   Updated: 2018/01/04 15:15:27 by clcreuso    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

int	ft_imaxlen_base(intmax_t n, int base)
{
	int	i;

	i = 1;
	while (n /= base)
		i++;
	return (i);
}
