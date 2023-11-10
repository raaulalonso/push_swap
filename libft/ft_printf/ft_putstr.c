/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: raalonso <raalonso@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/23 19:19:24 by raalonso          #+#    #+#             */
/*   Updated: 2023/11/01 16:46:06 by raalonso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

int	ft_putstr(char *s, int fd)
{
	int	i;

	i = 0;
	if (s == NULL)
		return (ft_putstr("(null)", 1));
	else
	{
		while (s[i] != '\0')
		{
			write(fd, &s[i], 1);
			i++;
		}
		return (i);
	}
}
