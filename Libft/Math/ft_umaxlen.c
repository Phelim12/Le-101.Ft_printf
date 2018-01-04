/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_umaxlen.c                                     .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: clcreuso <clcreuso@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/01/04 15:12:33 by clcreuso     #+#   ##    ##    #+#       */
/*   Updated: 2018/01/04 15:12:33 by clcreuso    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */
 
#include "libft.h"

int	ft_umaxlen(uintmax_t n)
{
	return (ft_umaxlen_base(n, 10));
}
