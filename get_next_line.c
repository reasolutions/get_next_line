/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rarslan <42istanbul.com.tr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/04 20:33:03 by rarslan           #+#    #+#             */
/*   Updated: 2022/08/06 01:39:38 by rarslan          ###   ########.tr       */
/*                                                                            */
/* ************************************************************************** */
#include "get_next_line.h"

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
	static char	*ln;
	char		*nextline;
	char		*temp;

	ln = readline(ln, fd);
	if (ft_strchr(ln, '\n'))
		nextline = ft_substr(ln, 0, ft_strchr(ln, '\n') - &ln[0] + 1);
	else
		nextline = ft_strdup(ln);
	if (nextline && nextline[0] == 0)
	{
		free(nextline);
		nextline = 0;
		free(ln);
		ln = 0;
		return (0);
	}
	temp = ln;
	ln = ft_substr(ln, ft_strchr(ln, '\n') - ln + 1, ft_strlen(ln));
	free (temp);
	return (nextline);
}
