/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putmem.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: raalonso <raalonso@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/13 21:17:05 by raalonso          #+#    #+#             */
/*   Updated: 2023/11/01 16:45:50 by raalonso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

int	ft_putmem(void *mem)
{
	int	count;

	count = 0;
	write(1, "0x", 2);
	count = ft_puthexmem((uintptr_t)mem, 1);
	return (count + 2);
}
