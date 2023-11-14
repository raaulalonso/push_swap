/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: raalonso <raalonso@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/16 21:38:59 by raalonso          #+#    #+#             */
/*   Updated: 2023/11/14 10:28:12 by raalonso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "../libft/libft.h"
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

void	swap(t_node **head, int print);
void	swap_both(t_node **head_a, t_node **head_b);
void	push(t_node **head_1, t_node **head_2, int print);
void	rotate(t_node **head, int print);
void	rotate_both(t_node **head_a, t_node **head_b);
void	rev_rotate(t_node **head, int print);
void	rev_rotate_both(t_node **head_a, t_node **head_b);
int		check_arg(int argc, char **argv);
int		stack_is_sorted(t_node *head);
void	small_sort(t_node **head_a, int num);
void	three_sort(t_node **head_a);
void	big_sort(t_node **head_a, t_node **head_b);
void	insert_into_b(int movements, int f, t_node **head_a, t_node **head_b);
void	move_cheaper(t_node **head_a, t_node *cheaper);
t_node	*get_cheaper(t_node **head_a, t_node **head_b, int max_b, int min_b);
int		get_movements(t_node **head_a, t_node **head_b, int max_b);
void	put_above_max(t_node **head_a, t_node **head_b, int max_b);
void	check_max_min(t_node **head_a, t_node **head_b, int *max_b, int *min_b);
int		moves_to_max(t_node *current_b, t_node **head_b, int max_b, int *f);

#endif