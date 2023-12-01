/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: raalonso <raalonso@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/16 21:39:02 by raalonso          #+#    #+#             */
/*   Updated: 2023/12/01 18:58:57 by raalonso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/push_swap.h"

/*Allocates memory for a new node.*/
t_node	*new_node(int data, t_node **head)
{
	t_node	*new_node;

	new_node = (t_node *)malloc(sizeof(t_node));
	if (!new_node)
	{
		destroy_list(&*head);
		exit(1);
	}
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
		tmp = new_node(ft_atoi(argv[argc - 1]), &head);
		tmp->next = head;
		head = tmp;
		argc--;
	}
	return (head);
}

/*Frees all the nodes of the list*/
void	destroy_list(t_node **head_a)
{
	t_node	*aux;

	aux = (*head_a)->next;
	while (aux != NULL)
	{
		free(*head_a);
		*head_a = aux;
		aux = aux->next;
	}
	free(*head_a);
	exit(0);
}

int	main(int argc, char **argv)
{
	t_node	*head_a;
	t_node	*head_b;
	int		f;

	f = 0;
	do_checks(&argc, &argv, &f);
	head_a = create_list(argc, argv);
	free_argv(&argv, argc, f);
	head_b = NULL;
	if (argc == 1 || stack_is_sorted(head_a) == 1)
		destroy_list(&head_a);
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
	destroy_list(&head_a);
	return (0);
}
