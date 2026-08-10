/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yijeong <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/08 20:47:05 by yijeong           #+#    #+#             */
/*   Updated: 2026/08/09 15:20:37 by ginapark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	view_init(char *str, int view[4][4])
{
	int	i;
	int	j;
	int	k;

	i = 0;
	k = 0;
	while (i < 4)
	{
		j = 0;
		while (j < 4)
		{
			view[i][j] = str[k] - '0';
			k += 2;
			j++;
		}
		i++;
	}
}

void	land_init(int buildings[4][4])
{
	int	i;
	int	j;

	i = 0;
	while (i < 4)
	{
		j = 0;
		while (j < 4)
		{
			buildings[i][j] = 0;
			j++;
		}
		i++;
	}
}
