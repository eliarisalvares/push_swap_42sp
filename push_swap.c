/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elraira- <elraira-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/21 15:44:51 by elraira-          #+#    #+#             */
/*   Updated: 2022/04/02 17:55:46 by elraira-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

/*
	This file contains the main functions related to actually sorting the
		stacks: verifying if it is already sorted and checking its size to then
		assing it to the corresponding sorting algorithm.
*/

/*	Checks if the stack is already sorted.
*/
int	ft_is_stack_sorted(t_node **stack)
{
	t_node	*head;

	head = *stack;
	while (head->next)
	{
		if (head->content > head->next->content)
			return (0);
		head = head->next;
	}
	return (1);
}

/*	Returns stack size.
*/
int	ft_stack_size(t_node *head)
{
	int	stack_size;

	stack_size = 0;
	while (head)
	{
		stack_size++;
		head = head->next;
	}
	return (stack_size);
}

/*	Selects which function will be responsible for sorting according to size
		to sort.
*/
void	ft_sort_stack(t_node **stack_a, t_node **stack_b)
{
	if (ft_stack_size(*stack_a) <= 5)
		ft_simple_sort(stack_a, stack_b);
	else
		ft_radix_sort(stack_a, stack_b);
}

/*	When stack < 5, this functions sends it to the corresponding sorting
		function according to the size of the stack (three, four or five).
		If stack = 2, it swaps.
*/
void	ft_simple_sort(t_node **stack_a, t_node **stack_b)
{
	int	size;

	if (ft_is_stack_sorted(stack_a) || ft_stack_size(*stack_a) == 0
		|| ft_stack_size(*stack_a) == 1)
		return ;
	size = ft_stack_size(*stack_a);
	if (size == 2)
		sa(stack_a);
	else if (size == 3)
		ft_sort_three(stack_a);
	else if (size == 4)
		ft_sort_four(stack_a, stack_b);
	else if (size == 5)
		ft_sort_five(stack_a, stack_b);
}

/**
	Stack A is box 1 and stack B is box 0. First, we star from
		rightmost bit. All 1s bits get pushed to the bottom (ra).
		Else, if bit = 0, they get stored in stack B (pb). Once all smaller
		ones (0s) are in b they can be pushed back one by one on top of stack a
		(pa).
	Once rightmost is done, we can move to the left until everything is sorted.

*
* Example:
*
Unsorted Stack:

	100
	000
	110
	001
	101
	010
	011
----------     ----------
	a              b
*
Sending least significant bit to stack b

	              010
	001           110
	101           000
	011           100
----------     ----------
	a              b

End result for first bit:

	100
	000
	110
	010
	001
	101
	011
----------     ----------
	a              b
*/
void	ft_radix_sort(t_node **stack_a, t_node **stack_b)
{
	int		i;
	int		j;
	int		size;

	i = 0;
	size = ft_stack_size(*stack_a);
	while (!ft_is_stack_sorted(stack_a))
	{
		j = 0;
		while (j++ < size)
		{
			if ((((*stack_a)->index >> i) & 1) == 1)
				ra(stack_a);
			else
				pb(stack_a, stack_b);
		}
		while (ft_stack_size(*stack_b) != 0)
			pa(stack_b, stack_a);
		i++;
	}
}
