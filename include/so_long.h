/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamottet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/24 16:33:48 by mamottet          #+#    #+#             */
/*   Updated: 2023/08/26 14:28:27 by mamottet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "../libs/minilibx-linux/mlx.h"
# include "../libs/c_lib/libft.h"

# include "custom_letters.h"
# include <fcntl.h> // Read
# include <string.h> // Strerror

// GAME OBJECTS KEYS
# define PLAYER 'P'
# define EXIT 'E'
# define COLLECTIBLE 'C'
# define WALL '1'
# define EMPTY '0'

// GAME KEYWORDS
# define ESC 65307
# define W 119
# define UP 65362
# define A 97
# define LEFT 65361
# define S 115
# define DOWN 65364
# define D 100
# define RIGHT 65363
# define RESTART 114

# define MAX_FILES 1

# define TRUE 1
# define FALSE 0

# define CELL_SIZE 32

// Struct
typedef struct s_game_objs
{
	void	*player;
	void	*player_left;
	void	*player_right;
	void	*player_down;
	void	*player_up;
	void	*collectible;
	void	*exit_open;
	void	*exit_close;
	void	*wall;
	void	*floor;
	int		img_width;
	int		img_height;
}	t_game_objs;

typedef struct s_game_positions
{
	int	player_row;
	int	player_col;
	int	exit_row;
	int	exit_col;
}	t_game_positions;

typedef struct s_game_data
{
	int	count_player;
	int	count_exit;
	int	count_collectible;
	int	count_wall;
	int	count_empty;
	int	count_movements;
	int	endgame;
}	t_game_data;

typedef struct s_game_resolutions
{
	int		settings_map_width;
	int		settings_map_height;
	char	*settings_name_window;
	char	*settings_name_map;
}	t_game_resolutions;

typedef struct s_map_data
{
	int					first_read_matrice;
	int					cols_matrice;
	int					rows_matrice;
	int					size_matrice;
	char				**matrice;
	t_game_resolutions	resolutions;
	t_game_positions	positions;
}	t_map_data;

typedef struct s_game_instance
{
	void				*mlx_ptr;
	void				*win_ptr;
	int					argc_tmp;
	char				**argv_tmp;
	t_map_data			map_init;
	t_game_positions	positions_init;
	t_game_data			game_data;
	t_game_resolutions	resolutions_init;
	t_game_objs			game_objs;
}	t_game_instance;

// --------------------- FUNCTION -------------- //
int			main(int argc, char **argv);
// --------------------- GAME INIT
void		ft_struct_init(t_game_instance *game_init);
void		ft_initialize_game(t_game_instance *game_init);
// --------------------- GAME EVENTS
int			ft_check_keyboard(int key, t_game_instance *game_init);
int			ft_non_special(int key, t_game_instance *game_init);
int			ft_exit_program(t_game_instance *game_init);
void		ft_reset_game(t_game_instance *game_init);
// --------------------- MAP VALIDATIONS AND MAP DATA
int			ft_open_map(char *map, t_game_instance *game_init);
int			ft_read_count_map(char *map);
int			ft_count_lines(int fd);
int			ft_map_dimensions(t_game_instance *game_init);
int			get_rows_count(t_game_instance *game_init);
int			get_cols_count(t_map_data *map_init);
int			ft_read_map(int fd, t_game_instance *game_init);
int			ft_check_read(t_game_instance *game_init);
int			ft_map_extension(char *map);
int			ft_is_valid_map(t_game_instance *game_init);
int			ft_is_map_shape_valid(t_game_instance *game_init);
int			ft_is_wall(t_game_instance *game_init);
int			ft_count_map_objects(t_game_instance *game_init);
int			ft_have_requires(t_game_instance *game_init);
// --------------------- GAME EVENTS/ACTIONS + GRAPHICS
void		ft_gameplay_start(t_game_instance *game_init);
int			ft_events_pressed(t_game_instance *game_init, int column, int row);
void		ft_win(t_game_instance *game_init);
int			ft_print_shell(t_game_instance *game_init);
int			ft_exit_program(t_game_instance *game_init);
void		ft_reset_game(t_game_instance *game_init);
void		ft_locate_player(t_game_instance *game_init);
// --------------------- GRAPHICS + EVENTS
void		ft_img_init(t_game_instance *game_init);
void		ft_check_img(t_game_instance *game_init, void **image, char *path);
int			ft_map_draw(t_game_instance *game_init);
void		ft_map_continues(t_game_instance *game_init, int column, int row);
void		ft_set(t_game_instance *game_init, void *img, int wid, int hgt);
// --------------------- I WANT TO BREAK [FREE]
void		ft_free_map(t_game_instance *game_init);
void		ft_free_img(t_game_instance *game_init);
void		ft_cleanup(t_game_instance *game_init);
// --------------------- CUSTOM ERRORS MESSAGE
void		ft_error_init(int n);
void		ft_error_map(int n);
// --------------------- UTILS
int			ft_strcmp(const char *s1, const char *s2);

#endif
