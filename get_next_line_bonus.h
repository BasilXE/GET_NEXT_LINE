/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: basayoub <basayoub@student.42amman.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/24 12:47:51 by basayoub          #+#    #+#             */
/*   Updated: 2026/11/24 14:42:51 by basayoub         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H

# include <unistd.h>
# include <stdlib.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1
# endif

char	*get_next_line(int fd);
char	*ft_stjoin(char *dest, char *src);
char	*clearer(char **t, char **t2);
char	*get_line(char *t);
char	*ft_strct(char *dest, char *src);
char	*iffer(char *txt, char **t2t, char *temp);
char	*remeber_of_read(char *t2t);
char	*looper(int fd, char *txt, char *t2t, char *temp);
int		malloccheck(char *txt, char **t2t);
int		checker(char *t);

#endif