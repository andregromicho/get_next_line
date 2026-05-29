/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abrandao <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/29 15:37:14 by abrandao          #+#    #+#             */
/*   Updated: 2026/05/29 15:37:15 by abrandao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_strdup(const char *str)
{
	char	*dest;
	size_t	i;
	size_t	len;

	len = 0;
	while (str[len])
		len++;
	dest = malloc(len + 1);
	if (!dest)
		return (NULL);
	i = 0;
	while (str[i])
	{
		dest[i] = str[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}

char	*ft_substr(char const *stored, unsigned int start, size_t len)
{
	char	*sub;
	size_t	i;

	if (!stored)
		return (NULL);
	sub = malloc(len + 1);
	if (!sub)
		return (NULL);
	i = 0;
	while (i < len && stored[start + i])
	{
		sub[i] = stored[start + i];
		i++;
	}
	sub[i] = '\0';
	return (sub);
}

char	*ft_strjoin(char *stored, char *buffer)
{
	char	*joined;
	size_t	s_len;
	size_t	b_len;
	size_t	i;
	size_t	j;

	if (!stored)
		return (ft_strdup(buffer));
	s_len = 0;
	while (stored[s_len])
		s_len++;
	b_len = 0;
	while (buffer[b_len])
		b_len++;
	joined = malloc(s_len + b_len + 1);
	if (!joined)
		return (free(stored), NULL);
	i = -1;
	while (stored[++i])
		joined[i] = stored[i];
	j = -1;
	while (buffer[++j])
		joined[i + j] = buffer[j];
	joined[i + j] = '\0';
	return (free(stored), joined);
}

void	update_buffer(char *buffer, char *stored, int start)
{
	int	i;

	i = 0;
	while (stored[start])
		buffer[i++] = stored[start++];
	while (i < BUFFER_SIZE + 1)
		buffer[i++] = '\0';
}

char	*read_and_store(int fd, char *stored, char *buffer)
{
	int	bytes_read;
	int	i;

	bytes_read = 1;
	while (bytes_read != 0)
	{
		i = 0;
		while (stored && stored[i])
		{
			if (stored[i] == '\n')
				return (stored);
			i++;
		}
		bytes_read = read(fd, buffer, BUFFER_SIZE);
		if (bytes_read == -1)
		{
			buffer[0] = '\0';
			return (free(stored), NULL);
		}
		buffer[bytes_read] = '\0';
		stored = ft_strjoin(stored, buffer);
		if (!stored)
			return (NULL);
	}
	return (stored);
}
