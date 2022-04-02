/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elraira- <elraira-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/21 15:44:12 by elraira-          #+#    #+#             */
/*   Updated: 2022/04/02 18:25:10 by elraira-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "../libft/libft.h"

/**
 * content: actual number
 * index: position -> useful for normalization
 * next: pointer to next node
 */
typedef struct s_node
{
	int				content;
	int				index;
	struct s_node	*next;
}				t_node;

/*.................................OPERATIONS.................................*/

/*..............................push operations...............................*/

void		push(t_node **stack_src, t_node **stack_dst);

/**
 * @brief Take the first element at the top of b and put it at
 * the top of a. Do nothing if b is empty.
 */
void		pa(t_node **stack_a, t_node **stack_b);

/**
 * @brief Take the first element at the top of a and put it at
	the top of b. Do nothing if a is empty.
 */
void		pb(t_node **stack_b, t_node **stack_a);

/*...............................swap operations..............................*/

void		swap(t_node **stack);

/**
 * @brief Swap the first 2 elements at the top of stack a.
 * Do nothing if there is only one or no elements
 */
void		sa(t_node **stack_a);

/**
 * @brief Swap the first 2 elements at the top of stack b.
 * Do nothing if there is only one or no elements.
 */
void		sb(t_node **stack_b);

/**
 * @brief Swap the first 2 elements at the top of stack a and b at the
 * same time.
 */
void		ss(t_node **stack_a, t_node **stack_b);

/*..............................rotate operations.............................*/

void		rotate(t_node **stack);

/**
 * @brief Shift up all elements of stack a by 1.
 * The first element becomes the last one.
 */
void		ra(t_node **stack_a);

/**
 * @brief Shift up all elements of stack b by 1.
 * The first element becomes the last one.
 */
void		rb(t_node **stack_b);

/**
 * @brief Shift up all elements of stack a and b by 1 at the same time.
 */
void		rr(t_node **stack_a, t_node **stack_b);

/*.............................reverse operations.............................*/

void		reverse_rotate(t_node **stack);

/**
 * @brief Shift down all elements of stack a by 1.
The last element becomes the first one.
 */
void		rra(t_node **stack_a);

/**
 * @brief Shift down all elements of stack b by 1.
The last element becomes the first one.
 */
void		rrb(t_node **stack_b);

/**
 * @brief Shift down all elements of stack a and b by 1 at the same time.
 */
void		rrr(t_node **stack_a, t_node **stack_b);

/* .....................linked_list_utils.c functions.........................*/
/**
 * @brief Create a node object. Allocates memory for a new node.
 */
t_node		*ft_create_node(int content);

/**
 * @brief Returns the last node of the list.
 */
t_node		*ft_get_last_node(t_node *head);

/**
 * @brief Adds a node at the beginning of the list.
 */
void		ft_add_node_to_front(t_node **stack, t_node *new_node);

/**
 * @brief Adds a node at the end of the list.
 */
void		ft_add_node_to_back(t_node **stack, t_node *new_node);

/*...........................init_stack.c functions...........................*/

/**
 * @brief Initialises stack and fill it with argv nodes.
 *
 * @param argc number of arguments received via command line
 * @param argv arguments
 */
void		ft_init_stack(t_node **stack, int argc, char **argv);

t_node		*ft_get_next_min(t_node **stack);

/**
 * @brief Assigns their index to the nodes of the stack during initialization.
 */
void		ft_add_index_to_stack(t_node **stack);

/*..............................free.c functions..............................*/
/**
 * @brief Frees the entire stack.
 */
void		ft_free_stack(t_node **stack);

/**
 * @brief Frees string allocated using ft_split (argv).
 */
void		ft_free_str(char **str);

/*......................validation_functions.c functions......................*/

/**
 * @brief Splits argv, checks if it's numeric, if there are
 * repeated arguments, send error messages.
 */
void		ft_check_arguments(int argc, char **argv);

/**
 * @brief Checks if any number was passed more than once.
 */
int			ft_is_repeated(int num, char **argv, int i);

/**
 * @brief Outputs "Error" and exit program in case of: arguments that aren't
 * numbers, arguments bigger than an integer or duplicates.
 *
 * @param msg message to be outputted.
 */
void		ft_error_msg_and_exit(char *msg);

/*.........................simple_sorting_functions.c.........................*/

/**
 * @brief Searches for smaller number in stack.
 */
int			ft_min_idx(t_node **stack, int content);

/**
 * @brief This function will sort stacks with 3 numbers.
 */
void		ft_sort_three(t_node **stack_a);

/**
 * @brief Returns the distance between the head node and the node within the
 * searched index.
 */
int			ft_get_distance_to_node(t_node **stack, int index);

/**
 * @brief This function will sort stacks with 4 numbers.
 */
void		ft_sort_four(t_node **stack_a, t_node **stack_b);

/**
 * @brief This function will sort stacks with 5 numbers.
 */
void		ft_sort_five(t_node **stack_a, t_node **stack_b);

/*............................push_swap.c functions...........................*/
/**
 * @brief Checks if the stack is already sorted.
 */
int			ft_is_stack_sorted(t_node **stack);

/**
 * @brief Returns stack size.
 *
 * @param head First node
 * @return int Size
 */
int			ft_stack_size(t_node *head);

/**
 * @brief Selects which function will be responsible for sorting according to
 * size to sort.
 */
void		ft_sort_stack(t_node **stack_a, t_node **stack_b);

/**
 * @brief When stack < 5, this functions sends it to the corresponding sorting
 * function according to the size of the stack (three, four or five).
 */
void		ft_simple_sort(t_node **stack_a, t_node **stack_b);

/**
 * @brief Radix sorting of values by binary indexing.
 */
void		ft_radix_sort(t_node **stack_a, t_node **stack_b);

#endif
