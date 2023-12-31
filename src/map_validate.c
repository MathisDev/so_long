/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_validate.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamottet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/24 16:15:14 by mamottet          #+#    #+#             */
/*   Updated: 2023/08/28 11:36:49 by mamottet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

int	ft_is_valid_map(t_game_instance *game_init)
{
	if (!(ft_count_map_objects(game_init)))
		return (0);
	if (!(ft_is_map_shape_valid(game_init)))
		return (0);
	if (!(ft_is_wall(game_init)))
		return (0);
	return (1);
}

int	ft_is_map_shape_valid(t_game_instance *game_init)
{
	if (game_init->map_init.cols_matrice <= 0
		|| game_init->map_init.rows_matrice <= 0)
		return (0);
	if (game_init->map_init.size_matrice == 0)
		return (0);
	if (game_init->map_init.size_matrice % game_init->map_init.rows_matrice == 0
		&& game_init->map_init.size_matrice / game_init->map_init.rows_matrice
		== game_init->map_init.cols_matrice)
		return (1);
	return (0);
}

int	ft_is_wall(t_game_instance *game_init)
{
	int		i;
	int		j;

	i = 0;
	while (i < game_init->map_init.rows_matrice)
	{
		j = 0;
		while (j < game_init->map_init.cols_matrice)
		{
			if (i == 0 || j == 0 || i == game_init->map_init.rows_matrice
				- 1 || j == game_init->map_init.cols_matrice - 1)
			{
				if (game_init->map_init.matrice[i][j] != '1')
					return (0);
			}
			j++;
		}
		i++;
	}
	return (1);
}

int	ft_count_map_objects(t_game_instance *game_init)
{
	int	row;
	int	column;

	row = -1;
	while (game_init->map_init.matrice[++row])
	{
		column = 0;
		while (game_init->map_init.matrice[row][column])
		{
			if (game_init->map_init.matrice[row][column] == PLAYER)
				game_init->game_data.count_player++;
			else if (game_init->map_init.matrice[row][column] == EXIT)
				game_init->game_data.count_exit++;
			else if (game_init->map_init.matrice[row][column] == COLLECTIBLE)
				game_init->game_data.count_collectible++;
			else if (game_init->map_init.matrice[row][column] == '1')
				game_init->game_data.count_wall++;
			else if (game_init->map_init.matrice[row][column] == '0')
				game_init->game_data.count_empty++;
			else if (game_init->map_init.matrice[row][column] != '\n')
				return (0);
			column++;
		}
	}
	return (ft_have_requires(game_init));
}

int	ft_have_requires(t_game_instance *game_init)
{
	if (!(game_init->game_data.count_player == 1
			&& game_init->game_data.count_exit == 1
			&& game_init->game_data.count_collectible >= 1))
		return (0);
	return (1);
}
