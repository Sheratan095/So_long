/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rendering.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maceccar <maceccar@student.42firenze.it>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/30 11:22:43 by maceccar          #+#    #+#             */
/*   Updated: 2024/05/03 00:47:17 by maceccar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

static void	render_movement_count(t_vars *vars, int x, int y);
static int	render_player(t_vars *vars, t_position pos, int status);
static int	render_exit(t_vars *vars, t_position pos);
static int	render_tile(t_vars *vars, char type, t_position position);
int			render_next_frame(t_vars *vars);

//This function is called each frame and render on screen the game
//First of all make leet move all the enemies
//position: coordinates of each tile to render
//Passthrow the map and rander tile depending on his position
//Render movement count on screen
int	render_next_frame(t_vars *vars)
{
	int			i;
	int			j;
	t_position	position;

	enemy_movement(vars);
	i = 0;
	j = 0;
	while (i < vars->game->number_of_rows)
	{
		j = 0;
		while (j < vars->game->number_of_columns)
		{
			position.x = j * TILE_SIZE;
			position.y = i * TILE_SIZE;
			render_tile(vars, vars->game->map[i][j], position);
			j++;
		}
		i++;
	}
	render_movement_count(vars, 10, 20);
	return (0);
}

//Render player depending on witch direction(last movement key pressed)
//	 is he facing and on witch status of animation is
static int	render_player(t_vars *vars, t_position pos, int status)
{
	int	direction;

	direction = vars->game->player_direction;
	if (direction == S_KEY || direction == DOWN_ARROW)
		put_img(vars, vars->assets->player_down[status], pos.x, pos.y);
	else if (direction == W_KEY || direction == UP_ARROW)
		put_img(vars, vars->assets->player_up[status], pos.x, pos.y);
	else if (direction == D_KEY || direction == RIGHT_ARROW)
		put_img(vars, vars->assets->player_right[status], pos.x, pos.y);
	else if (direction == A_KEY || direction == LEFT_ARROW)
		put_img(vars, vars->assets->player_left[status], pos.x, pos.y);
	return (1);
}

//Render exit depending on if the player already get all collectibles
static int	render_exit(t_vars *vars, t_position pos)
{
	if (vars->game->collectibles_count != 0)
		put_img(vars, vars->assets->exit_closed, pos.x, pos.y);
	else
		put_img(vars, vars->assets->exit_open, pos.x, pos.y);
	return (0);
}

//Switch different type of element in the map and render each one in
//	his tile
//frame_count is used to change the stauts of player animation each 10000 frame
//frame_count is static so it can store his value throw the calls
//	Beacause it increment each call of this function
static int	render_tile(t_vars *vars, char type, t_position pos)
{
	static int	frame_count;
	int			animation_status;

	if (frame_count > 10000)
		animation_status = 1;
	else
		animation_status = 0;
	if (type == ENEMY)
		put_img(vars, vars->assets->enemy, pos.x, pos.y);
	else if (type == PLAYER)
		render_player(vars, pos, animation_status);
	else if (type == COLLECTIBLES)
		put_img(vars, vars->assets->collectible, pos.x, pos.y);
	else if (type == FLOOR)
		put_img(vars, vars->assets->floor, pos.x, pos.y);
	else if (type == WALL)
		put_img(vars, vars->assets->wall, pos.x, pos.y);
	else if (type == EXIT)
		render_exit(vars, pos);
	if (frame_count == 20000)
		frame_count = 0;
	frame_count++;
	return (0);
}

//Transform number of movement from int to string
//Print it on the screen with a certain padding to align it with the
//	phrase before
static void	render_movement_count(t_vars *vars, int x, int y)
{
	char	*number;

	number = ft_itoa(vars->game->number_of_moves);
	mlx_string_put(vars->mlx, vars->win, x, y, 0XFFFFFF, "Number of moves :");
	mlx_string_put(vars->mlx, vars->win, x + 105, y + 1, 0XFFFFFF, number);
	free(number);
}
