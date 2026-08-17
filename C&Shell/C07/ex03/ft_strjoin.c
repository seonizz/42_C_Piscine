/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoohwang <yoohwang@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/17 18:01:18 by yoohwang          #+#    #+#             */
/*   Updated: 2026/08/17 22:30:29 by yoohwang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

static int	ft_strlen(char *s)
{
	int	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

static int	get_total(int size, char **strs, char *sep)
{
	int	total;
	int	i;

	total = 0;
	i = 0;
	while (i < size)
	{
		total += ft_strlen(strs[i]);
		i++;
	}
	total += ft_strlen(sep) * (size - 1);
	return (total);
}

static int	copy_at(char *dst, int k, char *src)
{
	int	j;

	j = 0;
	while (src[j])
	{
		dst[k] = src[j];
		k++;
		j++;
	}
	return (k);
}

char	*ft_strjoin(int size, char **strs, char *sep)
{
	char	*dst;
	int		i;
	int		k;

	if (size == 0)
	{
		dst = malloc(1);
		if (!dst)
			return (NULL);
		dst[0] = '\0';
		return (dst);
	}
	dst = malloc(get_total(size, strs, sep) + 1);
	if (!dst)
		return (NULL);
	k = 0;
	i = -1;
	while (++i < size)
	{
		k = copy_at(dst, k, strs[i]);
		if (i < size - 1)
			k = copy_at(dst, k, sep);
	}
	dst[k] = '\0';
	return (dst);
}

/**
 * @brief
 * strs 안의 문자열 size개를 이어붙이되, 사이사이에 sep을 끼워 넣은 새 문자열
 * -> malloc으로 만들어 반환.
 * 총 크기 = (모든 strs[i]의 길이 합) + (sep 길이) x (size - 1) + 1
 * 
 */