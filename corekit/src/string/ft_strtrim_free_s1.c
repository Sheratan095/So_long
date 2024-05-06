/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maceccar <maceccar@student.42firenze.it>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/30 11:22:43 by maceccar          #+#    #+#             */
/*   Updated: 2024/05/03 00:47:17 by maceccar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_contains_char(const char *str, char c)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] == c)
			return (1);
		i++;
	}
	return (0);
}

char	*ft_strtrim_free_s1(char *s1, char const *set)
{
	char	*result;
	int		start_inx;
	int		end_idx;
	int		count;
	int		i;

	start_inx = 0;
	while (ft_contains_char(set, s1[start_inx]) && s1[start_inx])
		start_inx++;
	end_idx = ft_strlen(s1);
	while (ft_contains_char(set, s1[end_idx - 1]) == 1 && end_idx > start_inx)
		end_idx--;
	count = end_idx - start_inx + 1;
	result = malloc(sizeof(char) * (count));
	if (!result)
		return (NULL);
	i = 0;
	while (start_inx < end_idx)
		result[i++] = s1[start_inx++];
	result[i] = '\0';
	return (free(s1), result);
}
