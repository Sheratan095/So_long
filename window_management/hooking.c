/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooking.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maceccar <maceccar@student.42firenze.it>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/30 11:22:43 by maceccar          #+#    #+#             */
/*   Updated: 2024/05/03 00:47:17 by maceccar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

static int	handle_keyboard_input(int keysym, t_vars *vars);
int			destroy_notify(t_vars *vars);
int			enemy_movement(t_vars *vars);

//Start all hooks
//mlx_key_hook: when a key is pressed, the handle_keyboard_input is called with
	//vars as parameter
//mlx_hook: when a event is invoked (DESTROY__NOTIFY)
//	the destroy_notify is called with vars as parameter
//	1L << 0 : xmask of the event
//mlx_loop_hook: call the function (render_next_frame) each frame
//	THERE CAN BE ONLY ONE
int	hook(t_vars *vars)
{
	mlx_key_hook(vars->win, handle_keyboard_input, vars);
	mlx_hook(vars->win, DESTROY_NOTIFY, 1L << 0, destroy_notify, vars);
	mlx_loop_hook(vars->mlx, render_next_frame, vars);
	return (0);
}

//Called when X in top right of windows is pressed
//	Non-statis because it's used in finish_game
int	destroy_notify(t_vars *vars)
{
	end(vars, false);
	return (1);
}

//If ESC is pressend => game end
//Try move
//If moved
//	Update and print the movement count in cosole
//Else check the status to determine if the player win or lose
static int	handle_keyboard_input(int keysym, t_vars *vars)
{
	t_game_status	status;

	if (keysym == KEY_ESC)
		end(vars, false);
	status = move(vars->game, keysym);
	if (status == moved)
		ft_printf("Movement count: %i\n", ++vars->game->number_of_moves);
	if (status == win || status == lose)
		finish_game(vars, status);
	return (0);
}
