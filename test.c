
/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   test.c                                           .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: clcreuso <clcreuso@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2017/12/21 20:26:33 by clcreuso     #+#   ##    ##    #+#       */
/*   Updated: 2017/12/21 20:26:33 by clcreuso    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "Sources/ft_printf.h"
#include <limits.h>
#include <locale.h>

int main(int argc, char const *argv[])
{
	setlocale(LC_ALL, "en_US.UTF-8");
	//char c;

	ft_printf("%x\n", 505);
	return 0;
}