/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoohwang <yoohwang@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/14 00:27:28 by yoohwang          #+#    #+#             */
/*   Updated: 2026/08/18 02:29:05 by yoohwang         ###   ########.fr       */
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
		heap[i] = src[i];
		i++;
	}
	heap[i] = '\0';
	return (heap);
}
