/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: raalonso <raalonso@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/16 21:38:59 by raalonso          #+#    #+#             */
/*   Updated: 2023/10/18 18:01:28 by raalonso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "../libft/libft.h"
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

typedef struct s_program
{
	int	num_a;
	int	num_b;
	int **stack;
}	t_prog;

int		**ft_sa(t_prog stack);
int		**ft_sb(t_prog stack);
int		**ft_ss(t_prog stack);
int		**ft_ra(t_prog stack);
int		**ft_rb(t_prog stack);
int		**ft_rr(t_prog stack);
int		**ft_rra(t_prog stack);
int		**ft_rrb(t_prog stack);
int		**ft_rrr(t_prog stack);
void	ft_pb(t_prog *stack);
void	ft_pa(t_prog *stack);

#endif