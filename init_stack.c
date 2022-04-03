/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_stack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elraira- <elraira-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/29 22:52:21 by elraira-          #+#    #+#             */
/*   Updated: 2022/04/03 20:46:13 by elraira-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/push_swap.h"

/**
	This file contains the functions related to stacks initialization and
		indexing.
*/

t_node	*ft_get_next_min(t_node **stack)
{
	t_node	*head;
	t_node	*min;
	int		has_min;

	min = NULL;
	has_min = 0;
	head = *stack;
	if (head)
	{
		while (head)
		{
			if ((head->index == -1) && (!has_min || head->content
					< min->content))
			{
				min = head;
				has_min = 1;
			}
			head = head->next;
		}
	}
	return (min);
}

/**	This function is used for assigning an index value for radixing. It is
		useful as it allows to makes things simpler and makes working with
		negative numbers possible. For each number we add to the stack, it
		checks if it is smaller than what the smallest value found previously.
 */
void	ft_add_index_to_stack(t_node **stack)
{
	t_node	*head;
	int		index;

	index = 0;
	head = ft_get_next_min(stack);
	while (head)
	{
		head->index = index++;
		head = ft_get_next_min(stack);
	}
}

/*	Just like the validation function, this one splits argument line if all
integers are passed together (argv[1]). Then, strings are converted into
integers and allocated into linked list as a new node using function
"ft_create_node" and "ft_add_node_to_back". Then, indexes are added to the
stack. At the end, if there are still 2 arguments there are no operations to be
made and anything allocated with ft_split can be freed.
*/
void	ft_init_stack(t_node **stack, int argc, char **argv)
{
	t_node	*new;
	int		i;

	i = 0;
	if (argc == 2)
		argv = ft_split(argv[1], ' ');
	else
		i = 1;
	while (argv[i])
	{
		new = ft_create_node(ft_atoi(argv[i]));
		ft_add_node_to_back(stack, new);
		i++;
	}
	ft_add_index_to_stack(stack);
	if (argc == 2)
		ft_free_str(argv);
}
