/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: basayoub <basayoub@student.42amman.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/02 16:57:51 by basayoub          #+#    #+#             */
/*   Updated: 2026/11/24 17:39:34 by basayoub         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_strct(char *dest, char *src)
{
	size_t	i;
	size_t	j;

	j = 0;
	i = 0;
	while (dest[i] != '\0')
	{
		i++;
	}
	while (src[j] != '\0')
	{
		dest[i] = src[j];
		i++;
		j++;
	}
	dest[i] = '\0';
	return (dest);
}

int	malloccheck(char *txt, char **t2t)
{
	if (!txt)
	{
		free (*t2t);
		*t2t = NULL;
		return (0);
	}
	if (!*t2t)
	{
		*t2t = malloc (1);
		if (!*t2t)
		{
			free (txt);
			return (0);
		}
		(*t2t)[0] = '\0';
	}
	return (1);
}

int	checker(char *t)
{
	size_t	i;

	i = 0;
	while (t[i])
	{
		if (t[i] == '\n')
			return (0);
		i++;
	}
	return (1);
}

char	*clearer(char **t, char **t2)
{
	if (t && *t)
	{
		free (*t);
		*t = NULL;
	}
	if (t2 && *t2)
	{
		free (*t2);
		*t2 = NULL;
	}
	return (NULL);
}

char	*get_next_line(int fd)
{
	char		*txt;
	char		*temp;
	static char	*t2t;

	temp = NULL;
	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	txt = malloc ((size_t)BUFFER_SIZE + 1);
	if (malloccheck(txt, &t2t) == 0)
		return (NULL);
	t2t = looper(fd, txt, t2t, temp);
	if (t2t == NULL)
		return (NULL);
	return (iffer (txt, &t2t, temp));
}
/*
#include <stdio.h>
#include <fcntl.h>
int main()
{
	size_t	i = 0;
	char	*line;
	int fd = open("text.txt", O_RDONLY);
	while (i <= 2)
	{
		line = get_next_line(fd);
		printf("%s",line);
		free (line);
		i++;
	}
	close (fd);
}*/
