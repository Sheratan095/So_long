/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_content.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maceccar <maceccar@student.42firenze.it>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/30 11:22:43 by maceccar          #+#    #+#             */
/*   Updated: 2024/05/03 00:47:17 by maceccar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

static t_bool	search_components(t_game *game, int *n_exit, int *n_player);
static int		switch_element_type(t_game *game, int i, int j, int *n_exit);
static void		add_enemy_to_list(t_game *game, int x, int y);

// CHECK THE MAP LOOKING FOR THE RIGHT NUMBER OF ELEMENT AND INITIALIZE THE
//	MAIN PARAMETERS OF t_game
// exit_count and player_position count are used to handle differende type
//	message depending of the error
// Alloc player and exit position and initialize
//	collectibles_count in t_game
// Read all the map content and check the number of elements
t_bool	validate_content(t_game *game)
{
	int	exit_count;
	int	player_position_count;

	player_position_count = 0;
	exit_count = 0;
	game->collectibles_count = 0;
	game->player_position = malloc(sizeof(t_position));
	game->exit_position = malloc(sizeof(t_position));
	if (!game->exit_position || !game->player_position)
		return (false);
	if (search_components(game, &exit_count, &player_position_count) == false)
		return (game->reason = "found an unknow element", false);
	if (player_position_count != 1)
	{
		game->reason = "Wrong number of player position, it must be 1";
		return (false);
	}
	else if (game->collectibles_count < 1)
	{
		game->reason = "Wrong number of collectibles, it must be >= 1";
		return (false);
	}
	else if (exit_count != 1)
		return (game->reason = "Wrong number of exit, it should be 1", false);
	return (game->is_map_valid = true, true);
}

// Pass throw the map
// For each element check his type
// If is unknowrn => error
// If number of founder player is 1 => add 1
// n_player: number of player position
// n_exit: number of exit
// THIS BAD OF MANAGEMENT OF PARAMETERS IS CAUSED BY NORM, IT COULD BE DONE
//	ALSO WITH GLOBAL VARIABLES
static t_bool	search_components(t_game *game, int *n_exit, int *n_player)
{
	int	i;
	int	j;
	int	tmp;

	i = 1;
	tmp = 0;
	while (game->map[i])
	{
		j = 1;
		while (game->map[i][j])
		{
			tmp = switch_element_type(game, i, j, n_exit);
			if (tmp == -1)
				return (false);
			else if (tmp == 1)
				(*n_player)++;
			j++;
		}
		i++;
	}
	return (true);
}

// LITERALLY A SWITCH
// Return 1 if the char examinated rappresent the starting position of the
//	player
// Return 0 for all the other components
// Return -1 if an unidentified character was found
// When the player or the exit position are found, their coordinates are
//	assigned to the respective variable in t_game
// THIS BAD OF MANAGEMENT OF PARAMETERS IS CAUSED BY NORM, IT COULD BE DONE
//	ALSO WITH GLOBAL VARIABLES
static int	switch_element_type(t_game *game, int i, int j, int *exit_num)
{
	int	player_num;

	player_num = 0;
	if (game->map[i][j] == PLAYER)
	{
		game->player_position->x = i;
		game->player_position->y = j;
		player_num++;
	}
	else if (game->map[i][j] == COLLECTIBLES)
		game->collectibles_count++;
	else if (game->map[i][j] == EXIT)
	{
		game->exit_position->x = i;
		game->exit_position->y = j;
		(*exit_num)++;
	}
	else if (game->map[i][j] == ENEMY)
		add_enemy_to_list(game, i, j);
	else if (game->map[i][j] != WALL && game->map[i][j] != FLOOR)
		return (-1);
	return (player_num);
}

//Add enemies to a list
//It's usefull to leet them move whiout causing problem
//	Main problem: passing throw the map anche making move one enemy
//	each time, it could go in the next tile, witch will be considered
//	as enother enemy and moved again
//	it would makes move the same enemy more time in the same "frame"
static void	add_enemy_to_list(t_game *game, int x, int y)
{
	t_position	*new_enemy_position;

	new_enemy_position = malloc(sizeof(t_position));
	if (new_enemy_position)
	{
		new_enemy_position->x = x;
		new_enemy_position->y = y;
		ft_lstadd_front(&game->enemies, ft_lstnew(new_enemy_position));
	}
}
