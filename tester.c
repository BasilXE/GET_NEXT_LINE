/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tester.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: basayoub <basayoub@student.42amman.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/11 00:27:20 by basayoub          #+#    #+#             */
/*   Updated: 2026/11/11 00:27:20 by basayoub         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "get_next_line.h"

static char	*ft_strct(char *dest, char *src)
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
char    *get_next_line(int fd)
{
	ssize_t	b;
	char	*txt;
	char	*t2t;

	b = 1;
	t2t = malloc (BUFFER_SIZE);
	while(b > 0)
	{
		txt = malloc (BUFFER_SIZE);
		b = read(fd, txt, BUFFER_SIZE);
		if (b > 0)
			txt[b] = '\0';
		t2t = ft_strjon(t2t, txt);
		free (txt);
	}
	// t2t = spliter (t2t);
	return (t2t);
}
int main()
{
	//size_t	i = 0;
	int fd = open("text.txt", O_RDONLY);
	//while (i <= 2)
	//{
		printf("%s\n",get_next_line(fd));
	//	i++;
	//}
}