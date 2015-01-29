/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_createmap.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cheron <cheron@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/20 14:46:55 by cheron            #+#    #+#             */
/*   Updated: 2015/01/27 14:01:38 by cheron           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <wolf3d.h>
#include <libft.h>

t_map	*ft_allocmap(void)
{
	t_map	*map;
	char	*row0;
	char	*row1;
	char	*row2;
	char	*row3;
	char	*row4;
	char	**array;

	map = (t_map *)malloc(sizeof(t_map));
	row0 = ft_strdup("11111");
	row1 = ft_strdup("11001");
	row2 = ft_strdup("10201");
	row3 = ft_strdup("11001");
	row4 = ft_strdup("11111");
	array = (char **)malloc(sizeof(char *) * 5);
	array[0] = row0;
	array[1] = row1;
	array[2] = row2;
	array[3] = row3;
	array[4] = row4;
	map->width = 5;
	map->height = 5;
	map->map = array;
	return (map);
}

void	ft_freemap(t_map *map)
{
	char	**array;
	int		y;

	array = map->map;
	y = 0;
	while (y < map->height)
	{
		free(array[y]);
		array[y] = NULL;
		y++;
	}
	free(array);
}
