/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_str_is_num.c                                  .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: clcreuso <clcreuso@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2017/12/17 17:43:48 by clcreuso     #+#   ##    ##    #+#       */
/*   Updated: 2017/12/17 17:43:48 by clcreuso    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../Includes/libft.h"

int		ft_str_is_num(const char *str)
{
	int a;

	a = 0;
	while (str[a])
		if (ft_isdigit(str[a]))
			a++;
		else
			return (0);
	return (1);
}
