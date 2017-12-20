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

int main()
{
 	char test;

 	test = 0;
	printf("    ft_printf = %d   \n", ft_printf("@moulitest: %5.d %5.0d", 0, 0));
	printf("    printf = %d   ", printf("@moulitest: %5.d %5.0d", 0, 0));
	return (0);
}