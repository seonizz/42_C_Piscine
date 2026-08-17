/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoohwang <yoohwang@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/14 00:27:28 by yoohwang          #+#    #+#             */
/*   Updated: 2026/08/14 02:00:26 by yoohwang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

char	*ft_strdup(char *src)
{
	char	*heap;
	int		i;
	int		len;

	len = 0;
	i = 0;
	while (src[len])
		len++;
	heap = malloc(len + 1);
	if (!heap)
		return (NULL);
	while (src[i])
	{
		src[i] = heap[i];
		i++;
	}
	heap[i] == '\0';
	return (heap);
}

/**
 * 1. 길이 재기
 * 2. 새 공간에 필요한 공간 만큼 할당하기 + \0까지. dst가 아니면 null
 * 3. src에 있는 값들을 dst에 옮기기
 * 4. \0 붙이기
 * 5. 반환하기
 */
