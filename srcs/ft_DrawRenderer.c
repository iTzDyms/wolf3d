/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_DrawRenderer.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cheron <cheron@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/23 13:50:18 by cheron            #+#    #+#             */
/*   Updated: 2015/01/23 17:35:49 by cheron           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <SDL.h>
#include <wolf3d.h>

#include <libft.h>
#include <stdio.h>
void		ft_DrawRenderer(t_pdata *pdata, t_map *map, SDL_Renderer *r)
{
	int		i;
	int		disToWall1;
	int		disToWall2;
	double	alpha;
 
	alpha = pdata->dir - (double)(FOV / 2);
	i = 0;
	while (i < PROJ_WIDTH)
	{
		ft_putendl(ft_itoa(alpha));
		disToWall1 = inter_horizontal( map, pdata, alpha );
		ft_putendl("hori ok");
		disToWall2 = inter_vertical( map, pdata, alpha);
		ft_putendl("ver ok");
		disToWall1 = (disToWall1 < disToWall2 ? disToWall1 : disToWall2);
		SDL_SetRenderDrawColor(r, 255, 0, 0, 255);
		SDL_RenderDrawLine(r, i, disToWall1, i, PROJ_HEIGHT - disToWall1);
		i++;
		alpha = alpha + DELTA_ALPHA;
	}
}
