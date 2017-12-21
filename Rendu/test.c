/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   test.c                                           .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: clcreuso <clcreuso@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2017/12/15 19:22:37 by clcreuso     #+#   ##    ##    #+#       */
/*   Updated: 2017/12/15 19:22:37 by clcreuso    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

# include "Libft/libft.h"
# include <wchar.h>
# include "Ft_printf/ft_printf.h"

int ft_printf(char const *str, ...);

int main(void)
{
	int a = 0;
	int test = 24;
	printf("%d", ft_printf("%S", L"Á±≥"));
	printf("%d", printf("%S", L"Á±≥"));

	return (0);
}