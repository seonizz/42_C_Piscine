/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoohwang <yoohwang@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/06 22:06:19 by yoohwang          #+#    #+#             */
/*   Updated: 2026/08/12 02:07:11 by yoohwang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

unsigned int	ft_strlcat(char *dest, char *src, unsigned int size)
{
	unsigned int	i;
	unsigned int	j;
	unsigned int	k;

	i = 0;
	j = 0;
	k = 0;
	while (i < size && dest[i])
		i++;
	while (src[j])
		j++;
	while (i + k + 1 < size && src[k])
	{
		dest[k + i] = src[k];
		k++;
	}
	dest[k + i] = '\0';
	return (i + j);
}
