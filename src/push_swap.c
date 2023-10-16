/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: raalonso <raalonso@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/16 21:39:02 by raalonso          #+#    #+#             */
/*   Updated: 2023/10/16 22:41:11 by raalonso         ###   ########.fr       */
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

int	**ft_sa(int **stack)
{
	int	aux;
	
	if (stack[0][0] != '\0' && stack[0][1] != '\0')
	{
		aux = stack[0][0];
		stack[0][0] = stack[0][1];
		stack[0][1] = aux;
	}
	return (stack);
}

int	**ft_sb(int **stack)
{
	int	aux;
	
	if (stack[1][0] != '\0' && stack[1][1] != '\0')
	{
		aux = stack[1][0];
		stack[1][0] = stack[1][1];
		stack[1][1] = aux;
	}
	return (stack);
}

int **ft_ss(int **stack)
{
	stack = ft_sa(stack);
	stack = ft_sb(stack);
	return (stack);
}

int	main(int argc, char **argv)
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

	stack = ft_ss(stack);


}