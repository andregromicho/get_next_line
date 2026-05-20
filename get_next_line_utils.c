/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abrandao <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/19 12:53:21 by abrandao          #+#    #+#             */
/*   Updated: 2026/05/19 12:53:24 by abrandao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_strchr(char *s, int c)
{
	int	i;

	if (!s)
		return (NULL);
	i = 0;
	while (s[i])
	{
		if (s[i] == c)
			return (&s[i]);
		i++;
	}
	if (s[i] == c)
		return (&s[i]);
	return (NULL);
}

char	*ft_strjoin(char *stored, char *buffer)
{
	char	*new_str;
	size_t	i;
	size_t	s_len;
	size_t	b_len;

	s_len = 0;
	while (stored && stored[s_len])
		s_len++;
	b_len = 0;
	while (buffer && buffer[b_len])
		b_len++;
	new_str = (char *)malloc(sizeof(char) * (s_len + b_len + 1));
	if (!new_str)
		return (free(stored), NULL);
	i = 0;
	while (stored && stored[i])
	{
		new_str[i] = stored[i];
		i++;
	}
	b_len = 0;
	while (buffer && buffer[b_len])
		new_str[i++] = buffer[b_len++];
	new_str[i] = '\0';
	return (free(stored), new_str);
}

char	*read_and_store(int fd, char *stored)
{
	char	*buffer;
	int		bytes_read;

	buffer = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buffer)
		return (free(stored), NULL);
	bytes_read = 1;
	while (bytes_read > 0 && !ft_strchr(stored, '\n'))
	{
		bytes_read = read(fd, buffer, BUFFER_SIZE);
		if (bytes_read == -1)
			return (free (buffer), free(stored), NULL);
		if (bytes_read == 0)
			break ;
		buffer[bytes_read] = '\0';
		stored = ft_strjoin(stored, buffer);
		if (!stored)
			return (free(buffer), NULL);
	}
	return (free(buffer), stored);
}

char	*ft_strdup_len(char *stored, size_t len)
{
	char	*new_str;
	size_t	i;

	if (!stored || len == 0)
		return (NULL);
	new_str = (char *)malloc(sizeof(char) * (len + 1));
	if (!new_str)
		return (NULL);
	i = 0;
	while (i < len && stored[i])
	{
		new_str[i] = stored[i];
		i++;
	}
	new_str[i] = '\0';
	return (new_str);
}

char	*update_stored(char *stored)
{
	char	*new_stored;
	size_t	i;
	size_t	len;

	if (!stored)
		return (NULL);
	i = 0;
	while (stored[i] && stored[i] != '\n')
		i++;
	if (!stored[i] || !stored[i + 1])
		return (free(stored), NULL);
	len = 0;
	while (stored[i + 1 + len])
		len++;
	new_stored = ft_strdup_len(&stored[i + 1], len);
	return (free(stored), new_stored);
}
