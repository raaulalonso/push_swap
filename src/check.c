/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: raalonso <raalonso@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/10 22:21:48 by raalonso          #+#    #+#             */
/*   Updated: 2023/11/14 09:42:34 by raalonso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/push_swap.h"

/*Checks that the arguments are only numbers, and they do not repeat.*/
int	check_arg(int argc, char **argv)
{
	int		i;
	long	num;

	i = 0;
	while (argc > 1)
	{
		while (argv[argc - 1][i] != '\0')
		{
			if ((argv[argc - 1][i] < '0' || argv[argc - 1][i] > '9')
				&& argv[argc - 1][i] != '-')
				return (1);
			i++;
		}
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
		i = 0;
		argc--;
	}
	return (0);
}

/*Checks if the list pointed by "head" is already sorted.*/
int	stack_is_sorted(node_t *head)
{
	node_t	*current;

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
