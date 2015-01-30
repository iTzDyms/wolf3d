/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_createpdata.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cheron <cheron@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/20 14:51:58 by cheron            #+#    #+#             */
/*   Updated: 2015/01/29 15:09:38 by cheron           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>
#include <wolf3d.h>
#include <stdlib.h>

t_pdata	*ft_allocpdata(void)
{
	t_pdata	*pdata;
	t_coord	*pcoord;

	pdata = (t_pdata *)malloc(sizeof(t_pdata));
	pcoord = ft_alloccoord();
	pdata->coord = pcoord;
//	pdata->height = PLAYER_HEIGHT;
	pdata->fov = FOV;
//	pdata->projdist = (PROJ_WIDTH / 2) / tan(FOV / 2);
//	pdata->wallh = 64 / pdata->projdist;
	pdata->dir = PLAYER_VIEW_DIR;
	return (pdata);
}

void	ft_freepdata(t_pdata *pdata)
{
	ft_freecoord(pdata->coord);
	free(pdata);
}
