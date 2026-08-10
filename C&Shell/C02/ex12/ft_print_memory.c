/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_memory.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoohwang <yoohwang@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/04 16:51:42 by yoohwang          #+#    #+#             */
/*   Updated: 2026/08/10 00:00:36 by yoohwang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

static void	ft_print_hex(unsigned long n, int len)
{
	char	*base;
	char	buf[16];
	int		i;

	base = "0123456789abcdef";
	i = len;
	while (i > 0)
	{
		buf[--i] = base[n % 16];
		n = n / 16;
	}
	write (1, buf, len);
}

static void	ft_print_num(unsigned char *p, unsigned int len)
{
	unsigned int	i;

	i = 0;
	while (i < 16)
	{
		if (i % 2 == 0)
			write (1, " ", 1);
		if (i < len)
			ft_print_hex(p[i], 2);
		else
			write (1, "  ", 2);
		i++;
	}
}

static void	ft_print_ascii(unsigned char *p, unsigned int len)
{
	unsigned int	i;

	i = 0;
	while (i < len)
	{
		if (!(p[i] >= 32 && p[i] <= 126))
			write (1, ".", 1);
		else
			write (1, &p[i], 1);
		i++;
	}
}

void	*ft_print_memory(void *addr, unsigned int size)
{
	unsigned int	i;
	unsigned char	*p;
	unsigned int	len;

	i = 0;
	p = (unsigned char *)addr;
	if (size == 0)
		return (addr);
	while (i < size)
	{
		len = 0;
		if (size - i >= 16)
			len = 16;
		else
			len = size - i;
		ft_print_hex((unsigned long)(p + i), 16);
		write (1, ":", 1);
		ft_print_num(p + i, len);
		write (1, " ", 1);
		ft_print_ascii(p + i, len);
		write (1, "\n", 1);
		i += 16;
	}
	return (addr);
}

/**
 * @brief 주소, 16진수, 아스키
 * 1. 
 * 
 * @param 
 * addr = 
 */