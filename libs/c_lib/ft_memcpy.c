/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamottet <mamottet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/13 09:10:14 by mamottet          #+#    #+#             */
/*   Updated: 2023/04/20 08:07:01 by mamottet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	size_t	count;
	char	*s1;

	if (dst == NULL && src == NULL)
		return (NULL);
	s1 = (char *)dst;
	count = 0;
	while (count < n)
	{
		*(char *)s1 = *(char *)src;
		s1++;
		src++;
		count++;
	}
	return (dst);
}
