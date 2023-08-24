/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamottet <mamottet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/17 20:13:14 by mamottet          #+#    #+#             */
/*   Updated: 2023/04/21 20:16:33 by Onizukkka        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*create_malloc(size_t size)
{
	void	*mem;

	mem = malloc(size);
	if (!mem)
		return (NULL);
	ft_bzero(mem, size);
	return (mem);
}

static char	*addnew(size_t size)
{
	size_t	i;
	char	*string;

	string = create_malloc(size + 1);
	if (!string)
		return (NULL);
	i = 0;
	while (i < size)
		string[i++] = '\0';
	return (string);
}

static int	count_size(int n)
{
	int	count;

	count = 0;
	if (n < 0)
		n *= -1;
	while (n != 0)
	{
		n /= 10;
		count++;
	}
	return (count);
}

char	*ft_itoa(int num)
{
	char		*dst;
	int			count;
	int			count_dst;
	long int	nb;

	nb = num;
	count = count_size(nb);
	count_dst = 0;
	if (nb < 0 || count == 0)
		count++;
	dst = addnew(count);
	if (!dst)
		return (NULL);
	if (nb < 0)
	{
		nb *= -1;
		dst[0] = '-';
		count_dst++;
	}
	while (count-- > count_dst)
	{
		dst[count] = (nb % 10) + '0';
		nb /= 10;
	}
	return (dst);
}
