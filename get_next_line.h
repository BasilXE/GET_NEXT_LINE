/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: basayoub <basayoub@student.42amman.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/02 17:03:21 by basayoub          #+#    #+#             */
/*   Updated: 2026/11/11 04:22:03 by basayoub         ###   ########.fr       */
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
char	*clearerone(char *t);
int	checker(char *t2t);
char	*ft_strjon(char const *s1, char const *s2);
char	*ft_strct(char *dest, char *src);





#endif