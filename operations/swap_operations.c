/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap_operations.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elraira- <elraira-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/21 16:42:45 by elraira-          #+#    #+#             */
/*   Updated: 2022/03/30 08:35:46 by elraira-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

/* This file contains all "swap" operations determined by the subject:
sa (swap a): Swap the first 2 elements at the top of stack a.
	Do nothing if there is only one or no elements.
sb (swap b): Swap the first 2 elements at the top of stack b.
	Do nothing if there is only one or no elements.
ss : sa and sb at the same time.
*/

void	swap(t_node **stack)
{
	t_node	*tmp;

	if (ft_stack_size(*stack) > 2)
	{
		tmp = (*stack)->next;
		(*stack)->next = tmp->next;
		tmp->next = *stack;
		*stack = tmp;
	}
}

void	sa(t_node **stack_a)
{
	swap(stack_a);
	ft_putendl_fd("sa", 1);
}

void	sb(t_node **stack_b)
{
	swap(stack_b);
	ft_putendl_fd("sb", 1);
}

void	ss(t_node **stack_a, t_node **stack_b)
{
	swap(stack_a);
	swap(stack_b);
	ft_putendl_fd("ss", 1);
}
