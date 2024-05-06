/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maceccar <maceccar@student.42firenze.it>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/30 11:22:43 by maceccar          #+#    #+#             */
/*   Updated: 2024/05/03 00:47:17 by maceccar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STACK_H
# define STACK_H

# include "corekit.h"

/**
	Struct used for the dubly linked list of int

	Circular dependency: con't use t_stack because it isn't still defined
			This will result in a compilation error because the compiler
			doesn't know what t_stack is at that point.
*/

typedef struct s_stack_node
{
	int					value;
	struct s_stack_node	*next;
	struct s_stack_node	*prev;
}	t_stack_node;

typedef struct s_stack
{
	int					length;
	struct s_stack_node	*head;
	struct s_stack_node	*tail;
}	t_stack;

t_stack			*ft_initialize_stack(t_stack *stack);

t_stack_node	*ft_create_node(int value);

enum e_bool		ft_is_stack_empty(t_stack *stack);

/**
	@brief Add new node to the stack
	@param stack pointer to stack
	@param new_value value to assign to the new node
	@return Pointer to stack
*/
t_stack			*ft_push(t_stack *stack, int new_value);

/**
	@brief Remove top element of the stack
	@param stack pointer to stack
	@return Value of popped node
*/
int				ft_pop(t_stack *stack);

/**
	@brief Remove last element of the stack
	@param stack pointer to stack
	@return Value of popped node
*/
int				ft_pop_tail(t_stack *stack);

/**
	@brief Print in the termial the stack, starting from top
	@param stack pointer to stack
*/
void			ft_display_stack(t_stack *stack);

/**
	@brief Free the stack
	@param stack pointer to stack
*/
void			ft_free_stack(t_stack *stack);

/**
	@brief Checks if value exists inside of stack
	@param stack pointer to stack
	@param value value to search
	@return the node found or NULL
*/
t_stack_node	*ft_stack_contains(t_stack *stack, int value);

/**
	@brief Search duplicate node of equal value after node pointer
	@param stack pointer to stack
	@return true if duplicate is found
*/
enum e_bool		ft_search_duplicate(t_stack *stack);

/**
	@brief Add new node to the bottom of the stack
	@param stack pointer to stack
	@param new_value value to assign to the new node
	@return Pointer to stack
*/
t_stack			*ft_push_tail(t_stack *stack, int new_value);

#endif
