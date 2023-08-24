/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamottet <mamottet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/13 09:11:01 by mamottet          #+#    #+#             */
/*   Updated: 2023/04/20 07:03:23 by mamottet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dest, const char *src, size_t count)
{
	size_t	src_count;
	size_t	dest_count;
	size_t	dest_length;
	size_t	src_length;

	src_length = ft_strlen(src);
	dest_length = ft_strlen(dest);
	dest_count = dest_length;
	src_count = 0;
	if (dest_length < count - 1 && count > 0)
	{
		while (src[src_count] && dest_length + src_count < count - 1)
		{
			dest[dest_count] = src[src_count];
			dest_count++;
			src_count++;
		}
		dest[dest_count] = 0;
	}
	if (dest_length >= count)
		dest_length = count;
	return (dest_length + src_length);
}
