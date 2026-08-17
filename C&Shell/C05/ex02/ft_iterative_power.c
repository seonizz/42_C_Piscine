/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_iterative_power.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoohwang <yoohwang@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/12 19:46:27 by yoohwang          #+#    #+#             */
/*   Updated: 2026/08/13 00:12:46 by yoohwang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_iterative_power(int nb, int power)
{
	int	sum;

	if (power < 0)
		return (0);
	if (power == 0)
		return (1);
	sum = 1;
	while (power > 0)
	{
		sum *= nb;
		power--;
	}
	return (sum);
}
