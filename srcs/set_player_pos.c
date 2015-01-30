/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_player_pos.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cheron <cheron@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/20 13:38:26 by cheron            #+#    #+#             */
/*   Updated: 2015/01/30 20:00:26 by cheron           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <wolf3d.h>

t_coord		set_player_pos(t_map *map)
{
	int		x;
	int		y;
	t_coord	pcoord;

	y = 0;
	while (y < map->height)
	{
		x = 0;
		while (x < map->width)
		{
			if (map->map[y][x] == '2')
			{
				pcoord.y = y * 64 + 32;
				pcoord.x = x * 64 + 32;
				return(pcoord);
			}
			x++;
		}
		y++;
	}
	pcoord.x = 1;
	pcoord.y = 1;
	return(pcoord);
}
