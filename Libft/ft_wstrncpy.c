/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_wstrncpy.c                                    .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: clcreuso <clcreuso@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2017/12/26 14:54:11 by clcreuso     #+#   ##    ##    #+#       */
/*   Updated: 2017/12/26 14:54:11 by clcreuso    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

wchar_t	*ft_wstrncpy(wchar_t *d, const wchar_t *s, size_t n)
{
	unsigned int cur;
	unsigned int a;

	a = 0;
	cur = 0;
	while (s[cur] && ((a + ft_size_wchar(s[cur])) <= n))
	{
		d[cur] = s[cur];
		a += ft_size_wchar(s[cur]);
		cur++;
	}
	while (a < n)
	{
		d[cur] = '\0';
		a += ft_size_wchar(s[cur]);
		cur++;
	}
	return (d);
}
