/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rarslan <42istanbul.com.tr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/04 20:33:03 by rarslan           #+#    #+#             */
/*   Updated: 2022/08/06 01:58:51 by rarslan          ###   ########.tr       */
/*                                                                            */
/* ************************************************************************** */
#include "get_next_line_bonus.h"

static char	*readline(char *ln, int fd)
{
	int		bytesread;
	char	*buff;
	char	*cup;

	buff = malloc(sizeof(char) * BUFFER_SIZE + 1);
	if (!buff)
		return (NULL);
	if (!ln)
		ln = ft_strdup("");
	bytesread = 1;
	while (bytesread && !ft_strchr(ln, '\n'))
	{
		bytesread = read(fd, buff, BUFFER_SIZE);
		if (bytesread == -1)
			break ;
		buff[bytesread] = '\0';
		cup = ln;
		ln = ft_strjoin(ln, buff);
		free(cup);
	}
	free(buff);
	return (ln);
}

char	*get_next_line(int fd)
{
	static char	*ln[1024];
	char		*nextline;
	char		*temp;

	ln[fd] = readline(ln[fd], fd);
	if (ft_strchr(ln[fd], '\n'))
		nextline = ft_substr(ln[fd], 0, \
				ft_strchr(ln[fd], '\n') - &ln[fd][0] + 1);
	else
		nextline = ft_strdup(ln[fd]);
	if (nextline && nextline[0] == 0)
	{
		free(nextline);
		nextline = 0;
		free(ln[fd]);
		ln[fd] = 0;
		return (0);
	}
	temp = ln[fd];
	ln[fd] = ft_substr(ln[fd], ft_strchr(ln[fd], '\n') - ln[fd] + 1, \
			ft_strlen(ln[fd]));
	free (temp);
	return (nextline);
}
