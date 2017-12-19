/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_putnbr_hd.c                                   .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: clcreuso <clcreuso@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2017/12/19 20:41:09 by clcreuso     #+#   ##    ##    #+#       */
/*   Updated: 2017/12/19 20:41:09 by clcreuso    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_hd(short int n)
{
	if (n == MIN_SHORT)
	{
		ft_putchar('-');
		ft_putchar('3');
		ft_putnbr_hd(2768);
		return ;
	}
	if (n < 0)
	{
		ft_putchar('-');
		n = -n;
	}
	if (n >= 10)
	{
		ft_putnbr_hd(n / 10);
		ft_putchar(n % 10 + '0');
	}
	if (n < 10)
		ft_putchar(n + '0');
}