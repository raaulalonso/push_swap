/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: raalonso <raalonso@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/16 21:38:59 by raalonso          #+#    #+#             */
/*   Updated: 2023/11/11 20:27:43 by raalonso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "../libft/libft.h"
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

void	swap(node_t **head, int print);
void	swap_both(node_t **head_a, node_t **head_b);
void	push(node_t **head_1, node_t **head_2, int print);
void	rotate(node_t **head, int print);
void	rotate_both(node_t **head_a, node_t **head_b);
void	rev_rotate(node_t **head, int print);
void	rev_rotate_both(node_t **head_a, node_t **head_b);
int		check_arg(int argc, char **argv);
int		stack_is_sorted(node_t *head);
void	small_sort(node_t **head_a, int num);
void	three_sort(node_t **head_a);

#endif