/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inunez-g <inunez-g@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/26 11:08:17 by inunez-g          #+#    #+#             */
/*   Updated: 2023/09/26 11:24:55 by inunez-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/cub3d.h"

void	print_list( t_var *vars )
{
	t_list	*tmp;

	tmp = vars->lst_map;
	while (tmp)
	{
		printf("%s", tmp->line);
		tmp = tmp->next;
	}
}

void	print_2dstr( char **str )
{
	int	i;

	i = -1;
	while (str[++i])
		printf("string: <%s>\n", str[i]);
}
