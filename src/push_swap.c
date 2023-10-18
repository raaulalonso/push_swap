/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: raalonso <raalonso@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/16 21:39:02 by raalonso          #+#    #+#             */
/*   Updated: 2023/10/18 20:21:58 by raalonso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/push_swap.h"

static int	ft_number(const char *str, int i)
{
	int	j;
	int	num;

	j = 0;
	num = 0;
	while ((str[i + j] != '\0') && ((str[i + j] <= '9') && (str[i + j] >= '0')))
	{
		num = ((num * 10) + (str[i + j] - 48));
		j++;
	}
	return (num);
}

int	ft_atoi(const char *str)
{
	int	i;
	int	num;
	int	sign;

	i = 0;
	num = 0;
	sign = 0;
	while (((str[i] > 8) && (str[i] < 14)) || (str[i] == 32))
		i++;
	if (str[i] == '-')
	{
		i++;
		sign++;
	}
	else if (str[i] == '+')
		i++;
	num = ft_number(str, i);
	if (sign == 1)
		return (num * -1);
	return (num);
}

////////// ---------------------------------------------------------- ///////////

int	**get_stack(int argc, char **argv)
{
	int	**stack;
	int	i;

	stack = (int **)malloc(sizeof(int *) * 2);
	stack[0] = (int *)malloc(sizeof(int) * (argc - 1));
	stack[1] = (int *)malloc(sizeof(int) * (argc - 1));
	i = 0;
	while (argc > 1)
	{
		stack[0][i] = ft_atoi(argv[i + 1]);
		i++;
		argc--;
	}
	return (stack);
}

int	**three_arg(t_prog stack, int type)
{
	if (stack.stack[type][0] > stack.stack[type][1]
			&& stack.stack[type][0] < stack.stack[type][2])
		stack.stack = ft_sa(stack);
	else if (stack.stack[type][0] > stack.stack[type][2]
			&& stack.stack[type][1] < stack.stack[type][2])
		stack.stack = ft_ra(stack);
	else if (stack.stack[type][0] > stack.stack[type][1]
			&& stack.stack[type][1] > stack.stack[type][2])
	{
		stack.stack = ft_sa(stack);
		stack.stack = ft_rra(stack);
	}
	else if (stack.stack[type][0] < stack.stack[type][2]
			&& stack.stack[type][1] > stack.stack[type][2])
	{
		stack.stack = ft_sa(stack);
		stack.stack = ft_ra(stack);
	}
	else if (stack.stack[type][2] < stack.stack[type][1]
			&& stack.stack[type][1] > stack.stack[type][0])
		stack.stack = ft_rra(stack);
	return (stack.stack);
}

int	main(int argc, char **argv)
{
	t_prog	stack;
	int i = 0;

	stack.num_a = argc - 1;
	stack.num_b = 0;
	stack.stack = get_stack(argc, argv);
	
	if ((argc - 1) == 3)
		stack.stack = three_arg(stack, 0);
	while (i < stack.num_a)
	{
		printf("%d ", stack.stack[0][i]);
		i++;
	}
	free(stack.stack[0]);
	free(stack.stack[1]);
	free(stack.stack);
	return (0);
}
