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

size_t	ft_strlen(char *str)
{
	size_t	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

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

char	*ft_strjoin(char *s1, char *s2)
{
	char	*new_str;
	int		i;
	int		j;

	if (s2 == NULL)
		return (s1);
	if (s1 == NULL)
	{
		s1 = (char *)malloc(sizeof(char) * 1);
		if (!s1)
			return (NULL);
		s1[0] = '\0';
	}
	new_str = (char *)malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1));
	if (!new_str)
		return (free(s1), NULL);
	i = -1;
	while (s1[++i])
		new_str[i] = s1[i];
	j = -1;
	while (s2[++j])
		new_str[i + j] = s2[j];
	new_str[i + j] = '\0';
	return (free(s1), new_str);
}

char	*ft_substr(char *s, unsigned int start, size_t len)
{
	char	*sub_str;
	size_t	i;
	size_t	s_len;

	if (!s)
		return (NULL);
	s_len = ft_strlen(s);
	if (start >= s_len)
		len = 0;
	else if (len > s_len - start)
		len = s_len - start;
	sub_str = (char *)malloc(sizeof(char) * (len + 1));
	if (!sub_str)
		return (NULL);
	i = 0;
	while (i < len && s[start + i])
	{
		sub_str[i] = s[start + i];
		i++;
	}
	sub_str[i] = '\0';
	return (sub_str);
}
