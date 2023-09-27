/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split_textures.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inunez-g <inunez-g@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/26 11:08:21 by inunez-g          #+#    #+#             */
/*   Updated: 2023/09/26 11:26:39 by inunez-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/cub3d.h"
#include <fcntl.h>

/*
 * GET TEXTURES.SPLIT. CHECKEO DE VALORES 
 */
static int	count_values( char *str )
{
	int	i;
	int	len;

	i = 0;
	len = 0;
	if (!str)
		return (-1);
	while (str[i])
	{
		while (ft_isspace(str[i]) && str[i])
			i++;
		if (!ft_isspace(str[i]) && str[i])
		{
			len++;
			while (!ft_isspace(str[i]) && str[i])
				i++;
		}
	}
	return (len);
}

static char	*splitdup(const char *s, size_t start, size_t finish)
{
	char	*dest;
	size_t	i;

	i = 0;
	dest = (char *)malloc(sizeof(char) * (finish - start + 1));
	if (!dest)
		return (NULL);
	while (start < finish)
		dest[i++] = s[start++];
	dest[i] = '\0';
	return (dest);
}

char	**fill_textures( char *str, char **dst )
{
	int	i;
	int	start;
	int	j;

	i = 0;
	j = 0;
	while (str[i])
	{
		while (ft_isspace(str[i]) && str[i])
			i++;
		if (!str[i])
			break ;
		start = i;
		while (!ft_isspace(str[i]) && str[i])
			i++;
		dst[j] = splitdup(str, start, i);
		j++;
	}
	dst[j] = NULL;
	return (dst);
}

char	**split_textures(char	*str, t_var	*vars)
{
	int		len;
	char	**dst;

	len = count_values(str);
	if (!str || len > 2)
		return (NULL);
	dst = (char **)malloc(sizeof(char *) * (len + 1));
	if (!dst)
		return (NULL);
	dst = fill_textures(str, dst);
	//print_2dstr(dst);
	if (!ft_strstr(TEXTURES, dst[0]))
		process_error(INVALID_TEXTURE, vars);
	return (dst);
}
