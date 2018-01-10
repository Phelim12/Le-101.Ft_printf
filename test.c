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

# include "Includes/libft.h"
# include <wchar.h>
# include "Sources/ft_printf.h"

int main()
{
 	setlocale(P_ALL, "en_US.UTF-8");
	wchar_t c;
	printf("    ft_printf = %d   \n", ft_printf("{à}"));
	printf("    printf = %d   ", printf("{à}"));
	return (0);
}