/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsilva-s <jsilva-s@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/12 12:26:32 by jsilva-s          #+#    #+#             */
/*   Updated: 2023/07/05 13:26:33 by jsilva-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H
# include <fcntl.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 10
# endif

size_t	ft_strlcpy(char *dst, const char *src, size_t size);
char	*ft_substr_gnl(char const *s, unsigned int start, size_t len);
char	*get_next_line(int fd);
size_t	ft_strlen(const char *s);
char	*ft_strcpy(char *dest, const char *s);
char	*ft_strjoin_gnl(char *storage, char *buffer);

#endif
