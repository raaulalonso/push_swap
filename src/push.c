/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: raalonso <raalonso@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/18 17:34:34 by raalonso          #+#    #+#             */
/*   Updated: 2023/10/18 18:56:46 by raalonso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/push_swap.h"

void	ft_pb(t_prog *stack)
{
	int	i;
	int	first;

	first = stack->stack[0][0];
	i = 0;
	while (i < stack->num_a - 1)
	{
		stack->stack[0][i] = stack->stack[0][i + 1];
		i++;
	}
	stack->stack[0][i] = 0;
	stack->num_a -= 1;
	i = stack->num_b;
	while (i != 0)
	{
		stack->stack[1][i] = stack->stack[1][i - 1];
		i--;
	}
	printf("pb\n");
	stack->stack[1][0] = first;
	stack->num_b += 1;
}

void	ft_pa(t_prog *stack)
{
	int	i;
	int	first;

	first = stack->stack[1][0];
	i = 0;
	while (i < stack->num_b - 1)
	{
		stack->stack[1][i] = stack->stack[1][i + 1];
		i++;
	}
	stack->stack[1][i] = 0;
	stack->num_b -= 1;
	i = stack->num_a;
	while (i != 0)
	{
		stack->stack[0][i] = stack->stack[0][i - 1];
		i--;
	}
	printf("pa\n");
	stack->stack[0][0] = first;
	stack->num_a += 1;
}
