/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: basayoub <basayoub@student.42amman.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/11 04:17:49 by basayoub          #+#    #+#             */
/*   Updated: 2026/11/11 04:17:49 by basayoub         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_stjoin(char *s1, char *s2)
{
	size_t		i;
	size_t		j;
	char		*str;

	i = 0;
	j = 0;
	while (s1[i] != '\0')
		i++;
	while (s2[j] != '\0')
		j++;
	str = malloc(i + j + 1);
	if (str == NULL)
		return (NULL);
	str[0] = '\0';
	str = ft_strct(str, (char *)s1);
	str = ft_strct(str, (char *)s2);
	return (str);
}

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

char	*get_line(char *t)
{
	size_t	i;
	char	*t2;

	i = 0;
	while (t[i] && t[i] != '\n')
		i++;
	if (t[i] == '\n')
		i++;
	t2 = malloc (i + 1);
	if (!t2)
		return (NULL);
	t2[i] = '\0';
	while (i--)
		t2[i] = t[i];
	return (t2);
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
