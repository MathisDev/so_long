/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamottet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/15 17:53:23 by mamottet          #+#    #+#             */
/*   Updated: 2023/08/25 10:49:22 by mamottet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdlib.h>
# include <unistd.h>

# ifndef BUFFER_SIZE
# define BUFFER_SIZE 42
# endif



size_t	ft_gnl_strlen(const char *s);
char	*ft_gnl_substr(char const *s, unsigned int start, size_t len);
char	*ft_gnl_strchr(const char *s, int i);
char	*ft_gnl_strdup(const char *s);
char	*ft_gnl_strjoin(char const *s1, char const *s2);
char	*get_next_line(int fd);

#endif
