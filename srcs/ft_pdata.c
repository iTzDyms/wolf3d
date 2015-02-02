/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_createpdata.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cheron <cheron@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/20 14:51:58 by cheron            #+#    #+#             */
/*   Updated: 2015/02/02 18:20:22 by cheron           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <wolf3d.h>

t_player	ft_get_player(t_map *map)
{
	t_player	pdata;

	pdata.mov = 0;
	pdata.rot = 2;
	pdata.dir.x = 1;
	pdata.dir.y = 0;
	pdata.coord = set_player_pos(map);
	pdata.coord.z = 1;
	pdata.cam.z = 1;
	return (pdata);
}
