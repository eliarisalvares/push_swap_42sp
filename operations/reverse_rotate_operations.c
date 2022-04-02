/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate_operations.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elraira- <elraira-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/21 16:48:31 by elraira-          #+#    #+#             */
/*   Updated: 2022/03/30 08:35:07 by elraira-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

/* This file contains all "reverse rotate" operations determined by the subject:
rra (reverse rotate a): Shift down all elements of stack a by 1.
	The last element becomes the first one.
rrb (reverse rotate b): Shift down all elements of stack b by 1.
	The last element becomes the first one.
rrr: rra and rrb at the same time.
*/

void	reverse_rotate(t_node **stack)
{
	t_node	*prev_tail;
	t_node	*tail;

	if (ft_stack_size(*stack) > 2)
	{
		prev_tail = *stack;
		while (prev_tail->next->next)
			prev_tail = prev_tail->next;
		tail = prev_tail->next;
		prev_tail->next = NULL;
		tail->next = *stack;
		*stack = tail;
	}
}

void	rra(t_node **stack_a)
{
	reverse_rotate(stack_a);
	ft_putendl_fd("rra", 1);
}

void	rrb(t_node **stack_b)
{
	reverse_rotate(stack_b);
	ft_putendl_fd("rrb", 1);
}

void	rrr(t_node **stack_a, t_node **stack_b)
{
	reverse_rotate(stack_a);
	reverse_rotate(stack_b);
	ft_putendl_fd("rrr", 1);
}
