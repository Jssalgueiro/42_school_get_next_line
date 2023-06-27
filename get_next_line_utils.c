/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jessica <jessica@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/12 12:26:22 by jsilva-s          #+#    #+#             */
/*   Updated: 2023/06/26 18:27:40 by jessica          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_strjoin_gnl(char *storage, char *buffer)
{
	int		len1;
	int		len2;
	char	*output;

    if(!storage)
    {
        storage = (char *)malloc(1 * sizeof(char));
        storage[0] = '\0';
    }
    if (!storage)
        return(NULL);
    if(!buffer)
        return(NULL);
len1 = ft_strlen(storage);
len2 = ft_strlen(buffer);
	output = malloc((len1 + len2 + 1) * sizeof(char));
	if (output == NULL)
		return (0);
    if(len1 != 0)
		output = ft_strcpy(output, storage);
	output = ft_strcpy(&output[len1], buffer);
	output = &output[-len1];
 	if(*storage)
        free(storage);
    storage = NULL;
	return (output);
}

char	*ft_strchr(const char *s, int c)
{
	unsigned int	i;
	unsigned int	len;
	char			*temp;
	char			conv;

	conv = (char)c;
	temp = (char *)s;
	i = 0;
	len = ft_strlen(s);
	while (i <= len)
	{
		if (temp[i] == conv)
			return (&temp[i]);
		i++;
	}
	return (NULL);
}

size_t ft_strlen(const char *s)
{
    int i;

    i = 0;
    while (s[i] != '\0')
        i++;
    return (i);
}

char *ft_strcpy(char *dest, const char *s)
{
    int i;

    i = 0;
    while (s[i] != '\0')
    {
        dest[i] = s[i];
        ++i;
    }
    dest[i] = '\0';
    return (dest);
}

char *ft_strdup(const char *s)
{
    int len;
    char *output;

    len = ft_strlen(s);
    output = malloc((len + 1) * sizeof(char));
    if (output == NULL)
        return (0);
    else
        output = ft_strcpy(output, s);
    return (output);
}

/* char *ft_print_gnl(char *str, char *tmp, int fd)
{
    int i;
    char *line;

    i = 0;
    if (*tmp != '\0' && *tmp )
    {
        ft_print_line(tmp);
        free(tmp);
    }
    while (str[i] != '\n' && str[i] != '\0')
    {
        line[i] = str[i];
        i++;
    }
    if (str[i] == '\n')
    {
        line[++i] = '\n';
        tmp = ft_strdup(&str[i]); //alocou o tmp
    }
    else if(i == BUFFER_SIZE)
    {
        i = read(fd, str, BUFFER_SIZE);
        str[i] = '\0';
        ft_print_gnl(str, tmp, fd);
    }
    //printf("tmp %s\n", tmp);
    printf("buff %s\n", buff);
    printf("cmp %d\n", ft_strncmp(str, tmp, BUFSIZE));
    return(line);
}*/