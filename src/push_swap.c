/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: raalonso <raalonso@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/16 21:39:02 by raalonso          #+#    #+#             */
/*   Updated: 2023/11/12 18:01:41 by raalonso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/push_swap.h"

/*Allocates memory for a new node.*/
node_t	*new_node(int data)
{
	node_t	*new_node;

	new_node = (node_t *)malloc(sizeof(node_t));
	if (!new_node)
		exit(1);
	new_node->data = data;
	new_node->next = NULL;
	return (new_node);
}

/*Creates a list made up with all of the arguments transformed into an int.*/
node_t	*create_list(int argc, char **argv)
{
	node_t	*head;
	node_t	*tmp;

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
	node_t	*head_a;
	node_t	*head_b;

	/*Check there are minimun 2 arguments. Also check for invalid arguments.*/
	if (argc <= 2 || check_arg(argc, argv) == 1)
		return (0);
	
	/*Create the list (stack a) with all of the arguments. Also incicialize 
	stack_b.*/
	head_a = create_list(argc, argv);
	head_b = NULL;

	/*Check if stack a is already sorted by default.*/
	if (stack_is_sorted(head_a) == 1)
		return (0);

	/*Decide which algorithm is going to be used. Small sort for 5 or less
	arguments. Big sort for more arguments.*/
	if ((argc - 1) <= 3)
		small_sort(&head_a, argc - 1);
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
