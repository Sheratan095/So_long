/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pop.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maceccar <maceccar@student.42firenze.it>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/30 11:22:43 by maceccar          #+#    #+#             */
/*   Updated: 2024/05/03 00:47:17 by maceccar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stack.h"

int	ft_pop(t_stack *stack)
{
	t_stack_node	*temp;
	int				result;

	if (ft_is_stack_empty(stack))
		return (0);
	temp = stack->head;
	result = temp->value;
	stack->head = stack->head->next;
	if (stack->head != NULL)
		stack->head->prev = NULL;
	free(temp);
	stack->length--;
	return (result);
}
