/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_createmap.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cheron <cheron@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/20 14:46:55 by cheron            #+#    #+#             */
/*   Updated: 2015/01/29 17:39:35 by cheron           ###   ########.fr       */
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
	char	*row5;
	char	*row6;
	char	*row7;
	char	*row8;
	char	*row9;
	char	*row10;
	char	*row11;
	char	*row12;
	char	*row13;
	char	**array;

	map = (t_map *)malloc(sizeof(t_map));
	row0 = ft_strdup("11111111111111");
	row1 = ft_strdup("11000000000011");
	row2 = ft_strdup("10000000000001");
	row3 = ft_strdup("10000000000001");
	row4 = ft_strdup("10000000000001");
	row5 = ft_strdup("10000000000001");
	row6 = ft_strdup("10000020000001");
	row7 = ft_strdup("10000000000001");
	row8 = ft_strdup("10000000000001");
	row9 = ft_strdup("10000000000001");
	row10 = ft_strdup("10000000000001");
	row11 = ft_strdup("10000000000001");
	row12 = ft_strdup("11000000000011");
	row13 = ft_strdup("11111111111111");
	array = (char **)malloc(sizeof(char *) * 14);
	array[0] = row0;
	array[1] = row1;
	array[2] = row2;
	array[3] = row3;
	array[4] = row4;
	array[5] = row5;
	array[6] = row6;
	array[7] = row7;
	array[8] = row8;
	array[9] = row9;
	array[10] = row10;
	array[11] = row11;
	array[12] = row12;
	array[13] = row13;
	map->width = 14;
	map->height = 14;
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
