/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   deep_btrk.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ginapark <ginapark@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/09 17:26:10 by ginapark          #+#    #+#             */
/*   Updated: 2026/08/09 17:26:15 by ginapark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	check_duplicated_val(int buildings[4][4], int row, int col, int num)
{
	int	i;

	i = 0;
	while (i < 4)
	{
		if (buildings[row][i] == num)
			return (0);
		if (buildings[i][col] == num)
			return (0);
		i++;
	}
	return (1);
}

int	row_count_visible(int buildings[4][4], int row, int start)
{
	int	i;
	int	max;
	int	view_counts;

	max = buildings[row][start];
	view_counts = 1;
	if (start == 0)
		i = 1;
	else
		i = -1;
	while (start + i >= 0 && start + i < 4)
	{
		if (buildings[row][start + i] > max)
		{
			max = buildings[row][start + i];
			view_counts++;
		}
		if (start == 0)
			i++;
		else
			i--;
	}
	return (view_counts);
}

int	col_count_visible(int buildings[4][4], int col, int start)
{
	int	i;
	int	max;
	int	view_counts;

	max = buildings[start][col];
	view_counts = 1;
	if (start == 0)
		i = 1;
	else
		i = -1;
	while (start + i >= 0 && start + i < 4)
	{
		if (buildings[start + i][col] > max)
		{
			max = buildings[start + i][col];
			view_counts++;
		}
		if (start == 0)
			i++;
		else
			i--;
	}
	return (view_counts);
}

int	check_view_matching(int buildings[4][4], int view_counts[4][4])
{
	int	i;

	i = 0;
	while (i < 4)
	{
		if (col_count_visible(buildings, i, 0) != view_counts[0][i])
			return (0);
		if (col_count_visible(buildings, i, 3) != view_counts[1][i])
			return (0);
		if (row_count_visible(buildings, i, 0) != view_counts[2][i])
			return (0);
		if (row_count_visible(buildings, i, 3) != view_counts[3][i])
			return (0);
		i++;
	}
	return (1);
}
