/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maceccar <maceccar@student.42firenze.it>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/30 11:22:43 by maceccar          #+#    #+#             */
/*   Updated: 2024/05/03 00:47:17 by maceccar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

unsigned int	ft_strlcat(char *dest, const char *src, unsigned int size)
{
	unsigned int	i;
	unsigned int	l;
	unsigned int	l2;

	i = 0;
	l = 0;
	l2 = 0;
	while (dest[l])
		l++;
	while (src[l2])
		l2++;
	if (size == 0)
	{
		return (l2);
	}
	while (src[i] && i + l < size - 1)
	{
		dest[i + l] = src[i];
		i++;
	}
	if (i < size)
		dest[i + l] = '\0';
	if (l > size)
		return (l2 + size);
	return (l + l2);
}
