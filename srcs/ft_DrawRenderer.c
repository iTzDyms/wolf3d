/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_DrawRenderer.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cheron <cheron@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/23 13:50:18 by cheron            #+#    #+#             */
/*   Updated: 2015/02/02 18:08:49 by cheron           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <SDL.h>
#include <math.h>
#include <wolf3d.h>
#include <stdio.h>////
static	void	ft_set_draw_color(SDL_Renderer *r, t_ray ray)
{	
	if (ray.dir.y > 0 && ray.where == 1)
		SDL_SetRenderDrawColor(r, 255, 255, 0, 255);
	else if (ray.dir.y <= 0 && ray.where == 1)
		SDL_SetRenderDrawColor(r, 0, 255, 0, 255);
	else if (ray.dir.y <= 0 && ray.where == 0)
		SDL_SetRenderDrawColor(r, 255, 0, 0, 255);
	else
		SDL_SetRenderDrawColor(r, 0, 255, 255, 255);
}

static	void	ft_draw_render_line(int i, double perpwalldis, SDL_Renderer *r)
{
	int	lineheight;
	int	drawstart;
	int	drawend;

	lineheight = (int)fabs(((double)PROJ_HEIGHT / perpwalldis));
	drawstart = -lineheight / 2 + PROJ_HEIGHT / 2;
	if (drawstart < 0)
		drawstart = 0;
	drawend = lineheight / 2 + PROJ_HEIGHT / 2;
	if (drawend >= PROJ_HEIGHT)
		drawend = PROJ_HEIGHT - 1;
	SDL_RenderDrawLine(r, i, drawstart, i, drawend);
}

void			ft_DrawRenderer(t_player *pdata, t_map *map, SDL_Renderer *r)
{
	t_ray	ray;
	double	perpwalldis;
	int	i;

	i = 0;
	while (i < PROJ_WIDTH)
	{
		printf("\ni :: %i\n", i);
		ray = ft_get_ray(pdata, i);
		ray = ft_dda(ray, map);
		perpwalldis = ft_distance(ray);
		//printf("dis :: %f\n", perpwalldis);////////
		ft_set_draw_color(r, ray);
		ft_draw_render_line(i, perpwalldis, r);
		i++;
	}
	return;
}
