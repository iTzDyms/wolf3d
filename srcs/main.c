/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cheron <cheron@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/19 14:36:56 by cheron            #+#    #+#             */
/*   Updated: 2015/01/20 19:38:26 by cheron           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>
#include <wolf3d.h>

int	main(void)
{
	t_map	*map;
	t_pdata	*pdata;

	map = ft_allocmap();
	pdata = ft_allocpdata();
	set_player_pos(map, pdata->coord);
	ft_freepdata(pdata);
	pdata = NULL;
	ft_freemap(map);
	map = NULL;
	return (1);
}
