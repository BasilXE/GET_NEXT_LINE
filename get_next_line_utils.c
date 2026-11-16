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

char	*ft_strjon(char const *s1, char const *s2)
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
int	checker(char *t2t)
{
	size_t	i;

	i = 0;
	while (t2t[i])
		i++;
	if (t2t[i - 1] == '\0' || t2t[i - 1] == '\n')
		return (1);
	return (0);
}
char	*clearerone(char *t)
{
	free (t);
	return (NULL);
}