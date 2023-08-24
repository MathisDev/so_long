/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamottet <mamottet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/17 13:46:58 by mamottet          #+#    #+#             */
/*   Updated: 2023/04/20 07:15:10 by mamottet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*str;
	size_t	count_s;
	size_t	count_str;

	str = (char *)malloc(sizeof(*s1) * (ft_strlen(s1) + ft_strlen(s2) + 1));
	if (!str)
		return (NULL);
	count_s = 0;
	count_str = 0;
	while (s1[count_s])
	{
		str[count_str++] = s1[count_s];
		count_s++;
	}
	count_s = 0;
	while (s2[count_s])
	{
		str[count_str++] = s2[count_s];
		count_s++;
	}
	str[count_str] = 0;
	return (str);
}
