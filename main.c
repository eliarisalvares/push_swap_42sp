/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elraira- <elraira-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/21 15:43:19 by elraira-          #+#    #+#             */
/*   Updated: 2022/03/31 17:57:41 by elraira-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

/*	The main function receives arguments from input.
	Lines 6-7: According to the subject: "If no parameters are specified,
		the program must not display anything and give the prompt back."
	Line 8: ft_check_arguments function -> this function splits single input
		line using ' '(space) as a delimiter when argc = 2 (executable + ints).
		Once it's done or argc > 2, we can begin to iterate over the arguments,
		first of all converting then into longs (the program must display an
		error message with longs, but accepts then as arguments), then checking
		if they are integers (between int_min and int_max), if there are no
		characters other than digits and no repeated arguments.
	Line 9-12: Allocating memory and initializing stacks values.
	Line 13: ft_init_stack function - > Just like the validation function,
		this one splits argument line if all integers are passed together
		(argv[1]). Then, strings are converted into integers and allocated into
		linked list as a new node using function "ft_create_node" and
		"ft_add_node_to_back". Then indexes are added to the stack. At the end,
		if there are still 2 arguments there are no operations to be made and
		anything allocated with ft_split can be freed.
	Lines 14-19: Checks if stack is already sorted. If it is, it can be freed.
	Line 15: If stack is not sorted, the function ft_sort_stack sends the stack
		to the tight sorting algorithm. If smaller then 5 elements, the stack
		will be sorted using simples_sorting_functions.c functions. Otherwise,
		it will be sorted using radix sort.
	Lines 16-19: After being sorted, the stack can be freed.
*/
int	main(int argc, char **argv)
{
	t_node	**stack_a;
	t_node	**stack_b;

	if (argc < 2)
		return (0);
	ft_check_arguments(argc, argv);
	stack_a = malloc(sizeof(t_node *));
	stack_b = malloc(sizeof(t_node *));
	*stack_a = NULL;
	*stack_b = NULL;
	ft_init_stack(stack_a, argc, argv);
	if (ft_is_stack_sorted(stack_a))
	{
		ft_free_stack(stack_a);
		ft_free_stack(stack_b);
		return (0);
	}
	ft_sort_stack(stack_a, stack_b);
	ft_free_stack(stack_a);
	ft_free_stack(stack_b);
	return (0);
}
