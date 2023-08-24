/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_init.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamottet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/24 16:14:09 by mamottet          #+#    #+#             */
/*   Updated: 2023/08/24 16:14:12 by mamottet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

// Function to initializes the window and sets the init properties of the game
void	ft_initialize_game(t_game_instance *game_init)
{
	game_init->mlx_ptr = mlx_init();
	if (game_init->mlx_ptr == NULL)
		ft_error_init(38);
	game_init->game_data.count_movements = 0;
	ft_img_init(game_init);
	game_init->game_objs.player = game_init->game_objs.player_down;
	game_init->win_ptr = mlx_new_window(game_init->mlx_ptr,
			game_init->map_init.resolutions.settings_map_width
			* CELL_SIZE, game_init->map_init.resolutions.settings_map_height
			* CELL_SIZE, "The Blue Knight");
	if (game_init->win_ptr == NULL)
		ft_error_init(38);
}

// Function to loads the different game images from image files (XPM format)
void	ft_img_init(t_game_instance *game_init)
{
	ft_check_img(game_init, &game_init->game_objs.player_up,
		"rscs/textures/Player/walkUP_00.xpm");
	ft_check_img(game_init, &game_init->game_objs.player_down,
		"rscs/textures/Player/walkDown_00.xpm");
	ft_check_img(game_init, &game_init->game_objs.player_right,
		"rscs/textures/Player/walkRight_00.xpm");
	ft_check_img(game_init, &game_init->game_objs.player_left,
		"rscs/textures/Player/walkLeft_00.xpm");
	ft_check_img(game_init, &game_init->game_objs.collectible,
		"rscs/textures/Collectibles/star_00.xpm");
	ft_check_img(game_init, &game_init->game_objs.floor,
		"rscs/textures/Tiles/midBlocks_02.xpm");
	ft_check_img(game_init, &game_init->game_objs.exit_open,
		"rscs/textures/Exit/exit_open_01.xpm");
	ft_check_img(game_init, &game_init->game_objs.exit_close,
		"rscs/textures/Exit/exit_close_01.xpm");
	ft_check_img(game_init, &game_init->game_objs.wall,
		"rscs/textures/Tiles/blockSimple.xpm");
}

void	ft_check_img(t_game_instance *game_init, void **image, char *path)
{
	int	width;
	int	height;

	*image = mlx_xpm_file_to_image(game_init->mlx_ptr, path, &width, &height);
	if (*image == NULL)
	{	
		ft_error_init(1);
		ft_exit_program(game_init);
	}
}
