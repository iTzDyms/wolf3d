/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_DrawRenderer.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cheron <cheron@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/23 13:50:18 by cheron            #+#    #+#             */
/*   Updated: 2015/02/12 14:43:26 by cheron           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <SDL.h>
#include <math.h>
#include <wolf3d.h>

static	void	ft_draw_render_line(int i, double perpwalldis, SDL_Renderer *r)
{
	int			lineheight;
	int			drawstart;
	int			drawend;

	lineheight = (int)fabs(((double)PROJ_HEIGHT / perpwalldis));
	drawstart = -lineheight / 2 + PROJ_HEIGHT / 2;
	if (drawstart < 0)
		drawstart = 0;
	drawend = lineheight / 2 + PROJ_HEIGHT / 2;
	if (drawend >= PROJ_HEIGHT)
		drawend = PROJ_HEIGHT - 1;
	SDL_RenderDrawLine(r, i, drawstart, i, drawend);
}

void			ft_draw_renderer(t_player *pdata, t_map *map, SDL_Renderer *r)
{
	t_ray		ray;
	double		perpwalldis;
	int			i;

	i = 0;
	while (i < PROJ_WIDTH)
	{
		ray = ft_get_ray(pdata, i);
		ray = ft_dda(ray, map);
		perpwalldis = ft_distance(ray);
		ft_set_draw_color(r, ray);
		ft_draw_render_line(i, perpwalldis, r);
		i++;
	}
	return ;
}
