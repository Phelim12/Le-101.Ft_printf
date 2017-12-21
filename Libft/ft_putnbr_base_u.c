/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_putnbr_base_u.c                              .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: clcreuso <clcreuso@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2017/12/12 19:16:44 by clcreuso     #+#   ##    ##    #+#       */
/*   Updated: 2017/12/12 19:16:44 by clcreuso    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

void	ft_print_base(char *str, int neg)
{
	int a;

	if (neg < 0)
		ft_putchar('-');
	a = ft_strlen(str);
	a--;
	while (str[a])
	{
		ft_putchar(str[a]);
		a--;
	}
}

int		ft_check_base(char *base, int a, int b)
{
	if (ft_strlen(base) == 1)
		return (0);
	while (base[b])
	{
		if (base[a] == base[b])
			return (0);
		if (base[b] == '+' || base[b] == '-')
			return (0);	
		b++;
	}
	return (1);
}

void	ft_putnbr_base_u(unsigned int nbr, char *base)
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
}
