/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: raalonso <raalonso@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/23 19:34:14 by raalonso          #+#    #+#             */
/*   Updated: 2023/11/01 16:46:02 by raalonso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

int	ft_putnbr(int n, int fd)
{
	char	num;
	int		count;

	count = 0;
	if (n == -2147483648)
		count += write(fd, "-2147483648", 11);
	if ((n < 0) && (n != -2147483648))
	{
		count += write(fd, "-", 1);
		n *= -1;
	}
	if ((n > 9) && (n != -2147483648))
	{
		count += ft_putnbr(n / 10, fd);
		count += ft_putnbr(n % 10, fd);
	}
	else if (n != -2147483648)
	{
		num = (n + 48);
		count += write (fd, &num, 1);
	}
	return (count);
}
