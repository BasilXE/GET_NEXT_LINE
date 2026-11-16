/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: basayoub <basayoub@student.42amman.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/02 16:57:51 by basayoub          #+#    #+#             */
/*   Updated: 2026/11/11 04:22:58 by basayoub         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char    *get_next_line(int fd)
{
	ssize_t	b;
	char	*txt;
	char	*t2t;

	b = 1;
	t2t = malloc (1);
	if (!t2t)
		return (NULL);
	t2t[0] = '\0';
	while(b > 0)
	{
		txt = malloc (BUFFER_SIZE + 1);
		if (!txt)
			return (clearerone(t2t));
		b = read(fd, txt, BUFFER_SIZE);
		if (b >= 0)
			txt[b] = '\0';
		t2t = ft_strjon(t2t, txt);
		if (checker(t2t) == 1)
			return (t2t);
		free (txt);
	}
	return (t2t);
}
/*int main()
{
	size_t	i = 0;
	int fd = open("text.txt", O_RDONLY);
	while (i <= 2)
	{
		printf("%s",get_next_line(fd));
		i++;
	}
}*/