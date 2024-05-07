/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   finish_game.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maceccar <maceccar@student.42firenze.it>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/30 11:22:43 by maceccar          #+#    #+#             */
/*   Updated: 2024/05/03 00:47:17 by maceccar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

static int	finish_hook( int keycode, t_vars *vars);
static int	death_animation(t_vars *vars);
static int	win_animation(t_vars *vars);
void		initialize_window(t_vars *vars);
int			hook(t_vars *vars);
int			destroy_notify(t_vars *vars);

//Last windows of the game
//Destroy the current mlx window
//If the player lost
//	=>Create lost window
//If the player won
//	=>Create win window
//In each case, then start the finish hoop look and the destroy_notify loop_hook
//If the player lost
//	=>Lost animation
//If the player won
//	=>Win animation
//mlx_loop: make mlx run
int	finish_game(t_vars *vars, t_game_status status)
{
	mlx_destroy_window(vars->mlx, vars->win);
	if (status == lose)
	{
		vars->win = mlx_new_window(vars->mlx, 800, 400, "YOU DIED");
		ft_printf("\nLOSE\n\n");
	}
	else if (status == win)
	{
		vars->win = mlx_new_window(vars->mlx, 800, 400, "YOU WIN");
		ft_printf("\nWIN\n\n");
	}
	mlx_key_hook(vars->win, finish_hook, vars);
	mlx_hook(vars->win, DESTROY_NOTIFY, 1L << 0, destroy_notify, vars);
	if (status == lose)
		mlx_loop_hook(vars->mlx, death_animation, vars);
	else if (status == win)
		mlx_loop_hook(vars->mlx, win_animation, vars);
	mlx_loop(vars->mlx);
	return (0);
}

//Check what'pressed 
//ESC => end
//R (restart)
//	temporary save file name
//	end the game just destoying t_game
//	get a new t_game parsing map as at first start
//	start the game again
static int	finish_hook( int keycode, t_vars *vars)
{
	t_game	*game;
	char	*file_tmp;

	if (keycode == KEY_ESC)
		end(vars, false);
	if (keycode == R_KEY)
	{
		file_tmp = vars->game->file;
		end(vars, true);
		game = get_map(file_tmp);
		start_game(game);
	}
	return (0);
}

//Each 1000 frame change the animation status
//	displaiyng different images on window
//frame_count is static so it can store his value throw the calls
//	Beacause it increment each call of this function
static int	death_animation(t_vars *vars)
{
	static int	frame_count;

	if (frame_count > 2000)
		put_img(vars, vars->assets->death[0], 0, 0);
	else
		put_img(vars, vars->assets->death[1], 0, 0);
	if (frame_count == 4000)
		frame_count = 0;
	frame_count++;
	return (0);
}

//Just display on screen the win aniamtion
static int	win_animation(t_vars *vars)
{
	static int	frame_count;

	if (frame_count > 2000)
		put_img(vars, vars->assets->win[0], 0, 0);
	else
		put_img(vars, vars->assets->win[1], 0, 0);
	if (frame_count == 4000)
		frame_count = 0;
	frame_count++;
	return (0);
	return (0);
}
