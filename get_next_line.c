/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: basayoub <basayoub@student.42amman.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/02 16:57:51 by basayoub          #+#    #+#             */
/*   Updated: 2026/11/19 02:52:49 by basayoub         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char    *get_next_line(int fd)
{
	ssize_t	b;
	char	*txt;
	char	*temp;
	static char	*t2t;

	b = 1;
	txt = malloc (BUFFER_SIZE + 1);
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
		if (b >= 0)
			txt[b] = '\0';
		temp = ft_stjoin(t2t, txt);
		if (!temp)
			return ((clearer(txt,t2t)));
		free (t2t);
		t2t = temp;
		if (checker(t2t) == 0)
			return (get_line(t2t));
	}
	free (txt);
	return (temp);
}
int main()
{
	size_t	i = 0;
	int fd = open("text.txt", O_RDONLY);
	while (i <= 2)
	{
		printf("%s",get_next_line(fd));
		i++;
	}
}