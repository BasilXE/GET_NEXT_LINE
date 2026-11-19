/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: basayoub <basayoub@student.42amman.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/02 17:03:21 by basayoub          #+#    #+#             */
/*   Updated: 2026/11/19 02:38:07 by basayoub         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
#define GET_NEXT_LINE_H

#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>//
#include <fcntl.h>//

#ifndef BUFFER_SIZE
#define BUFFER_SIZE 1
#endif

char    *get_next_line(int fd);
char	*ft_stjoin(char *dest, char *src);
int	checker(char *t);
char	*clearer(char *t, char *t2);
char	*get_line(char *t);
char	*ft_strct(char *dest, char *src);




#endif