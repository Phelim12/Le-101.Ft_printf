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
 	char test;

 	test = 0;
	printf("    ft_printf = %d   \n", ft_printf("@moulitest: {% 4.5i}", 42));
	printf("    printf = %d   ", printf("@moulitest: {% 4.5i}", 42));
	return (0);
}