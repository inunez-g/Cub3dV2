/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inunez-g <inunez-g@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/26 11:08:08 by inunez-g          #+#    #+#             */
/*   Updated: 2023/09/26 11:30:47 by inunez-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/cub3d.h"

/*
 * Recorrer la linea
 */
void	get_map_index( t_var *vars )
{
	int	i;
	int	j;

	i = -1;
	while (vars->map[++i])
	{
		j = 0;
		while (ft_isspace(vars->map[i][j]))
			j++;
		if (!ft_isspace(vars->map[i][j]) && ft_isdigit(vars->map[i][j]))
		{
			vars->map_index = i;
			break ;
		}
	}
}

void	add_texture( char **texture, t_var *vars)
{
	if (!ft_strcmp(texture[0], "NO"))
		vars->textures->no = ft_strdup(texture[1]);
	else if (!ft_strcmp(texture[0], "SO"))
		vars->textures->so = ft_strdup(texture[1]);
	else if (!ft_strcmp(texture[0], "EA"))
		vars->textures->ea = ft_strdup(texture[1]);
	else if (!ft_strcmp(texture[0], "WE"))
		vars->textures->we = ft_strdup(texture[1]);
	else if (!ft_strcmp(texture[0], "C"))
		vars->textures->c = ft_strdup(texture[1]);
	else if (!ft_strcmp(texture[0], "F"))
		vars->textures->f = ft_strdup(texture[1]);
}

void	check_textures( t_var *vars )
{
	int		i;
	char	**texture;

	i = 0;
	while (i < vars->map_index)
	{
		if (!ft_strcmp(vars->map[i], "\n"))
		{
			i++;
			continue ;
		}
		texture = split_textures(vars->map[i], vars);
		print_2dstr(texture);
		if (!texture)
			process_error(INVALID_TEXTURE, vars);
		add_texture(texture, vars);
		free_2dstr(texture);
		texture = NULL;
		i++;
	}
}

void	texture_filled_checker(t_var *vars)
{
	if (!vars->textures->no || !vars->textures->so || !vars->textures->we || !vars->textures->ea || !vars->textures->f || !vars->textures->c)
		process_error(INVALID_TEXTURE, vars);
	printf("Bien\n");
}

int check_top(t_var	*vars, int	j, int	i)
{
	printf("check: %d\n", (int)ft_strlen(vars->map[j - 1]));
	if (((int)ft_strlen(vars->map[j - 1]) <= i) || !vars->map[j - 1][i] || (vars->map[j - 1][i] != '0' && vars->map[j - 1][i] != '1' && vars->map[j - 1][i] != 'N' && vars->map[j - 1][i] != 'S' && vars->map[j - 1][i] != 'E' && vars->map[j - 1][i] != 'W'))
	{
		printf("OPCION_TOP\n");
		return(1);
	}
	return(0);
}

int	ft_2dstrlen(char **str)
{
	int	len;

	len = 0;
	while (str[len])
		len++;
	return(len);
}

int check_bottom(t_var *vars, int	j, int	i)
{
	if (j == ft_2dstrlen(vars->map) - 1)
	{
		printf("OPCION_BOT_LASTLINE\n");
		return(1);
	}
    if (!vars->map[j + 1][i] || (vars->map[j + 1][i] != '0' && vars->map[j + 1][i] != '1' && vars->map[j + 1][i] != 'N' && vars->map[j + 1][i] != 'S' && vars->map[j + 1][i] != 'E' && vars->map[j + 1][i] != 'W'))
	{
		printf("OPCION_BOT\n");
        return(1);
	}
    return(0);
}

int check_right(t_var	*vars, int	j, int	i)
{
    if (!vars->map[j][i + 1] || (vars->map[j][i + 1] != '0' && vars->map[j][i + 1] != '1' && vars->map[j][i + 1] != 'N' && vars->map[j][i + 1] != 'S' && vars->map[j][i + 1] != 'E' && vars->map[j][i + 1] != 'W'))
	{
		printf("OPCION_RIGHT\n");
        return (1);
	}
	return(0);
}

