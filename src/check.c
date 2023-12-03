/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: raalonso <raalonso@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/10 22:21:48 by raalonso          #+#    #+#             */
/*   Updated: 2023/12/03 22:35:48 by raalonso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/push_swap.h"

int	check_are_num(int argc, char **argv)
{
	int	i;

	i = 0;
	if (argv[argc - 1][0] == '\0')
		return (1);
	while (argv[argc - 1][i] != '\0')
	{
		if ((argv[argc - 1][i] < '0' || argv[argc - 1][i] > '9')
			&& argv[argc - 1][i] != '-')
			return (1);
		if (argv[argc - 1][i] == '-' &&
			(argv[argc - 1][i + 1] == '\0' || i != 0))
			return (1);
		i++;
	}
	return (0);
}

/*Checks that the arguments are only numbers, and they do not repeat.*/
int	check_arg(int argc, char **argv)
{
	int		i;
	long	num;

	while (argc > 1)
	{
		if (check_are_num(argc, argv) == 1)
			return (1);
		i = argc - 1;
		num = (long)ft_atoi(argv[argc - 1]);
		if (num > 2147483647 || num < -2147483648)
			return (1);
		while (i > 1)
		{
			if (ft_atoi(argv[i - 1]) == num)
				return (1);
			i--;
		}
		argc--;
	}
	return (0);
}

/*Checks if the list pointed by "head" is already sorted.*/
int	stack_is_sorted(t_node *head)
{
	t_node	*current;

	current = head;
	while (current->next != NULL)
	{
		if (current->data > current->next->data)
			break ;
		current = current->next;
	}
	if (current->next == NULL)
		return (1);
	else
		return (0);
}
