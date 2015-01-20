/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_player_pos.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cheron <cheron@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/20 13:38:26 by cheron            #+#    #+#             */
/*   Updated: 2015/01/20 18:29:11 by cheron           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <wolf3d.h>

void	set_player_pos(t_map *map, t_coord *pcoord)
{
	int		x;
	int		y;

	y = 0;
	while (y < map->height)
	{
		x = 0;
		while (x < map->width)
		{
			if (map->map[y][x] == '2')
			{
				pcoord->y = y * 64 + 32;
				pcoord->x = x * 64 + 32;
				return ;
			}
			x++;
		}
		y++;
	}
	pcoord->x = 0;
	pcoord->y = 0;
}
