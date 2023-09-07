/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpovill- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/25 18:08:32 by mpovill-          #+#    #+#             */
/*   Updated: 2023/09/06 10:29:27 by mpovill-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	void	rec_write_number(unsigned int number, int fd)
{
	if (number / 10 < 1)
		ft_putchar_fd(number + '0', fd);
	else
	{
		rec_write_number(number / 10, fd);
		ft_putchar_fd((number % 10) + '0', fd);
	}
}

void	ft_putnbr_fd(int n, int fd)
{
	unsigned int	number;

	if (n < 0)
	{
		ft_putchar_fd('-', fd);
		number = n * -1;
	}
	else
		number = n;
	rec_write_number(number, fd);
}
