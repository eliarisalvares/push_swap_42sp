/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_operations.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elraira- <elraira-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/21 16:45:57 by elraira-          #+#    #+#             */
/*   Updated: 2022/03/30 08:35:15 by elraira-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

/* This file contains all "rotate" operations determined by the subject:
ra (rotate a): Shift up all elements of stack a by 1.
	The first element becomes the last one.
rb (rotate b): Shift up all elements of stack b by 1.
	The first element becomes the last one.
rr : ra and rb at the same time.
*/

void	rotate(t_node **stack)
{
	t_node	*tail;
	t_node	*head;

	if (ft_stack_size(*stack) > 2)
	{
		tail = ft_get_last_node(*stack);
		head = *stack;
		*stack = (*stack)->next;
		tail->next = head;
		head->next = NULL;
	}
}

void	ra(t_node **stack_a)
{
	rotate(stack_a);
	ft_putendl_fd("ra", 1);
}

void	rb(t_node **stack_b)
{
	rotate(stack_b);
	ft_putendl_fd("rb", 1);
}

void	rr(t_node **stack_a, t_node **stack_b)
{
	rotate(stack_a);
	rotate(stack_b);
	ft_putendl_fd("rr", 1);
}
