/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_ulen.c                                        .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: clcreuso <clcreuso@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/01/04 15:10:43 by clcreuso     #+#   ##    ##    #+#       */
/*   Updated: 2018/01/04 15:10:43 by clcreuso    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

int	ft_ulen(unsigned int n)
{
	return (ft_ulen_base(n, 10));
}