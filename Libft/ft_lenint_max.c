/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_lenint_max.c                                  .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: clcreuso <clcreuso@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2017/11/24 22:03:12 by clcreuso     #+#   ##    ##    #+#       */
/*   Updated: 2017/11/24 22:03:12 by clcreuso    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

int		ft_lenint_max(intmax_t n, int sign)
{
	int	ret;

	ret = 1;
	if (n < 0 && sign)
		ret++;
	while ((n) && (n /= 10))
		ret++;
	return (ret);
}
