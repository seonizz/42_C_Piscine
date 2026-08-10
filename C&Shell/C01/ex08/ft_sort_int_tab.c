/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_int_tab.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoohwang <yoohwang@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/02 00:33:48 by yoohwang          #+#    #+#             */
/*   Updated: 2026/08/02 20:54:54 by yoohwang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

static void	ft_swap(int *i, int *j)
{
	int	tmp;

	tmp = *i;
	*i = *j;
	*j = tmp;
}

void	ft_sort_int_tab(int *tab, int size)
{
	int	i;
	int	j;

	j = size;
	while (j != 0)
	{
		i = 0;
		while (i < size - 1)
		{
			if (tab[i + 1] < tab[i])
				ft_swap(&tab[i], &tab[i + 1]);
			i++;
		}
		j--;
	}
}
