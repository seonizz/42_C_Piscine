/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_params.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoohwang <yoohwang@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/13 15:35:55 by yoohwang          #+#    #+#             */
/*   Updated: 2026/08/13 22:16:59 by yoohwang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	ft_strcmp(char *s1, char *s2)
{
	int				i;
	unsigned char	*ss1;
	unsigned char	*ss2;

	ss1 = (unsigned char *)s1;
	ss2 = (unsigned char *)s2;
	i = 0;
	while (ss1[i] && ss1[i] == ss2[i])
		i++;
	return (ss1[i] - ss2[i]);
}

void	ft_check(char **argv)
{
	int		i;
	char	*tmp;
	int		swapped;

	i = 1;
	swapped = 0;
	while (argv[i] && argv[i + 1])
	{
		if (ft_strcmp(argv[i], argv[i + 1]) > 0)
		{
			tmp = argv[i];
			argv[i] = argv[i + 1];
			argv[i + 1] = tmp;
			swapped = 1;
		}
		i++;
	}
	if (swapped)
		ft_check(argv);
}

int	main(int argc, char **argv)
{
	int	i;
	int	j;

	ft_check(argv);
	(void)argc;
	i = 1;
	while (argv[i])
	{
		j = 0;
		while (argv[i][j])
			j++;
		write(1, argv[i], j);
		write(1, "\n", 1);
		i++;
	}
	return (0);
}
