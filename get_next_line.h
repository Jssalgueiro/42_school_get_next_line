/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jessica <jessica@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/12 12:26:32 by jsilva-s          #+#    #+#             */
/*   Updated: 2023/06/26 22:03:23 by jessica          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

#ifndef BUFFER_SIZE
# define BUFFER_SIZE 10
#endif

# include <limits.h>
# include <stdarg.h>
# include <stdint.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <stddef.h>
# include <fcntl.h> //define the flags to open function

char    *get_next_line(int fd);
size_t  ft_strlen(const char *s);
char    *ft_strcpy(char *dest, const char *s);
char    *ft_strdup(const char *s);
void    ft_print_line(char *str);
char    *ft_print_gnl(char *str, char *tmp, int fd);
char	*ft_strchr(const char *s, int c);
char	*ft_strjoin_gnl(char *storage, char *buffer);

#endif
