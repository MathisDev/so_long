/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamottet <mamottet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/17 14:06:25 by mamottet          #+#    #+#             */
/*   Updated: 2023/04/20 07:15:49 by mamottet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char	*str;
	size_t	count_str;

	str = ft_strdup(s);
	if (!str)
		return (NULL);
	count_str = 0;
	while (str[count_str])
	{
		str[count_str] = (*f)(count_str, str[count_str]);
		count_str++;
	}
	return (str);
}
