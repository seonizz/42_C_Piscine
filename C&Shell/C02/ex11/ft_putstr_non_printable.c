/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_non_printable.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoohwang <yoohwang@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/03 20:39:12 by yoohwang          #+#    #+#             */
/*   Updated: 2026/08/05 01:47:53 by yoohwang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

static void	ft_print_hex(unsigned char c)
{
	char	*arr;

	arr = "0123456789abcdef";
	write (1, "\\", 1);
	write (1, &arr[c / 16], 1);
	write (1, &arr[c % 16], 1);
}

void	ft_putstr_non_printable(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] >= 32 && str[i] <= 126)
			write (1, &str[i], 1);
		else
		{
			ft_print_hex(str[i]);
		}
		i++;
	}
}
