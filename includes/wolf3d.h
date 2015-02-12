/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wolf3d.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cheron <cheron@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/19 14:40:51 by cheron            #+#    #+#             */
/*   Updated: 2015/02/12 17:05:08 by cheron           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WOLF3D_H
# define WOLF3D_H

# include <SDL.h>

# define PROJ_HEIGHT 768
# define PROJ_WIDTH 1366
# define W_TITLE "Wolf3D"
# define DELAY 1000 / 60
# define ROT 1.0
# define SPEED 1.0

typedef	struct		s_screen
{
	SDL_Window		*win;
	SDL_Renderer	*r;	
}					t_screen;

typedef	struct		s_map
{
	int				width;
	int				height;
	char			**map;
}					t_map;

typedef struct		s_pos
{
	int				x;
	int				y;
	int				z;
}					t_pos;

typedef struct		s_coord
{
	double			x;
	double			y;
	double			z;
}					t_coord;

typedef	struct		s_player
{
	int				mov;
	int				rot;
	t_coord			dir;
	t_coord			coord;
	t_coord			cam;
}					t_player;

typedef struct		s_ray
{
//	double			dist;
	t_coord			dir;
	t_coord			delta;
	t_coord			side;
	t_coord			coord;
	t_pos			map;
	t_pos			step;
	int				where;
}					t_ray;

t_screen			*ft_allocscreen(void);
void				ft_freescreen(t_screen *screen);
t_map				*ft_allocmap(void);
void				ft_freemap(t_map *map);
void				ft_print_map(t_map *map);
t_player			ft_get_player(t_map *map);
t_coord				set_player_pos(t_map *map);
SDL_Window			*ft_createwin(char *title, int height, int width);
void				ft_proceed(t_screen *screen, t_map *map, t_player *pdata);
void				ft_draw_renderer(t_player *player, t_map *map, SDL_Renderer *r);
void				ft_move(t_player *pdata, SDL_Keycode sym, SDL_Keymod mod);
void				ft_rotate(t_player *pdata, SDL_Keycode sym, SDL_Keymod mod);
t_ray				ft_get_ray(t_player *pdata, int i);
t_ray				ft_dda(t_ray ray, t_map *map);
int					hit_wall(int col, int row, t_map *map);
double				ft_distance(t_ray ray);
void				ft_set_draw_color(SDL_Renderer *r, t_ray ray);
void				ft_draw_line(SDL_Renderer *r, int col, int start, int end);
void				ft_draw_rectangle(SDL_Renderer *r, int xa, int xb, int ya, int yb);
#endif
