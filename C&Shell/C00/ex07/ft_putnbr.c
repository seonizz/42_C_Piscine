/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoohwang <yoohwang@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/30 23:27:49 by yoohwang          #+#    #+#             */
/*   Updated: 2026/08/01 20:55:25 by yoohwang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putnbr_long(long n)
{
	char	j;

	if (n < 0)
	{
		write (1, "-", 1);
		n = -n;
	}
	if (n < 10)
	{
		write (1, &j, 1);
		j = '0' + (n % 10);
		return ;
	}
	ft_putnbr_long(n / 10);
	j = '0' + (n % 10);
	write (1, &j, 1);
}

void	ft_putnbr(int nb)
{
	long	n;

	n = nb;
	ft_putnbr_long(n);
}
