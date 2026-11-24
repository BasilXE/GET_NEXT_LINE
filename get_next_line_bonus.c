/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: basayoub <basayoub@student.42amman.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/24 12:47:15 by basayoub          #+#    #+#             */
/*   Updated: 2026/11/24 18:22:30 by basayoub         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*remeber_of_read(char *t2t)
{
	char	*temper;
	size_t	i;

	i = 0;
	temper = get_line(t2t);
	if (!temper)
	{
		free (t2t);
		return (NULL);
	}
	while (t2t[i])
	{
		if (temper[i] != t2t[i])
			break ;
		i++;
	}
	free (temper);
	temper = ft_stjoin("", t2t + i);
	free (t2t);
	return (temper);
}

int	malloccheck(char *txt, char **t2t)
{
	if (!txt)
	{
		free (t2t);
		t2t = NULL;
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

char	*iffer(char *txt, char **t2t, char *temp)
{
	free (txt);
	if ((*t2t)[0] == '\0')
	{
		free(*t2t);
		return (*t2t = NULL);
	}
	if (checker(*t2t))
	{
		temp = *t2t;
		*t2t = NULL;
		return (temp);
	}
	temp = get_line(*t2t);
	if (!temp)
	{
		free (*t2t);
		return (*t2t = NULL);
	}
	*t2t = remeber_of_read(*t2t);
	if (!*t2t)
	{
		free (temp);
		return (NULL);
	}
	return (temp);
}

char	*looper(int fd, char *txt, char *t2t, char *temp)
{
	ssize_t	b;

	b = 1;
	while (b > 0 && checker(t2t))
	{
		b = read(fd, txt, BUFFER_SIZE);
		if (b < 0)
		{
			clearer (&txt, &t2t);
			t2t = NULL;
			return (NULL);
		}
		txt[b] = '\0';
		temp = ft_stjoin(t2t, txt);
		free (t2t);
		t2t = temp;
		if (!t2t)
			return (clearer (&txt, NULL));
	}
	return (t2t);
}

char	*get_next_line(int fd)
{
	char		*txt;
	char		*temp;
	static char	*t2t[2048];

	temp = NULL;
	if (fd < 0 || BUFFER_SIZE <= 0 || fd >= 2048)
		return (NULL);
	txt = malloc ((size_t)BUFFER_SIZE + 1);
	if (malloccheck(txt, &t2t[fd]) == 0)
		return (NULL);
	t2t[fd] = looper(fd, txt, t2t[fd], temp);
	if (t2t[fd] == NULL)
		return (NULL);
	return (iffer (txt, &t2t[fd], temp));
}
/*#include <stdio.h>
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