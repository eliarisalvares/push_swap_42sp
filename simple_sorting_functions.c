/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simple_sorting_functions.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elraira- <elraira-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/21 15:43:59 by elraira-          #+#    #+#             */
/*   Updated: 2022/04/02 17:54:47 by elraira-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

/**
	This file contains the functions that will sort stacks with up to 5 numbers.
*/

/*	Searches for smaller number in stack
*/
int	ft_min_idx(t_node **stack, int content)
{
	t_node	*head;
	int		min_index;

	head = *stack;
	min_index = head->index;
	while (head->next)
	{
		head = head->next;
		if ((head->index < min_index) && head->index != content)
			min_index = head->index;
	}
	return (min_index);
}

/*
This function will sort stacks with 3 numbers.
	first case:
		when n1 is the minimum index and n2 is bigger than n3
	second case:
		when n1 is the second minimum index
		2.1: n2 is smaller than n1
		2.2: n2 is bigger than n1
	third case:
		else
		3.1: n2 is the minimum index
		3.2: n3 is the minimum index
*/
void	ft_sort_three(t_node **stack_a)
{
	if ((*stack_a)->index == ft_min_idx(stack_a, -1) && (*stack_a)->next->index
		> (*stack_a)->next->next->index)
	{
		ra(stack_a);
		sa(stack_a);
		rra(stack_a);
	}
	else if ((*stack_a)->index
		== ft_min_idx(stack_a, ft_min_idx(stack_a, -1)))
	{
		if ((*stack_a)->next->index < (*stack_a)->index)
			sa(stack_a);
		else
			rra(stack_a);
	}
	else
	{
		if ((*stack_a)->next->index == ft_min_idx(stack_a, -1))
			ra(stack_a);
		else
		{
			sa(stack_a);
			rra(stack_a);
		}
	}
}

/*	Returns the distance between the start node and the node within the
searched index.
*/
int	ft_get_distance_to_node(t_node **stack, int index)
{
	t_node	*head;
	int		distance_node;

	distance_node = 0;
	head = *stack;
	while (head)
	{
		if (head->index == index)
			break ;
		distance_node++;
		head = head->next;
	}
	return (distance_node);
}

/*
This function will sort stacks with 4 numbers.
	first case:
		when the minimum index is n2
	second case:
		when the minimum index is n3
	third case:
		when the minimum index is n4
	then:
		when the first number is at its place, whe move the first number to
		stack b and order the remaining numbers at stack a using ft_sort_three.
		at last, the first number can be returned to stack a using pa.
*/
void	ft_sort_four(t_node **stack_a, t_node **stack_b)
{
	int	distance;

	distance = ft_get_distance_to_node(stack_a, ft_min_idx(stack_a, -1));
	if (distance == 1)
		ra(stack_a);
	else if (distance == 2)
	{
		ra(stack_a);
		ra(stack_a);
	}
	else if (distance == 3)
		rra(stack_a);
	if (!ft_is_stack_sorted(stack_a))
	{
		pb(stack_a, stack_b);
		ft_sort_three(stack_a);
		pa(stack_b, stack_a);
	}
}

/*
This function will sort stacks with 5 numbers.
	first case:
		when the minimum index is n2
	second case:
		when the minimum index is n3
	third case:
		when the minimum index is n4
	fourth case:
		when the minimum index is n5
	then:
		when the first number is at its place, whe move the first number to
		stack b and order the remaining numbers at stack a using ft_sort_four.
		at last, the first number can be returned to stack a using pa.
*/
void	ft_sort_five(t_node **stack_a, t_node **stack_b)
{
	int	distance;

	distance = ft_get_distance_to_node(stack_a, ft_min_idx(stack_a, -1));
	if (distance == 1)
		ra(stack_a);
	else if (distance == 2)
	{
		ra(stack_a);
		ra(stack_a);
	}
	else if (distance == 3)
	{
		rra(stack_a);
		rra(stack_a);
	}
	else if (distance == 4)
		rra(stack_a);
	if (ft_is_stack_sorted(stack_a))
		return ;
	pb(stack_a, stack_b);
	ft_sort_four(stack_a, stack_b);
	pa(stack_b, stack_a);
}
