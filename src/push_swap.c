/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: raalonso <raalonso@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/16 21:39:02 by raalonso          #+#    #+#             */
/*   Updated: 2023/11/14 18:34:41 by raalonso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/push_swap.h"

/*Allocates memory for a new node.*/
t_node	*new_node(int data)
{
	t_node	*new_node;

	new_node = (t_node *)malloc(sizeof(t_node));
	if (!new_node)
		exit(1);
	new_node->data = data;
	new_node->next = NULL;
	return (new_node);
}

/*Creates a list made up with all of the arguments transformed into an int.*/
t_node	*create_list(int argc, char **argv)
{
	t_node	*head;
	t_node	*tmp;

	head = NULL;
	while (argc > 1)
	{
		tmp = new_node(ft_atoi(argv[argc - 1]));
		tmp->next = head;
		head = tmp;
		argc--;
	}
	return (head);
}

int	main(int argc, char **argv)
{
	t_node	*head_a;
	t_node	*head_b;

	if (argc <= 2 || check_arg(argc, argv) == 1)
	{
		ft_printf("Error\n");
		return (0);
	}
	head_a = create_list(argc, argv);
	head_b = NULL;
	if (stack_is_sorted(head_a) == 1)
		return (0);
	if ((argc - 1) <= 5)
		small_sort(&head_a, &head_b, argc - 1);
	else
	{
		push(&head_a, &head_b, 2);
		push(&head_a, &head_b, 2);
		if (head_b->data < head_b->next->data)
			swap(&head_b, 2);
		big_sort(&head_a, &head_b);
	}
	return (0);
}
