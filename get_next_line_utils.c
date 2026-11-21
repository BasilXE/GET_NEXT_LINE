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
char	*get_line(char *t)
{
	size_t	i;
	char	*t2;

	i = 0;
	while (t[i])
		i++;
	
	t2 = malloc(i + 2);
	if (!t2)
		return (NULL);
	i = 0;
	while (t[i] && (t[i] != '\n'))
	{
		t2[i] = t[i];
		i++;
	}
	if (t[i] == '\n')
	{
		t2[i] = t[i];
		t2[i + 1] = '\0';
	}
	else
		t2[i] = '\0';
	return (t2);
}
char	*clearer(char *t, char *t2)
{
	free (t2);
	free (t);
	return (NULL);
}
