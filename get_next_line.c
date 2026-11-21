/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: basayoub <basayoub@student.42amman.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/02 16:57:51 by basayoub          #+#    #+#             */
/*   Updated: 2026/11/21 17:33:01 by basayoub         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*remeber_of_read(char *t2t)
{
	char	*temper;
	size_t	i;

	i = 0;
	temper = get_line(t2t);
	if (!temper)
		return (NULL);
	while(t2t[i])
	{
		if (temper[i] != t2t[i])
			break;
		i++;
	}
	free (temper);
	temper = ft_stjoin("", t2t + i);
	if (!temper)
		return (NULL);
	free (t2t);
	return (temper);
}

char    *get_next_line(int fd)
{
	ssize_t	b;
	char	*txt;
	char	*temp;
	static char	*t2t;

	b = 1;
	txt = malloc (BUFFER_SIZE + 1);
	temp = NULL;
	if (!txt)
		return (NULL);
	if (!t2t)
	{
		t2t = malloc (1);
		if (!t2t)
			return (clearer(txt, NULL));
		t2t[0] = '\0';
	}
	while (b > 0)
	{
		b = read(fd, txt, BUFFER_SIZE);
		printf ("%zd",b);
		if (b >= 0)
			txt[b] = '\0';
		else
		{
			clearer (txt,t2t);
			return (NULL);
		}
		temp = ft_stjoin(t2t, txt);
		if (!temp)
			return ((clearer(txt,t2t)));
		free (t2t);
		t2t = temp;
		if (checker(t2t) == 0)
		{
			temp = get_line(t2t);
			t2t = remeber_of_read(t2t);
			free (txt);
			return (temp);
		}
	}
	free (txt);
	return (temp);
}
int main()
{
	size_t	i = 0;
	char	*line;
	int fd = open("text.txt", O_RDONLY);
	while (i <= 4)
	{
		line = get_next_line(fd);
		printf("%s",line);
		free (line);
		i++;
	}
	close (fd);
}