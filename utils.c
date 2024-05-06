/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maceccar <maceccar@student.42firenze.it>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/30 11:22:43 by maceccar          #+#    #+#             */
/*   Updated: 2024/05/03 00:47:17 by maceccar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

//Used for norminette
int	put_img(t_vars *vars, void *asset, int x, int y)
{
	mlx_put_image_to_window(vars->mlx, vars->win, asset, x, y);
	return (0);
}

//Allocate and initialize all the parameter of t_game
//Enemy list is allocated with just a null pointer
//	it will be checked in allocation to avoid segfault
t_game	*allocate_game(t_game *game)
{
	game = malloc(sizeof(t_game));
	if (!game)
		return (game);
	game->player_direction = DOWN_ARROW;
	game->number_of_moves = 0;
	game->number_of_columns = 0;
	game->number_of_rows = 0;
	game->is_map_valid = false;
	game->map = NULL;
	game->player_position = NULL;
	game->exit_position = NULL;
	game->enemies = ft_lstnew(NULL);
	return (game);
}
