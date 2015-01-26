/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_DrawRenderer.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cheron <cheron@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/23 13:50:18 by cheron            #+#    #+#             */
/*   Updated: 2015/01/26 16:28:39 by cheron           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <SDL.h>
#include <wolf3d.h>

#include <libft.h>
#include <stdio.h>
void		ft_DrawRenderer(t_pdata *pdata, t_map *map, SDL_Renderer *r)
{
	int		i;
	double	disToWall1;
	double	disToWall2;
	double	alpha;
 
	alpha = pdata->dir - (double)(FOV / 2);
	i = 0;
	while (i < PROJ_WIDTH)
	{
		disToWall1 = inter_horizontal( map, pdata, alpha );
		//ft_putendl("hori ok");
		disToWall2 = inter_vertical( map, pdata, alpha);
		//ft_putendl("ver ok");
		if (disToWall1 == -1)
		{
			if (disToWall2 == -1)
				disToWall1 = 0;
			else
				disToWall1 = disToWall2;
		}
		else if (disToWall2 != -1)
			disToWall1 = (disToWall1 < disToWall2 ? disToWall1 : disToWall2);
		SDL_SetRenderDrawColor(r, 255, 0, 0, 255);
		ft_putendl(ft_itoa(disToWall1));
		SDL_RenderDrawLine(r, i, (int)disToWall1 / 2, i, PROJ_HEIGHT - (int)disToWall1 / 2);
		i++;
		alpha = alpha + DELTA_ALPHA;
	}
}
