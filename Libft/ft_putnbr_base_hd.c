/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_putnbr_base_hd.c                              .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: clcreuso <clcreuso@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2017/12/21 21:41:58 by clcreuso     #+#   ##    ##    #+#       */
/*   Updated: 2017/12/21 21:41:58 by clcreuso    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

int		ft_putnbr_base_hd(short int nbr, char *base)
{
	char str[256];
	int neg;
	int a;
	int b;

	b = 0;
	neg = 1;
	a = ft_strlen(base);
	while (nbr >= 1)
	{
		str[b] = base[nbr % a];
		nbr /= a;
		b++;
	}
	str[b] = '\0';
	if (ft_check_base(base, 0, 1))
		ft_print_base(str, neg);
	if (ft_strlen(str) == 0)
		return (-1);
	return (ft_strlen(str));
}
