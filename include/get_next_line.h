/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlouvrie <rlouvrie@student.42.fr >         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/21 20:22:07 by rlouvrie          #+#    #+#             */
/*   Updated: 2023/08/22 14:14:48 by rlouvrie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# ifndef BUFFER_SIZE
# define BUFFER_SIZE 5
# endif
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>

char	*get_next_line(int fd);
char	*get_next_line2(int fd);
char	*ft_strjoin(const char *s1, char const *s2);
char	*ft_substr(char *s, unsigned int start, size_t len);
char	*ft_strchr(const char *s, int c);
size_t	ft_strlen(const char *s);
#endif