/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_program_name.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoohwang <yoohwang@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/13 11:38:01 by yoohwang          #+#    #+#             */
/*   Updated: 2026/08/13 21:43:22 by yoohwang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	main(int argc, char **argv)
{
	int	len;

	len = 0;
	(void)argc;
	while (argv[0][len])
		len++;
	write(1, argv[0], len);
	write(1, "\n", 1);
	return (0);
}
