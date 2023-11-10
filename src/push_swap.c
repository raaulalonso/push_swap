/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: raalonso <raalonso@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/16 21:39:02 by raalonso          #+#    #+#             */
/*   Updated: 2023/11/10 22:23:03 by raalonso         ###   ########.fr       */
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

void	printnode(node_t *head)
{
	node_t	*tmp;

	tmp = head;
	while (tmp)
	{
		ft_printf("%d", tmp->data);
		tmp = tmp->next;
	}
	ft_printf("\n");
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

	head_a = create_list(argc, argv);
	head_b = NULL;
	if (check_arg(argc, argv) == 1)
	{
		printf("\nlol es por letras\n");
		return (0);
	}
	else if (check_arg(argc, argv) == 2)
	{
		printf("\nlol es por repetir\n");
		return (0);
	}
	if (stack_is_sorted(head_a) == 1)
		return (0);
	return (0);
}
