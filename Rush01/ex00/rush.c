/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoohwang <yoohwang@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/08 16:10:16 by yijeong           #+#    #+#             */
/*   Updated: 2026/08/12 02:07:11 by yoohwang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>

void	view_init(char *str, int view[4][4]);
void	land_init(int buildings[4][4]);
int		check_duplicated_val(int buildings[4][4], int row, int col, int num);
int		row_count_visible(int buildings[4][4], int row, int start);
int		col_count_visible(int buildings[4][4], int col, int start);
int		check_view_matching(int buildings[4][4], int view_counts[4][4]);

void	print(int buildings[4][4])
{
	int		i;
	int		j;
	char	c;

	i = 0;
	while (i < 4)
	{
		j = 0;
		while (j < 4)
		{
			c = buildings[i][j] + '0';
			write(1, &c, 1);
			if (j != 3)
				write(1, " ", 1);
			j++;
		}
		write(1, "\n", 1);
		i++;
	}
}


int	solve_btrk(int buildings[4][4], int view_counts[4][4], int row, int col)
{
	int	num;

	if (row == 4)
		return (check_view_matching(buildings, view_counts));
	if (col == 4)
		return (solve_btrk(buildings, view_counts, row + 1, 0));
	num = 1;
	while (num <= 4)
	{
		if (check_duplicated_val(buildings, row, col, num) == 1)
		{
			buildings[row][col] = num;
			if (solve_btrk(buildings, view_counts, row, col + 1) == 1)
				return (1);
			buildings[row][col] = 0;
		}
		num++;
	}
	return (0);
}

void	rush(char *str)
{
	int	view_counts[4][4];
	int	buildings[4][4];

	view_init(str, view_counts);
	land_init(buildings);
	if (solve_btrk(buildings, view_counts, 0, 0) == 1)
		print(buildings);
	else
		write(1, "Error", 6);
}
