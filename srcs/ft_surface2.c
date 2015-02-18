/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_surface2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cheron <cheron@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/20 14:46:55 by cheron            #+#    #+#             */
/*   Updated: 2015/02/12 14:00:17 by cheron           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <SDL.h>
#include <math.h>
#include <wolf3d.h>

static	void	ft_proceed_line(SDL_Surface *s, int i, double perpwalldis,
								Uint32 pixel);

static	void	ft_apply_floor(t_player *pdata, SDL_Surface *surface);
static	void	ft_apply_sky(t_player *pdata, SDL_Surface *surface);
static	void	ft_apply_wall(t_player *pdata, t_map *map,
								SDL_Surface *surface);

void	ft_draw_surface(t_map *map, t_player *pdata,
						SDL_Surface *surface)
{
	ft_apply_sky(pdata, surface);
	ft_apply_floor(pdata, surface);
	ft_apply_wall(pdata, map, surface);
}

static	void	ft_apply_sky(t_player *pdata, SDL_Surface *surface)
{
	t_pos	pos;


	pos.x = 0;
	pos.y = 0;
	pdata = pdata;///////////future usage to see the position the player is looking and the proportion the sky has
	ft_surface_draw_rect(surface, pos, PROJ_WIDTH, PROJ_HEIGHT / 2,
						(Uint32)0x3399FF);
}

static	void	ft_apply_floor(t_player *pdata, SDL_Surface *surface)
{
	t_pos	pos;

	pos.x = 0;
	pos.y = PROJ_HEIGHT / 2;
	pdata = pdata; /////////////////// for future use
	ft_surface_draw_rect(surface, pos, PROJ_WIDTH, PROJ_HEIGHT / 2,
						(Uint32)0x66665D);
}

static	void	ft_apply_wall(t_player *pdata, t_map *map,
						SDL_Surface *surface)
{
	t_ray		ray;
	double		perpwalldis;
	int			i;
	Uint32		color;

	i = 0;
	while (i < PROJ_WIDTH)
	{
		ray = ft_get_ray(pdata, i);
		ray = ft_dda(ray, map);
		perpwalldis = ft_distance(ray);
		color = ft_get_draw_color(ray);
		ft_proceed_line(surface, i, perpwalldis, color);
		i++;
	}	
}

static	void	ft_proceed_line(SDL_Surface *surface, int i,
									double perpwalldis, Uint32 color)
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
	ft_surface_draw_verline(surface, i, drawstart, drawend, color);
}

