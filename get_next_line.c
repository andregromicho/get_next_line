/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abrandao <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/19 12:53:03 by abrandao          #+#    #+#             */
/*   Updated: 2026/05/19 12:53:09 by abrandao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	char		*line;
	static char	*stored;
	size_t		i;

	if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, 0, 0) < 0)
		return (free(stored), stored = NULL, NULL);
	stored = read_and_store(fd, stored);
	if (!stored || !stored[0])
		return (free(stored), stored = NULL, NULL);
	i = 0;
	while (stored[i] && stored[i] != '\n')
		i++;
	if (stored[i] == '\n')
		i++;
	line = ft_strdup_len(stored, i);
	if (!line)
		return (free(stored), stored = NULL, NULL);
	stored = update_stored(stored);
	return (line);
}

/* #include "get_next_line.h"
#include <stdio.h>
#include <fcntl.h>

int main(void)
{
    int fd;
    char *line;

    fd = open("teste.txt", O_RDONLY);
    if (fd < 0)
    {
        printf("Error opening file");
        return (1);
    }
    while ((line = get_next_line(fd)) != NULL)
    {
        printf("line :%s", line);
        free(line);
    }
    close(fd);
    return (0);
} */