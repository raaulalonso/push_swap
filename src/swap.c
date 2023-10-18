/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: raalonso <raalonso@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/18 17:34:23 by raalonso          #+#    #+#             */
/*   Updated: 2023/10/18 18:54:22 by raalonso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/push_swap.h"

int	**ft_sa(t_prog stack)
{
	int	aux;

	if (stack.stack[0][0] != '\0' && stack.stack[0][1] != '\0')
	{
		aux = stack.stack[0][0];
		stack.stack[0][0] = stack.stack[0][1];
		stack.stack[0][1] = aux;
		printf("sa\n");
	}
	return (stack.stack);
}

int	**ft_sb(t_prog stack)
{
	int	aux;

	if (stack.stack[1][0] != '\0' && stack.stack[1][1] != '\0')
	{
		aux = stack.stack[1][0];
		stack.stack[1][0] = stack.stack[1][1];
		stack.stack[1][1] = aux;
		printf("sb\n");
	}
	return (stack.stack);
}

int	**ft_ss(t_prog stack)
{
	stack.stack = ft_sa(stack);
	stack.stack = ft_sb(stack);
	printf("ss\n");
	return (stack.stack);
}
