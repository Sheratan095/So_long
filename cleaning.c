/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cleaning.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maceccar <maceccar@student.42firenze.it>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/30 11:22:43 by maceccar          #+#    #+#             */
/*   Updated: 2024/05/03 00:47:17 by maceccar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void		free_game(t_game *game);
static void	free_assets(t_vars *vars);
static int	destroy_window(t_vars *vars);
static void	free_enemy_lst(t_game *game);

//CLEAN EVERITHING
//If restart == false => exit
//Else => don't exit beacause, after this function, the game will started back 
int	end(t_vars *vars, t_bool restart)
{
	if (restart == true)
		ft_printf("\nRESTARTING\n\n");
	else
		ft_printf("\nGAME END\n\n");
	free_game(vars->game);
	free_assets(vars);
	destroy_window(vars);
	if (vars->mlx)
		free(vars->mlx);
	if (restart == false)
		exit(0);
	return (1);
}

//FREE ALL POINTER IN T_GAME
//Non-static beacause it's called by main if something goes wrong during
//	map parsing
void	free_game(t_game *game)
{
	if (game->exit_position)
		free(game->exit_position);
	if (game->player_position)
		free(game->player_position);
	if (game->map)
		ft_free_matrix((void **)game->map);
	if (game->enemies)
		free_enemy_lst(game);
	free(game);
}

//FREE THE ASSETS DESTROYING MLX_IMAGE
static void	free_assets(t_vars *vars)
{
	mlx_destroy_image(vars->mlx, vars->assets->collectible);
	mlx_destroy_image(vars->mlx, vars->assets->exit_closed);
	mlx_destroy_image(vars->mlx, vars->assets->exit_open);
	mlx_destroy_image(vars->mlx, vars->assets->enemy);
	mlx_destroy_image(vars->mlx, vars->assets->wall);
	mlx_destroy_image(vars->mlx, vars->assets->floor);
	mlx_destroy_image(vars->mlx, vars->assets->player_up[0]);
	mlx_destroy_image(vars->mlx, vars->assets->player_up[1]);
	mlx_destroy_image(vars->mlx, vars->assets->player_down[0]);
	mlx_destroy_image(vars->mlx, vars->assets->player_down[1]);
	mlx_destroy_image(vars->mlx, vars->assets->player_right[0]);
	mlx_destroy_image(vars->mlx, vars->assets->player_right[1]);
	mlx_destroy_image(vars->mlx, vars->assets->player_left[0]);
	mlx_destroy_image(vars->mlx, vars->assets->player_left[1]);
	mlx_destroy_image(vars->mlx, vars->assets->death[0]);
	mlx_destroy_image(vars->mlx, vars->assets->death[1]);
	mlx_destroy_image(vars->mlx, vars->assets->win[0]);
	mlx_destroy_image(vars->mlx, vars->assets->win[1]);
	free(vars->assets);
}

//DESTROY ALL MLX ELEMENTS
static int	destroy_window(t_vars *vars)
{
	mlx_destroy_window(vars->mlx, vars->win);
	mlx_destroy_display(vars->mlx);
	return (0);
}

static void	free_enemy_lst(t_game *game)
{
	t_list	*tmp;

	tmp = game->enemies;
	while (tmp->content != NULL)
	{
		game->enemies = tmp->next;
		free(tmp->content);
		free(tmp);
		tmp = game->enemies;
	}
	free(game->enemies);
}
