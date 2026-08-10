/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yijeong <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/08 16:00:57 by yijeong           #+#    #+#             */
/*   Updated: 2026/08/09 15:14:41 by ginapark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	rush(char *str);

int	check_error(char *str)
{
	int	i;

	i = 0;
	while (i < 31)
	{
		if (i % 2 == 0)
		{
			if (str[i] < '1' || str[i] > '4')
				return (0);
		}
		else
		{
			if (str[i] != ' ')
				return (0);
		}
		i++;
	}
	if (str[i] != '\0')
		return (0);
	return (1);
}

int	main(int argc, char **argv)
{
	if (argc != 2 || !check_error(argv[1]))
		write(1, "Error", 5);
	else
		rush(argv[1]);
	return (0);
}
