/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_iterative_factorial.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoohwang <yoohwang@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/12 18:13:06 by yoohwang          #+#    #+#             */
/*   Updated: 2026/08/13 22:16:59 by yoohwang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_iterative_factorial(int nb)
{
	int	sum;

	if (nb < 0)
		return (0);
	sum = 1;
	while (nb > 0)
	{
		sum *= nb;
		nb--;
	}
	return (sum);
}
