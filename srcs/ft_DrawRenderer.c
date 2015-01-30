/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_DrawRenderer.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cheron <cheron@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/23 13:50:18 by cheron            #+#    #+#             */
/*   Updated: 2015/01/30 17:03:43 by cheron           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <SDL.h>
#include <wolf3d.h>

#include <libft.h>
#include <stdio.h>
void		ft_DrawRenderer(t_pdata *pdata, t_map *map, SDL_Renderer *r)
{
	int		i;
	double	dis1;
	double	dis2;
	double	lowdis;
	double	alpha;

   	lowdis = 0;	
	alpha = fmod(pdata->dir + (double)(FOV / 2) + 360.0, 360.0);
	i = 0;
	ft_putendl("image;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;");
	//ft_putstr("dir ::");
	//ft_putendl(ft_itoa(pdata->dir));
		while (i < PROJ_WIDTH)
	{
		//alpha = pdata->dir + ( (i * ( FOV / PROJ_WIDTH ) ) - ( FOV / 2.0 ) );
		//		printf("alpha :: %f\n", alpha);
		dis1 = inter_horizontal( map, pdata, alpha );
		//ft_putendl("hori ok");
		dis2 = inter_vertical( map, pdata, alpha);
		//ft_putendl("ver ok");i
//		ft_putstr("hori1: ");
//		ft_putendl(ft_itoa(disToWall1));
//		ft_putstr("ver2 : ");
//		ft_putendl(ft_itoa(disToWall2));
//		ft_putendl("");
		if ((dis1 + dis2) == -2)
			ft_fatal("both dis error");
		else if (dis1 == -1 || dis2 == -1)
		{
			if (dis1 == -1)
			{
				lowdis = dis2;
				SDL_SetRenderDrawColor(r, 255, 0, 0, 255);
				if (alpha > 90 && alpha < 270)
					SDL_SetRenderDrawColor(r, 255, 255, 0, 255);
			}
			else
			{
				lowdis = dis1;
//				ft_putendl("dis2 error");
				SDL_SetRenderDrawColor(r, 0, 255, 0, 255);
				if (alpha < 180)
				{
					ft_putendl("!dis2  ::  bleu clair");
					ft_putstr("alpha ==>");
					printf("%f\n",alpha);
					SDL_SetRenderDrawColor(r, 0, 255, 255, 255);
				}
			}	
		}
		else
		{
			if (dis2 < dis1)
			{
				lowdis = dis2;
				SDL_SetRenderDrawColor(r, 255, 0, 0, 255);
				if (alpha > 90 && alpha < 270)
					SDL_SetRenderDrawColor(r, 255, 255, 0, 255);
			}
			else
			{
				lowdis = dis1;
				SDL_SetRenderDrawColor(r, 0, 255, 0, 255);
				if (alpha < 180)
				{	
					ft_putendl("dis2(vert) > dis1(hori) :: bleu clair");
					ft_putstr("alpha ==>");
					printf("%f\n",alpha);
					SDL_SetRenderDrawColor(r, 0, 255, 255, 255);
					printf("dis1 :: %f\ndis2 ::  %f\n", dis1, dis2);
				}
			}	

		}
		lowdis *= cos(((pdata->dir - alpha) * M_PI / 180));;
		//lowdis *= cos( M_PI / 180 * ((i) * (FOV / PROJ_WIDTH) - (FOV / 2.0)));
		SDL_RenderDrawLine(r, i, lowdis / 2, i, PROJ_HEIGHT - lowdis / 2);
		i++;
		alpha = ft_mod(alpha - DELTA_ALPHA);
	}
}
