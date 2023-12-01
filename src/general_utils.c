/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   general_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: raalonso <raalonso@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/01 18:57:20 by raalonso          #+#    #+#             */
/*   Updated: 2023/12/01 19:00:28 by raalonso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/push_swap.h"

int	countwords(char *str, char c)
{
	int	i;
	int	f;
	int	wnum;

	i = 0;
	f = 0;
	wnum = 0;
	while (str[i])
	{
		if (str[i] != c)
		{
			if (f == 0)
				wnum++;
			f = 1;
		}
		else
			f = 0;
		i++;
	}
	return (wnum);
}

char	**divide_arg(char **argv, int *argc)
{
	char	*str;
	char	**new_argv;

	str = ft_strjoin("./push_swap ", argv[1]);
	if (!str)
		exit(1);
	*argc = countwords(str, ' ');
	new_argv = ft_split(str, ' ');
	if (!new_argv)
	{
		free(str);
		exit(1);
	}
	free(str);
	return (new_argv);
}

void	do_checks(int *argc, char ***argv, int *f)
{
	if (*argc == 2)
	{
		*argv = divide_arg(*argv, &*argc);
		*f = 1;
	}
	if (check_arg(*argc, *argv) == 1)
	{
		ft_printf("Error\n");
		exit(1);
	}
	if (*argc == 2)
		exit(0);
}

void	free_argv(char ***argv, int argc, int f)
{
	int	i;

	if (f == 1)
	{
		i = 0;
		while (i < argc)
		{
			free((*argv)[i]);
			i++;
		}
		free(*argv);
	}
}
