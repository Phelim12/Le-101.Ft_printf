/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   find_params.c                                    .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: clcreuso <clcreuso@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2017/12/08 19:51:08 by clcreuso     #+#   ##    ##    #+#       */
/*   Updated: 2017/12/08 19:51:08 by clcreuso    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

# include "ft_printf.h"

void	ft_find_flags(char specs, t_params *ptr)
{
	if (specs == '#')
		ptr->flags_hashtag = TRUE;
	if (specs == '-')
		ptr->flags_less = TRUE;
	if (specs == '+')
		ptr->flags_more = TRUE;
	if (specs == ' ')
		ptr->flags_space = TRUE;
	if (specs == '0')
		ptr->flags_zero = TRUE;
}

int		ft_find_width(char *specs, t_params *ptr)
{
	int		cursor;
	int 	ret;
	char	*nb;

	ret = 0;
	cursor = 0;
	nb = ft_strnew(32);
	while (ft_isdigit(*(specs + cursor)))
		cursor++;
	ret = (cursor - 1);
	while (--cursor >= 0)
		nb[cursor] = *(specs + cursor);
	ptr->size_width = ft_atoi(nb);
	free(nb);
	return (ret);
}

int		ft_find_precision(char *specs, t_params *ptr)
{
	int		cursor;
	int 	ret;
	char	*nb;

	ret = 0;
	cursor = 0;
	nb = ft_strnew(32);
	while (ft_isdigit(*(specs + cursor)))
		cursor++;
	ret = (cursor - 1);
	while (--cursor >= 0)
		nb[cursor] = *(specs + cursor);
	ptr->size_precision = ft_atoi(nb);
	free(nb);
	return (ret);
}

int		ft_find_size(char *specs, t_params *ptr)
{
	int ret;

	ret = 0;
	if (*specs == 'l' && *(specs + 1) == 'l')
	{
		ptr->size_type = 'L';
		ret = 1;
	}
	else if (*specs == 'h' && *(specs + 1) == 'h')
	{
		ptr->size_type = 'H';
		ret = 1;
	}
	else
		ptr->size_type = *specs;
	return (ret);
}

int		ft_find_params(char *specs, t_params *ptr)
{
	int ret;

	ret = 0;
	if (ft_strchr("#-+ 0", *specs))
		ft_find_flags(*specs, ptr);
	else if (ft_isdigit(*specs))
		ret = ft_find_width(specs, ptr);
	else if (ft_isdigit(*specs) && *(specs - 1) == '.')
		ret = ft_find_precision(specs, ptr);
	else if (ft_strchr("hjlz", *specs))
		ret = ft_find_size(specs, ptr);
	return (ret);
}