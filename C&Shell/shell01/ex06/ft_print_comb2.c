/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_comb2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoohwang <yoohwang@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/30 17:46:23 by yoohwang          #+#    #+#             */
/*   Updated: 2026/07/31 21:55:48 by yoohwang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	print_num(int n)
{
	char	tens;
	char	units;

	tens = '0' + (n / 10);
	units = '0' + (n % 10);
	write (1, &tens, 1);
	write (1, &units, 1);
}

void	ft_print_comb2(void)
{
	int	i;
	int	j;

	j = 0;
	while (j <= 98)
	{
		i = j + 1;
		while (i <= 99)
		{
			print_num(j);
			write(1, " ", 1);
			print_num(i);
			if (!(j == 98 && i == 99))
				write(1, ", ", 2);
			i++;
		}
		j++;
	}
}
