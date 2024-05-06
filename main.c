/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maceccar <maceccar@student.42firenze.it>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/30 11:22:43 by maceccar          #+#    #+#             */
/*   Updated: 2024/05/03 00:47:17 by maceccar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

//Args check
//Parsing and check map
//Start game
//Free game in each case at the end of program
int	main(int argc, char *argv[])
{
	t_game	*game;

	if (argc != 2)
	{
		ft_printf("Error, Specify a map file\n");
		return (0);
	}
	game = get_map(argv[1]);
	if (!game)
		ft_printf("Error, allocation failed!!\n");
	if (game->is_map_valid == false)
		ft_printf("%s\n", game->reason);
	else
		start_game(game);
	free_game(game);
}
