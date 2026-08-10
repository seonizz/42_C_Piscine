/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rev_int_tab.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoohwang <yoohwang@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/01 23:24:13 by yoohwang          #+#    #+#             */
/*   Updated: 2026/08/02 20:51:19 by yoohwang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

static void	ft_swap(int *i, int *j)
{
	int	tmp;

	tmp = *i;
	*i = *j;
	*j = tmp;
}

void	ft_rev_int_tab(int *tab, int size)
{
	int	i;
	int	j;

	i = 0;
	j = size - 1;
	while (j > i)
	{
		ft_swap(&tab[i], &tab[j]);
		i++;
		j--;
	}
}
