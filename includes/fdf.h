/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aouichou <aouichou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/21 17:43:18 by aouichou          #+#    #+#             */
/*   Updated: 2022/07/03 03:21:55 by aouichou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H
# include "libft.h"
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>
# include "mlx.h"
# include "/usr/include/X11/Xlib.h"
# include "mlx_int.h"
# include "defines.h"
# include <math.h>

typedef struct s_color
{
	int					start_color;
	int					start_r;
	int					start_g;
	int					start_b;
	int					end_color;
	int					end_r;
	int					end_g;
	int					end_b;
	int					delta_r;
	int					delta_g;
	int					delta_b;
}						t_color;

typedef struct s_p
{
	float				x;
	float				y;
	float				z;
	int					color;
}						t_p;

typedef struct s_map
{
	char				*name;
	t_p					**map_coords;
	float				mx_x;
	float				mx_y;
	int					mx_h;
	int					mn_h;
	struct s_map		*next;
	struct s_map		*previous;
}						t_map;

typedef struct s_segmnt
{
	t_p					start;
	t_p					end;
	float				new_z;
}						t_segmnt;

typedef struct s_image
{
	t_img				*image;
	int					pxl_bits;
	int					segmnt_bits;
	int					endian;
	char				*buffer;
	t_segmnt			*segmnt;
}						t_image;

typedef struct s_cam
{
	int					projection;
	int					color_pallet;
	int					color_type;
	float				scale;
	float				scale_z;
	float				move_x;
	float				move_y;
	double				alpha;
	double				beta;
	double				gamma;
}						t_cam;

typedef struct s_main_fdf
{
	int					fd;
	void				*mlx;
	void				*win;
	t_image				*image;
	float				res_x;
	float				res_y;
	t_map				*map_head;
	t_cam				*cam;
}						t_main_fdf;

void					ft_parsing(int ac, char **av);

void					ft_add_to_lst(t_main_fdf *ptr, t_map *link);
t_main_fdf				*ft_get_ptr(void);
float					ft_abs(float nbr);
float					ft_max(float a, float b);
float					ft_min(float a, float b);

void					ft_free_tab(char **tab);
void					free_map(t_map *map);
void					free_coords(t_p **coordinates, int width);

void					ft_exit(void);
void					ft_error(char *error);
void					ft_error_map(t_map *map, char *map_name, char *line);
int						ft_close(void *param);

void					ft_display_menu(t_main_fdf *ptr);

t_map					*init_map(char *name);
t_image					*init_image(t_main_fdf *ptr);
t_cam					*init_cam(t_main_fdf *ptr);
t_segmnt				*init_segmnt(t_p start, t_p end);
t_p						**init_coords(int mx_x, int mx_y);

int						ft_count_tab(char *line, char c);
void					center_map(t_map *map);
float					scale_to_fit(t_map *map);
void					reset_cam(t_main_fdf *ptr);

t_color					*starting_color_init(int min_color, int max_color);
t_color					*color_init(t_p start, t_p end);
int						color_gradient(t_color *color, float progress);
int						get_color(t_color *color, int i_line, int line_size);

void					apply_colors(t_main_fdf *ptr, t_p *point);
void					render_segmnt(t_main_fdf *ptr, t_p start, t_p end);
void					renderer(t_main_fdf *ptr);
int						handler(t_main_fdf *ptr);
void					ft_mlx(t_main_fdf *ptr);

void					clear_image(t_image *image, int image_size);
void					pixel_to_image(t_image *image, float x, float y, \
										int color);
void					bresenham(t_main_fdf *ptr, t_p start, t_p end);

int						ft_key_hook(int keycode, t_main_fdf *ptr);

int						ft_mouse_hook(int keycode, int x, int y, \
										t_main_fdf *ptr);

void					project(t_cam *cam, t_segmnt *segmnt);

void					transform(t_cam *cam, t_segmnt *segmnt);
void					translate(t_segmnt *segmnt, int move_x, int move_y);
void					altitude(t_segmnt *segmnt, int scale_factor);

void					rotate(t_cam *cam, t_segmnt *segmnt);
void					rotate_x(t_segmnt *segmnt, double angle);
void					rotate_y(t_segmnt *segmnt, double angle);
void					rotate_z(t_segmnt *segmnt, double angle);

int						ft_close(void *param);

void					apply_colors_negatif(t_main_fdf *ptr, t_p *point);
void					apply_colors_positif(t_main_fdf *ptr, t_p *point);

void					apply_topo_colors_negatif(t_main_fdf *ptr, t_p *point);
void					apply_topo_colors_positif(t_main_fdf *ptr, t_p *point);

#endif
