/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abrandao <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/29 15:37:03 by abrandao          #+#    #+#             */
/*   Updated: 2026/05/29 15:37:05 by abrandao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdlib.h>
# include <unistd.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

char	*get_next_line(int fd);
char	*read_and_store(int fd, char *stored, char *buffer);
void	update_buffer(char *buffer, char *stored, int start);
char	*ft_strdup(const char *str);
char	*ft_strjoin(char *stored, char *buffer);
char	*ft_substr(char const *stored, unsigned int start, size_t len);

#endif
