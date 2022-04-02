/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   linked_list_utils.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elraira- <elraira-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/21 15:43:14 by elraira-          #+#    #+#             */
/*   Updated: 2022/04/02 17:54:29 by elraira-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

/*
	This file contains functions related to the creation and appending of nodes
		to the linked list.
*/

/*	Returns the last node of the list.
*/
t_node	*ft_get_last_node(t_node *head)
{
	if (!head)
		return (NULL);
	while (head -> next)
		head = head -> next;
	return (head);
}

/*	Create a node object. Allocates memory for a new node.
*/
t_node	*ft_create_node(int content)
{
	t_node	*new_node;

	new_node = malloc(sizeof(t_node));
	if (!new_node)
		return (NULL);
	new_node->content = content;
	new_node->index = -1;
	new_node->next = NULL;
	return (new_node);
}

/*	Adds a node at the beginning of the list.
*/
void	ft_add_node_to_front(t_node **stack, t_node *new_node)
{
	if (!new_node)
		return ;
	new_node -> next = *stack;
	*stack = new_node;
}

/*	Adds a node at the end of the list.
*/
void	ft_add_node_to_back(t_node **stack, t_node *new_node)
{
	t_node	*tmp;

	if (!new_node)
		return ;
	if (*stack)
	{
		tmp = ft_get_last_node(*stack);
		tmp -> next = new_node;
	}
	else
		*stack = new_node;
}
