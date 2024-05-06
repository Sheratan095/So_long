/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_validation.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maceccar <maceccar@student.42firenze.it>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/30 11:22:43 by maceccar          #+#    #+#             */
/*   Updated: 2024/05/03 00:47:17 by maceccar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

t_bool			validate_content(t_game *game);
static t_bool	is_surrended_by_walls(char *map[]);
static void		try_reach(char **map, t_position s_pos, int *n_ex, int *n_col);

//Check if the map is surrended by walls
//Validate content, the message will be chosen depending on the error
//Duplicate the map
//	=>Try to reach all collectibles and the exit
//Map validation is set by default to false and it's changed when the
//	map is checked
void	validate_map(t_game *game)
{
	char	**tmp_matrix;
	int		exit;
	int		collectibles;

	exit = 0;
	collectibles = 0;
	if (is_surrended_by_walls(game->map) == false)
	{
		game->reason = "Map isn't surrended by walls";
		return ;
	}
	if (validate_content(game) == false)
		return ;
	tmp_matrix = ft_duplicate_char_matrix(game->map);
	try_reach(tmp_matrix, *game->player_position, &exit, &collectibles);
	game->is_map_valid = false;
	if (collectibles != game->collectibles_count)
		game->reason = "Not all collectibles are reachable";
	else if (exit == 0)
		game->reason = "Exit isn't reachable";
	else
		game->is_map_valid = true;
	if (tmp_matrix)
		ft_free_matrix((void **)tmp_matrix);
}

//Check if the first and last chars in a row are walls (100000001)
//Check if first and last row are all composed by 1    (111111111)
static t_bool	is_surrended_by_walls(char *map[])
{
	int		i;
	size_t	j;
	size_t	column_number;

	i = 1;
	j = 0;
	column_number = ft_strlen(map[0]);
	while (map[i + 1])
	{
		if (map[i][0] != WALL || map[i][column_number - 1] != WALL)
			return (false);
		i++;
	}
	while (j < column_number)
	{
		if (map[0][j] != WALL || map[i][j] != WALL)
			return (false);
		j++;
	}
	return (true);
}

//Recursive function to establish if ther's a valid path to reach 
//	all collectibles and the exit
//s_pos: starting position
//n_ex: establish if exit is reachable
//n_col: number of rechable collectibles
//n_ex & n_col are pointer to int defined in the primary function
//	beacause of error handling, i can't be done properly in a
//	recursive function, so the data are to be stored and checked
//	at the end of recursice function in the primary (validate_map)
void	try_reach(char **map, t_position s_pos, int *n_ex, int *n_col)
{
	int			x;
	int			y;

	x = s_pos.x;
	y = s_pos.y;
	if (map[x][y] == EXIT)
		*n_ex = 1;
	if (map[x][y] == COLLECTIBLES)
		(*n_col)++;
	if (map[x][y] == WALL || map[x][y] == 'v' || map[x][y] == ENEMY)
		return ;
	map[x][y] = 'v';
	s_pos.x = x + 1;
	s_pos.y = y;
	try_reach(map, s_pos, n_ex, n_col);
	s_pos.x = x;
	s_pos.y = y + 1;
	try_reach(map, s_pos, n_ex, n_col);
	s_pos.x = x - 1;
	s_pos.y = y;
	try_reach(map, s_pos, n_ex, n_col);
	s_pos.x = x;
	s_pos.y = y -1;
	try_reach(map, s_pos, n_ex, n_col);
	return ;
}
