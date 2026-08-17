/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_base.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoohwang <yoohwang@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/18 00:00:29 by yoohwang          #+#    #+#             */
/*   Updated: 2026/08/18 01:05:52 by yoohwang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int		ft_base_check(char *base);
int		ft_atoi_base(char *str, char *base);

static int	ft_nbr_len(long long n, int base_len)
{
	int	len;

	len = 0;
	if (n <= 0)
	{
		len++;
		n = -n;
	}
	while (n > 0)
	{
		n /= base_len;
		len++;
	}
	return (len);
}

static char	*ft_it_base(int nbr, char *base, int base_len)
{
	long long	n;
	int			len;
	char		*res;

	n = nbr;
	len = ft_nbr_len(n, base_len);
	res = (char *)malloc(sizeof(char) * (len + 1));
	if (!res)
		return (NULL);
	res[len] = '\0';
	if (n < 0)
	{
		res[0] = '-';
		n = -n;
	}
	else if (n == 0)
		res[0] = base[0];
	while (n > 0)
	{
		res[--len] = base[n % base_len];
		n /= base_len;
	}
	return (res);
}

char	*ft_convert_base(char *nbr, char *base_from, char *base_to)
{
	int	from_len;
	int	to_len;
	int	num;

	if (!nbr || !base_from || !base_to)
		return (NULL);
	from_len = ft_base_check(base_from);
	to_len = ft_base_check(base_to);
	if (from_len == 0 || to_len == 0)
		return (NULL);
	num = ft_atoi_base(nbr, base_from);
	return (ft_it_base(num, base_to, to_len));
}
