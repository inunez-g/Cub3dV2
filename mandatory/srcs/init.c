/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inunez-g <inunez-g@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/26 11:08:02 by inunez-g          #+#    #+#             */
/*   Updated: 2023/09/26 11:38:52 by inunez-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/cub3d.h"

void    init(t_var  *vars)
{
    vars->textures = (t_textures *)malloc(sizeof(t_textures));
    vars->textures->so = NULL;
    vars->textures->ea = NULL;
    vars->textures->we = NULL;
    vars->textures->f = NULL;
    vars->textures->c = NULL;
    vars->textures->filled = 0;
    vars->lst_map = NULL;
    vars->lines = 0;
    vars->player = (t_player *)malloc(sizeof(t_player));
    vars->player->x = 0;
    vars->player->y = 0;
    vars->player->dir = '\0';
    vars->player->found = 0;
}
