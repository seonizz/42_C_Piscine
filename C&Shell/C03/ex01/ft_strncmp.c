/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoohwang <yoohwang@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/06 16:04:07 by yoohwang          #+#    #+#             */
/*   Updated: 2026/08/09 23:08:46 by yoohwang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_strncmp(char *s1, char *s2, unsigned int n)
{
	unsigned int	i;
	unsigned char	*ss1;
	unsigned char	*ss2;

	i = 0;
	ss1 = (unsigned char *)s1;
	ss2 = (unsigned char *)s2;
	while (i < n)
	{
		if (ss1[i] != ss2[i])
			return (ss1[i] - ss2[i]);
		if (ss1[i] == '\0')
			return (0);
		i++;
	}
	while (i > n)
	{
		if (ss1[i] != ss2[i])
			return (ss1[i] - ss2[i]);
		if (ss1[i] == '\0')
			return (0);
		i++;
	}
	return (0);
}
