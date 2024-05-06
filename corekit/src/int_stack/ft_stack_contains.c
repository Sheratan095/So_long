/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stack_contains.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maceccar <maceccar@student.42firenze.it>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/30 11:22:43 by maceccar          #+#    #+#             */
/*   Updated: 2024/05/03 00:47:17 by maceccar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stack.h"

t_stack_node	*ft_stack_contains(t_stack *stack, int value)
{
	t_stack_node	*temp;

	if (ft_is_stack_empty(stack))
		return (NULL);
	temp = stack->head;
	while (temp != NULL)
	{
		if (temp->value == value)
			return (temp);
		temp = temp->next;
	}
	return (NULL);
}
