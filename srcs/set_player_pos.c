/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_player_pos.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cheron <cheron@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/20 13:38:26 by cheron            #+#    #+#             */
/*   Updated: 2015/02/02 15:03:54 by cheron           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <wolf3d.h>
#include <libft.h>

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
				pcoord.y = y + 0.5;
				pcoord.x = x + 0.5;
				return(pcoord);
			}
			x++;
		}
		y++;
	}
	ft_fatal("could not find original player coordinates.");
	return(pcoord);
}
