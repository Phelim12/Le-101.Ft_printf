/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_size_int.c                                    .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: clcreuso <clcreuso@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2017/11/24 22:05:43 by clcreuso     #+#   ##    ##    #+#       */
/*   Updated: 2017/11/24 22:05:43 by clcreuso    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../Includes/libft.h"

int		ft_size_int(int n)
{
	int a;
	int size;

	a = 1;
	size = 0;
	if (n < 0)
	{
		n = -n;
		a = 0;
	}
	while ((n /= 10) > 1)
		size++;
	if (a == 0)
		return (size + 2);
	return (size + 1);
}