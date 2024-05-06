/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pop_tail.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maceccar <maceccar@student.42firenze.it>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/30 11:22:43 by maceccar          #+#    #+#             */
/*   Updated: 2024/05/03 00:47:17 by maceccar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stack.h"

int	ft_pop_tail(t_stack *stack)
{
	t_stack_node	*temp;
	int				result;

	if (ft_is_stack_empty(stack))
		return (0);
	if (stack->length == 1)
		return (ft_pop(stack));
	temp = stack->tail;
	result = temp->value;
	stack->tail = stack->tail->prev;
	stack->tail->next = NULL;
	free(temp);
	stack->length--;
	return (result);
}
