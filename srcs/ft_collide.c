/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_collide.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cheron <cheron@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/02 13:04:04 by cheron            #+#    #+#             */
/*   Updated: 2015/02/02 14:39:37 by cheron           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <wolf3d.h>

int	hit_wall(int col, int row, t_map *map)
{
	if (col < 0 || row < 0 || col >= map->width || row >= map->height)
	{
		return (1);
	}
	else
	{
		return (map->map[row][col] == 1);
	}
}
