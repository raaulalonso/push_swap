/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: raalonso <raalonso@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/16 21:39:02 by raalonso          #+#    #+#             */
/*   Updated: 2023/11/12 15:01:59 by raalonso         ###   ########.fr       */
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

/* 1 for rotate, 2 for reverse. */
void	rotate_reverse(int type, int f, node_t **head_b)
{
	if (type == 1)
	{
		if (f == 1)
			rev_rotate(&*head_b, 2);
		else
			rotate(&*head_b, 2);
	}
	else if (type == 2)
	{
		if (f == 1)
			rotate(&*head_b, 2);
		else
			rev_rotate(&*head_b, 2);
	}
}

void	insert_into_b(int movements, int f, node_t **head_a, node_t **head_b)
{
	int	i;

	if (f == 1)
	{
		i = ft_lstsize(*head_b) - movements;
		movements = i + 1;
	}
	else
		i = movements;
	while (i != 0)
	{
		rotate_reverse(1, f, &*head_b);
		i--;
	}
	push(&*head_a, &*head_b, 2);
	while (i < movements)
	{
		rotate_reverse(2, f, &*head_b);
		i++;
	}
}

node_t	*get_cheaper(node_t **head_a, node_t **head_b, int max_b, int min_b)
{
	node_t	*current_a;
	node_t	*current_b;
	node_t	*cheaper;
	int		movements;
	int		price;
	int		i;
	
	i = 0;
	price = 0;
	movements = 0;
	current_a = *head_a;
	current_b = *head_b;
	while (current_a != NULL)
	{
		if (current_a->data > max_b || current_a->data < min_b)
		{
			while (current_b != NULL && current_a->data != max_b)
			{
				current_b = current_b->next;
				movements++;
			}
		}
		else
		{
			while (current_b != NULL && current_a->data < current_b->data)
			{
				current_b = current_b->next;
				movements++;
			}
		}
		if (movements > ft_lstsize(*head_b) / 2)
			movements = ft_lstsize(*head_b) - movements;
		//printf("movements -> %d %d\n", movements, i);
		if (movements + i < price || price == 0)
		{
			price = movements + i + 1;
			cheaper = current_a;
		}
		movements = 0;
		i++;
		current_b = *head_b;
		current_a = current_a->next;
	}
	//printf ("cheaper -> %d\n", cheaper->data);
	return (cheaper);
}

void	move_cheaper(node_t **head_a, node_t *cheaper)
{
	int		movements;
	node_t	*current_a;
	int		f;

	f = 0;
	movements = 0;
	current_a = *head_a;
	while (current_a != cheaper)
	{
		current_a = current_a->next;
		movements++;
	}
	if (movements > ft_lstsize(*head_a) / 2)
	{
		movements = ft_lstsize(*head_a) - movements;
		f = 1;
	}
	while (movements != 0)
	{
		if (f == 1)
			rev_rotate(&*head_a, 1);
		else
			rotate(&*head_a, 1);
		movements--;
	}
}

void	put_above_max(node_t **head_a, node_t **head_b, int max_b)
{
	int		movements;
	node_t	*current_b;
	int		f;

	f = 0;
	movements = 0;
	current_b = *head_b;
	while (current_b->data != max_b)
	{
		current_b = current_b->next;
		movements++;
	}
	if (movements > ft_lstsize(*head_b) / 2)
	{
		movements = ft_lstsize(*head_b) - movements;
		f = 1;
	}
	while (movements != 0)
	{
		if (f == 1)
			rev_rotate(&*head_b, 2);
		else
			rotate(&*head_b, 2);
		movements--;
	}
	push(&*head_a, &*head_b, 2);
}

void	big_sort(node_t **head_a, node_t **head_b)
{	
	node_t	*current_a;
	node_t	*current_b;
	node_t	*cheaper;
	int		movements;
	int		count;
	int		lst_size;
	int		f;
	int		max_b;
	int		min_b;

	max_b = (*head_b)->data;
	min_b = (*head_b)->next->data;
	count = 0;
	lst_size = ft_lstsize(*head_a);
	while (count < lst_size)
	{
		movements = 0;
		current_b = *head_b;
		current_a = *head_a;
		//cheaper = get_cheaper(&*head_a, &*head_b, max_b, min_b);
		//move_cheaper(&*head_a, cheaper);
		f = 0;
		current_a = *head_a;
		/*if (current_a->data > max_b)
		{
			put_above_max(&*head_a, &*head_b, max_b);
			max_b = current_a->data;
		}
		else if (current_a->data < min_b)
		{
			put_above_max(&*head_a, &*head_b, max_b);
			min_b = current_a->data;
		}*/
		//else
		//{
			while (current_b != NULL && current_a->data < current_b->data)
			{
				current_b = current_b->next;
				movements++;
			}
			if (movements > ft_lstsize(*head_b) / 2)
				f = 1;
			insert_into_b(movements, f, &*head_a, &*head_b);
		//}
		count++;
	}
	count = 0;
	lst_size = ft_lstsize(*head_b);
	while (count < lst_size)
	{
		push(&*head_b, &*head_a, 1);
		count++;
	}
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
