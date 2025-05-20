/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dayano <dayano@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/21 15:50:09 by dayano            #+#    #+#             */
/*   Updated: 2025/05/20 15:35:08 by dayano           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static char	*extract_line(char *save)
{
	char	*ext_line;
	int		ext_line_size;

	if (!*save)
		return (NULL);
	if (!ft_strchr(save, '\n'))
		ext_line_size = ft_strlen(save);
	else
		ext_line_size = ft_strchr(save, '\n') - save + 1;
	ext_line = ft_substr(save, 0, ext_line_size);
	if (!ext_line)
	{
		return (free(save), NULL);
	}
	return (ext_line);
}

static char	*update_save(char *save)
{
	char	*remained_save;
	char	*new_save_pos;

	if (!*save)
	{
		return (free(save), NULL);
	}
	new_save_pos = ft_strchr(save, '\n');
	if (!new_save_pos)
		return (free(save), NULL);
	remained_save = ft_strdup(new_save_pos + 1);
	if (!remained_save)
	{
		return (free(save), NULL);
	}
	if (remained_save[0] == '\0')
	{
		return (free(remained_save), free(save), NULL);
	}
	free(save);
	return (remained_save);
}

static char	*read_and_append(int fd, char *buff, char *save)
{
	char	*tmp;
	int		read_size;

	read_size = read(fd, buff, BUFFER_SIZE);
	while (read_size > 0)
	{
		buff[read_size] = '\0';
		if (!save)
			save = ft_strdup("");
		tmp = save;
		save = ft_strjoin(save, buff);
		free(tmp);
		tmp = NULL;
		if (!save)
			return (NULL);
		if (!*save || ft_strchr(save, '\n'))
			break ;
		read_size = read(fd, buff, BUFFER_SIZE);
	}
	free(buff);
	buff = NULL;
	if (read_size < 0 || (read_size == 0 && !save))
		return (NULL);
	return (save);
}

char	*get_next_line(int fd)
{
	static char	*save = NULL;
	char		*buff;
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0 || BUFFER_SIZE >= SIZE_MAX)
		return (NULL);
	buff = (char *)malloc(sizeof(char) * BUFFER_SIZE + 1);
	if (!buff)
		return (NULL);
	save = read_and_append(fd, buff, save);
	if (!save)
		return (NULL);
	line = extract_line(save);
	if (!line || line[0] == '\0')
	{
		free(save);
		save = NULL;
	}
	else
	{
		save = update_save(save);
	}
	return (line);
}
