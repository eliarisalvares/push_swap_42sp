/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validation_functions.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elraira- <elraira-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/21 15:43:05 by elraira-          #+#    #+#             */
/*   Updated: 2022/04/02 20:04:58 by elraira-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

/*
	This file contains functions responsible for checking if argv is valid and
		outputting error message and closing the program when it is not.
*/

/*	Checks if any number was passed more than once.
*/
int	ft_is_repeated(int num, char **argv, int i)
{
	i++;
	while (argv[i])
	{
		if (ft_atol(argv[i]) == num)
			return (1);
		i++;
	}
	return (0);
}

/*	Outputs "Error" and exit program in case of: arguments that aren't
numbers, arguments bigger than an integer or duplicates.
*/
void	ft_error_msg_and_exit(char *msg)
{
	ft_putendl_fd(msg, 2);
	exit(0);
}

/*	According to the subject: "In case of error, it must display "Error"
		followed by a '\n' on the standard error.
	Errors include for example: some arguments aren’t integers, some arguments
		are bigger than an integer and/or there are duplicates."
	At the end, if there are still 2 arguments there are no operations to be
		made and anything  allocated with ft_split can be freed.
*/
void	ft_check_arguments(int argc, char **argv)
{
	int		i;
	long	tmp;

	i = 0;
	if (*argv && argc == 2)
		argv = ft_split(argv[1], ' ');
	else
		i = 1;
	while (argv[i])
	{
		tmp = ft_atol(argv[i]);
		if (!ft_str_isdigit(argv[i]) || ft_is_repeated(tmp, argv, i))
			ft_error_msg_and_exit("Error");
		if (tmp < -2147483648 || tmp > 2147483647)
			ft_error_msg_and_exit("Error");
		i++;
	}
	if (argc == 2)
		ft_free_str(argv);
}
