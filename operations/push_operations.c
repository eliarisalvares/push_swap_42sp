/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_operations.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elraira- <elraira-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/21 16:51:16 by elraira-          #+#    #+#             */
/*   Updated: 2022/03/30 20:37:09 by elraira-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

/* This file contains all "push" operations determined by the subject:
pa (push a): Take the first element at the top of b and put it at the top of a.
	Do nothing if b is empty.
pb (push b): Take the first element at the top of a and put it at the top of b.
	Do nothing if a is empty.
*/

void	push(t_node **stack_src, t_node **stack_dst)
{
	t_node	*tmp;

	if (ft_stack_size(*stack_src) != 0)
	{
		tmp = *stack_src;
		*stack_src = (*stack_src)->next;
		ft_add_node_to_front(stack_dst, tmp);
	}
}

void	pa(t_node **stack_b, t_node **stack_a)
{
	push(stack_b, stack_a);
	ft_putendl_fd("pa", 1);
}

void	pb(t_node **stack_a, t_node **stack_b)
{
	push(stack_a, stack_b);
	ft_putendl_fd("pb", 1);
}
