/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoohwang <yoohwang@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/10 12:17:39 by yoohwang          #+#    #+#             */
/*   Updated: 2026/08/10 21:27:01 by yoohwang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	ft_base_check(char *base)
{
	int	i;
	int	j;

	i = 0;
	while (base[i])
	{
		if (base[i] == '-' || base[i] == '+')
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
	int		len;
	int		idx;
	char	stack[50];

	idx = -1;
	len = ft_base_check(base);
	if (len)
		return ;
	if (nbr < 0)
	{
		write(1, "-", 1);
		nbr = -nbr;
	}
	while (nbr)
	{
		stack[++idx] = base[nbr % len];
		nbr /= len;
	}
	while (idx != -1)
	{
		write(1, &stack[idx], 1);
		idx--;
	}
}

/**
 * @brief 주어진 숫자를 주어진 진법으로 표현해서 출력하는 함수
 * 
 * 0. nbr이 음수인지 양수인지 쳌
 * 1. ft_check_base()함수를 통해 진법을 체크하고 맞는 진법이라면 return len(base)
 * 2. 주어진 숫자를 진법으로 바꾼 후 스택에 저장한다.
 * 3. 스택의 idx를 하나씩 줄여가면서 스택에 있는 요소를 wrtie()한다.
 * 
 * @param int nbr: 진법으로 바꿀 숫자
 * @param char *base: 주어진 진법
 * @return 표현된 진법을 출력
 */