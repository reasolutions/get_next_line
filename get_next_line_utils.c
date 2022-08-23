/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rarslan <42istanbul.com.tr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/04 20:36:17 by rarslan           #+#    #+#             */
/*   Updated: 2022/08/06 01:46:08 by rarslan          ###   ########.tr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i])
	{
		i++;
	}
	return (i);
}

char	*ft_strchr(char *str, int c)
{
	int	i;

	i = 0;
	while (str[i] != c && str[i])
	{
		i++;
	}
	if (str[i] == c)
	{
		return (&str[i]);
	}
	return (0);
}

char	*ft_strdup(const char *str)
{
	int		i;
	char	*yer;

	yer = malloc(sizeof(char) *(ft_strlen(str) + 1));
	if (!yer)
		return (0);
	i = 0;
	while (str[i])
	{
		yer[i] = str[i];
		i++;
	}
	yer[i] = '\0';
	return (yer);
}

char	*ft_strjoin(const char *s1, const char *s2)
{
	int		i;
	int		j;
	char	*yer;

	if (!s2 && !s1)
		return (0);
	yer = malloc(sizeof(char) *(ft_strlen(s1) + ft_strlen(s2) + 1));
	if (!yer)
		return (0);
	i = 0;
	while (s1[i])
	{
		yer[i] = s1[i];
		i++;
	}
	j = 0;
	while (s2[j])
	{
		yer[i + j] = s2[j];
		j++;
	}
	yer[i + j] = '\0';
	return (yer);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char		*result;
	size_t		i;
	size_t		size;

	if (s == NULL)
		return (NULL);
	if (ft_strlen(s) <= start)
		return (ft_strdup(""));
	size = ft_strlen(s);
	if (size < len)
		len = size;
	result = (char *)malloc(sizeof(char) * len + 1);
	if (result == NULL)
		return (NULL);
	i = 0;
	while (i < len)
	{
		result[i] = s[i + start];
		i++;
	}
	result[i] = '\0';
	return (result);
}
