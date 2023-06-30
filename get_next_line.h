/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsilva-s <jsilva-s@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/12 12:26:32 by jsilva-s          #+#    #+#             */
/*   Updated: 2023/06/30 14:12:19 by jsilva-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 10
# endif

# include <fcntl.h> //define the flags to open function
# include <limits.h>
# include <stdarg.h>
# include <stddef.h>
# include <stdint.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

void	*ft_memcpy(void *dest, const void *src, size_t len);
char	*ft_strjoin(char const *str1, char const *str2);
char	*ft_strchr(const char *str, int character);
size_t	ft_strlcpy(char *dst, const char *src, size_t size);
char	*ft_substr_gnl(char const *s, unsigned int start, size_t len);
char	*get_next_line(int fd);
size_t	ft_strlen(const char *s);
char	*ft_strcpy(char *dest, const char *s);
char	*ft_strdup(const char *s);
void	ft_print_line(char *str);
char	*ft_print_gnl(char *str, char *tmp, int fd);
char	*ft_strchr(const char *s, int c);
char	*ft_strjoin_gnl(char *storage, char *buffer);

#endif
