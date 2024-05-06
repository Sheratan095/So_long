/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movement.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maceccar <maceccar@student.42firenze.it>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/30 11:22:43 by maceccar          #+#    #+#             */
/*   Updated: 2024/05/03 00:50:21 by maceccar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static t_game_status	try_move(t_game *game, t_position newposition);
static t_game_status	switch_position(t_game *game, t_position newposition);

//Switch the move depending of chosen direction
//Set the player direction in t_game for the sprite animation (turning)
//Assing to newposition the coordinates of the point to reach
//Try to reach the end point
t_game_status	move(t_game *game, int direction)
{
	t_position	new_position;

	new_position = *game->player_position;
	if (direction == W_KEY || direction == UP_ARROW)
	{
		game->player_direction = direction;
		return (new_position.x--, try_move(game, new_position));
	}
	if (direction == S_KEY || direction == DOWN_ARROW)
	{
		game->player_direction = direction;
		return (new_position.x++, try_move(game, new_position));
	}
	if (direction == D_KEY || direction == RIGHT_ARROW)
	{
		game->player_direction = direction;
		return (new_position.y++, try_move(game, new_position));
	}
	if (direction == A_KEY || direction == LEFT_ARROW)
	{
		game->player_direction = direction;
		return (new_position.y--, try_move(game, new_position));
	}
	return (playing);
}

//If ther's a wall => nothing to do
//If ther's a collectible, subtract 1 to collectibles count (countdown)
//Switch the position also in case of collectibles
static t_game_status	try_move(t_game *game, t_position newposition)
{
	if (game->map[newposition.x][newposition.y] == WALL)
		return (playing);
	if (game->map[newposition.x][newposition.y] == COLLECTIBLES)
		game->collectibles_count--;
	return (switch_position(game, newposition));
}

//Return the status of game after the move
//If the player arrive at the exit
//	If he took all collectibles => win
//	Else => nothing, just move above of the exit tile
//If ther's an enemy => lost but still move on that tile
//If player is on the exit, the char in map is still considered the exit and
//	not the player beacause the player position is considered in t_gamd
//IT IS DONE BEACAUSE WITHOUT IT, THE PLAYER COULDN'T HAVE GONE ON THE EXIT
//	POSITION BEACAUSE IT WOULDN'T HAVE BEEN KEEPED IN MEMORY BEACUASE
//	OVERWRITTEN BY PLAYER
//Set the player position to his new real position
//EXIT AND FLOOR ARE DEFINED 'CONSTANT' AND NOT WITH THE DEINIFTION IN .h JUST
//	BEACAUSE NORM
// TO DO solve this norm problem using constant defined in the header
static t_game_status	switch_position(t_game *game, t_position newposition)
{
	t_game_status	status;

	status = moved;
	if (game->map[newposition.x][newposition.y] == EXIT)
		if (game->collectibles_count == 0)
			status = win;
	if (game->map[newposition.x][newposition.y] == ENEMY)
		status = lose;
	game->map[newposition.x][newposition.y] = PLAYER;
	if (game->exit_position->x == game->player_position->x)
	{
		if (game->exit_position->y == game->player_position->y)
			game->map[game->player_position->x][game->player_position->y] = 'E';
		else
			game->map[game->player_position->x][game->player_position->y] = '0';
	}
	else
		game->map[game->player_position->x][game->player_position->y] = FLOOR;
	game->player_position->x = newposition.x;
	game->player_position->y = newposition.y;
	return (status);
}
