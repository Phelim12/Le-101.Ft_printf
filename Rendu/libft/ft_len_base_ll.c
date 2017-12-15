/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_putnbr_base_ll.c                              .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: clcreuso <clcreuso@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2017/12/12 19:16:44 by clcreuso     #+#   ##    ##    #+#       */
/*   Updated: 2017/12/12 19:16:44 by clcreuso    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

int		ft_len_base_ll(intmax_t nbr, char *base)
{
	char str[256];
	int neg;
	int a;
	int b;

	b = 0;
	neg = 1;
	a = ft_strlen(base);
	if (nbr < 0)
	{	
		nbr = -nbr;
		neg = -1;
	}
	while (nbr >= 1)
	{
		str[b] = base[nbr % a];
		nbr /= a;
		b++;
	}
	str[b] = '\0';
	if (ft_check_base(base, 0, 1) && neg == -1)
		return (ft_strlen(str) + 1);
	else
		return (ft_strlen(str));
}
