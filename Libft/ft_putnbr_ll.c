/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_putnbr_ll.c                                      .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: clcreuso <clcreuso@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2017/11/24 22:05:19 by clcreuso     #+#   ##    ##    #+#       */
/*   Updated: 2017/11/24 22:05:19 by clcreuso    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_ll(long long int n, int sign)
{
	if ((n + 1) == -9223372036854775807)
	{
		if (sign)
			ft_putchar('-');
		ft_putchar('9');
		ft_putnbr_ll(223372036854775808, sign);
		return ;
	}
	if (n < 0)
	{
		if (sign)
			ft_putchar('-');
		n = -n;
	}
	if (n >= 10)
	{
		ft_putnbr_ll(n / 10, sign);
		ft_putchar(n % 10 + '0');
	}
	if (n < 10)
		ft_putchar(n + '0');
}
