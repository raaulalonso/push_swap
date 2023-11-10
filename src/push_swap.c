/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: raalonso <raalonso@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/16 21:39:02 by raalonso          #+#    #+#             */
/*   Updated: 2023/11/10 20:29:43 by raalonso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/push_swap.h"

node_t	*new_node(int data)
{
	node_t	*new_node;

	new_node = (node_t *)malloc(sizeof(node_t));
	new_node->data = data;
	new_node->next = NULL;
	return (new_node);
}

void	printnode(node_t *head)
{
	node_t	*tmp;

	tmp = head;
	while (tmp)
	{
		printf("%d", tmp->data);
		tmp = tmp->next;
	}
	printf("\n");
}

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

	head_a = create_list(argc, argv);
	head_b = create_list(argc, argv);
	printnode(head_a);
	printnode(head_b);
	swap_both(&head_a, &head_b);
	printnode(head_a);
	printnode(head_b);
	rev_rotate_both(&head_a, &head_b);
	printnode(head_a);
	printnode(head_b);
	return (0);
}
