/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_lenuint_max.c                                 .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: clcreuso <clcreuso@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2017/11/24 22:03:12 by clcreuso     #+#   ##    ##    #+#       */
/*   Updated: 2017/11/24 22:03:12 by clcreuso    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

int		ft_lenuint_max(uintmax_t n)
{
	int	ret;

	ret = 1;
	while ((n) && (n /= 10))
		ret++;
	return (ret);
}