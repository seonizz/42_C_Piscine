/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoohwang <yoohwang@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/11 22:19:09 by yoohwang          #+#    #+#             */
/*   Updated: 2026/08/11 22:19:19 by yoohwang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	ft_base_check(char *base)
{
	int	i;
	int	j;

	i = 0;
	if (base[0] == '\0' || base[1] == '\0')
		return (0);
	while (base[i])
	{
		if (base[i] == '+' || base[i] == '-')
			return (0);
		j = i + 1;
		while (base[j])
		{
			if (base[i] == base[j])
				return (0);
			j++;
		}
		i++;
	}
	return (i);
}

void	ft_putnbr_base(int nbr, char *base)
{
	int		idx;
	int		len;
	long	n;
	char	stack[50];

	len = 0;
	idx = -1;
	len = ft_base_check(base);
	if (len == 0)
		return ;
	n = nbr;
	if (n == 0)
	{
		write(1, &base[0], 1);
		return ;
	}
	if (n < 0)
	{
		write(1, "-", 1);
		n = -n;
	}
	while (n)
	{
		stack[++idx] = base[n % len];
		n = n / len;
	}
	while (idx != -1)
	{
		write(1, &stack[idx], 1);
		idx--;
	}
}

/**
 * @brief 정수 nbr을 base 에 채워진 문자열대로 처리
 * while (nbr) 동안 -라면 음수 처리, 
 */