int check_left(t_var *vars, int j , int i)
{
    if (!vars->map[j][i - 1] || (vars->map[j][i - 1] != '0' && vars->map[j][i - 1] != '1' && vars->map[j][i - 1] != 'N' && vars->map[j][i - 1] != 'S' && vars->map[j][i - 1] != 'E' && vars->map[j][i - 1] != 'W'))
	{
		printf("OPCION_LEFT\n");
        return(1);
	}
    return(0);
}

int check_top_left(t_var *vars, int j , int i)
{
	if (!vars->map[j - 1][i - 1] || vars->map[j - 1][i - 1] == '\n' || vars->map[j - 1][i - 1] == ' ')
	{
		printf("OPCION_TOP_LEFT\n");
        return(1);
	}
	return(0);
}

int check_top_right(t_var *vars, int j , int i)
{
	if (!vars->map[j - 1][i + 1] || vars->map[j - 1][i + 1] == '\n' || vars->map[j - 1][i + 1] == ' ')
	{
		printf("OPCION_TOP_RIGHT\n");
        return(1);
	}
	return(0);
}

int check_bottom_left(t_var *vars, int j , int i)
{
	if (!vars->map[j + 1][i - 1] || vars->map[j + 1][i - 1] == '\n' || vars->map[j + 1][i - 1] == ' ')
	{
		printf("OPCION_BOTTOM_LEFT\n");
        return(1);
	}
	return(0);
}

int check_bottom_right(t_var *vars, int j , int i)
{
	if (!vars->map[j + 1][i + 1] || vars->map[j + 1][i + 1] == '\n' || vars->map[j + 1][i + 1] == ' ')
	{
		printf("OPCION_BOTTOM_RIGHT\n");
        return(1);
	}
	return(0);
}

void	check_player(t_var *vars, int j, int i, char	direction)
{
	if (vars->player->found == 1)
		process_error(INVALID_FILE, vars);
	else
	{
		vars->player->found = 1;
		vars->player->x = j;
		vars->player->y = i;
		vars->player->dir = direction;
	}
}

void    check_borders(t_var *vars)
{
    int i = 0;
    int j = 0;
	
	j = vars->map_index;
    while (vars->map[j])
    {
        i = 0;
		if (vars->map[j][0] == '\n' || vars->map[j][0] == '\0')
			process_error(INVALID_MAP, vars);
        while (vars->map[j][i])
        {
            if (vars->map[j][i] == '0' || vars->map[j][i] == 'N' || vars->map[j][i] == 'S' || vars->map[j][i] == 'E' || vars->map[j][i] == 'W')
            {
				if (vars->map[j][i] == 'N' || vars->map[j][i] == 'S' || vars->map[j][i] == 'E' || vars->map[j][i] == 'W')
					check_player(vars, j, i, vars->map[j][i]);
                if (check_top(vars, j , i) || check_bottom(vars, j , i) || check_right(vars, j , i) || check_left(vars, j , i) || check_top_left(vars, j , i) || check_top_right(vars, j , i) || check_bottom_left(vars, j , i) || check_bottom_right(vars, j , i))
                    process_error(INVALID_MAP, vars);
            }
            else
            {
                if (vars->map[j][i] != '1' && vars->map[j][i] != ' ' && vars->map[j][i] != '\n')
                    process_error(INVALID_MAP, vars);
            }
            i++;
        }
        j++;
    }
	if (vars->player->found == 0)
		process_error(INVALID_MAP, vars);
}

int	main( int argc, char **argv )
{
	t_var	vars;

	if (argc == 2)
	{
		init(&vars);
		get_map(argv[1], &vars);
		get_map_index(&vars);
		check_textures(&vars);
		texture_filled_checker(&vars);
		print_2dstr(vars.map);
		check_borders(&vars);
		printf("BIEN\n");

		
		//printf("map = %s\n", vars.map[vars.map_index]);
		//printf("index = %d, %s\n", vars.map_index, vars.map[vars.map_index]);
		return (1);
	}
	process_error(INVALID_PARAMS, &vars);
	return (0);
}