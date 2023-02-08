/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkord <gkord@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/13 14:35:11 by gkord             #+#    #+#             */
/*   Updated: 2022/03/06 15:39:06 by gkord            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_null_antileak(char *res, char *buffer, char *line)
{
	if (res)
		free (res);
	if (buffer)
		free (buffer);
	if (line)
		free (line);
	return (NULL);
}

char	*ft_clear_line(char *res)
{
	int		line_break;
	char	*buf;
	int		i;

	line_break = 0;
	while (res[line_break] && res[line_break] != '\n')
		line_break++;
	if (!res[line_break])
		return (ft_null_antileak(res, NULL, NULL));
	buf = (char *)malloc(sizeof(char) * (ft_strlen(res) - line_break + 1));
	if (!buf)
		return (ft_null_antileak(res, NULL, NULL));
	i = 0;
	line_break++;
	while (res[line_break])
		buf[i++] = res[line_break++];
	buf[i] = '\0';
	free (res);
	return (buf);
}

char	*ft_read_line(int fd, char *res)
{
	char	*buffer;
	int		check;

	buffer = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buffer)
		return (NULL);
	buffer[BUFFER_SIZE] = '\0';
	check = 1;
	while (!ft_strchr(res, '\n') && check != 0)
	{
		check = read(fd, buffer, BUFFER_SIZE);
		if (check == -1)
			return (ft_null_antileak(NULL, buffer, NULL));
		buffer[check] = '\0';
		res = ft_strjoin(res, buffer);
	}
	free(buffer);
	return (res);
}

char	*get_next_line(int fd)
{
	static char	*res;
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	res = ft_read_line(fd, res);
	if (!res)
		return (NULL);
	line = ft_extract_line(res);
	res = ft_clear_line(res);
	return (line);
}
