/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamottet <mamottet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/17 17:58:01 by mamottet          #+#    #+#             */
/*   Updated: 2023/04/20 07:03:41 by mamottet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	if_set(char c, char const *set)
{
	size_t	count;

	count = 0;
	while (set[count])
	{
		if (set[count] == c)
			return (1);
		count++;
	}
	return (0);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*str;
	size_t	count;
	size_t	start;
	size_t	end;

	start = 0;
	while (s1[start] && if_set(s1[start], set))
		start++;
	end = ft_strlen(s1);
	while (end > start && if_set(s1[end - 1], set))
		end--;
	str = (char *)malloc(sizeof(*s1) * (end - start + 1));
	if (!str)
		return (NULL);
	count = 0;
	while (start < end)
		str[count++] = s1[start++];
	str[count] = 0;
	return (str);
}
