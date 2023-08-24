/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamottet <mamottet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/13 09:11:39 by mamottet          #+#    #+#             */
/*   Updated: 2023/04/20 07:03:34 by mamottet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	count;
	size_t	count_char;
	size_t	l_len;
	char	*str;

	count = 0;
	str = (char *)big;
	l_len = ft_strlen(little);
	if (l_len == 0 || big == little)
		return (str);
	while (str[count] != '\0' && count < len)
	{
		count_char = 0;
		while (str[count + count_char] != '\0' && little[count_char] != '\0'
			&& str[count + count_char] == little[count_char] && count
			+ count_char < len)
			count_char++;
		if (count_char == l_len)
			return (str + count);
		count++;
	}
	return (0);
}
