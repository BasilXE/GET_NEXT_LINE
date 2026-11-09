/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: basayoub <basayoub@student.42amman.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/02 16:57:51 by basayoub          #+#    #+#             */
/*   Updated: 2026/11/09 18:12:30 by basayoub         ###   ########.fr       */
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
	size_t	i;
	char	*txt;
	static char	*t2t;

	i = 0;
	b = 1;
	t2t = malloc (BUFFER_SIZE + 1);
	while(b > 0)
	{
		txt = malloc (BUFFER_SIZE + 1);
		b = read(fd, txt, BUFFER_SIZE);
		t2t = ft_strjon(t2t, txt);
		
		free (txt);
	}
	printf("*%zd*", b);
	return (t2t);
}
int main()
{
	//size_t	i = 0;
	int fd = open("text.txt", O_RDONLY);
	//while (i <= 2)
	//{
		printf("%s",get_next_line(fd));
	//	i++;
	//}
}