#include "get_next_line.h"

char    *read_and_store(int fd, char *stored)
{
    char    *buffer;
    int     bytes_read;

    buffer = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
    if (!buffer)
        return (NULL);
    bytes_read = 1;
    while (!ft_strchr(stored, '\n') && bytes_read != 0)
    {
        bytes_read = read(fd, buffer, BUFFER_SIZE);
        if (bytes_read == -1)
        {
            free(buffer);
            free(stored);
            return (NULL);
        }
        buffer[bytes_read] = '\0';
        stored = ft_strjoin(stored, buffer);
    }
    free(buffer);
    return (stored);
}

char    *extract_line(char *stored)
{
    char    *line;
    size_t  i;

    if (!stored || !stored[0])
        return (NULL);
    i = 0;
    while (stored[i] && stored[i] != '\n')
        i++;
    line = ft_substr(stored, 0, i);
    return (line);
}

char    *update_stored(char *stored)
{
    char    *new_stored;
    size_t  stored_len;
    size_t  line_len;

    stored_len = ft_strlen(stored);
    line_len = ft_strlen(ft_strchr(stored, '\n')) + 1;
    new_stored = ft_substr(stored, stored_len - line_len, line_len);
    free(stored);
    return (new_stored);
}

char *get_next_line(int fd)
{
    char    *line;
    static char *stored;
    size_t  stored_len;
    size_t  line_len;

    if (fd < 0 || BUFFER_SIZE <= 0)
        return (NULL);
    stored = read_and_store(fd, stored);
    if (!stored)
        return (NULL);
    line = extract_line(stored);
    stored = update_stored(stored);
    return (line);
}

