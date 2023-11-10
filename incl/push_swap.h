/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: raalonso <raalonso@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/16 21:38:59 by raalonso          #+#    #+#             */
/*   Updated: 2023/11/10 20:28:51 by raalonso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "../libft/libft.h"
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

typedef struct node
{
	int			data;
	struct node	*next;
}	node_t;

void	swap(node_t **head);
void	swap_both(node_t **head_a, node_t **head_b);
void	push(node_t **head_1, node_t **head_2);
void	rotate(node_t **head);
void	rotate_both(node_t **head_a, node_t **head_b);
void	rev_rotate(node_t **head);
void	rev_rotate_both(node_t **head_a, node_t **head_b);

#endif