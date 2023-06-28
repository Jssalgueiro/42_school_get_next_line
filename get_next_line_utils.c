/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsilva-s <jsilva-s@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/12 12:26:22 by jsilva-s          #+#    #+#             */
/*   Updated: 2023/06/28 13:28:06 by jsilva-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t size)
{
	unsigned int	i;
	unsigned int	c;

	i = 0;
	c = ft_strlen(src);
	if (size == 0)
		return (c);
	while (src[i] != '\0' && i < (size - 1) && size > 0)
	{
		dst[i] = src[i];
		i++;
	}
	dst[i] = '\0';
	return (c);
}

char	*ft_substr_gnl(char const *s, unsigned int start, size_t len)
{
	char	*subst;
	size_t	size;

	if (!s)
		return (NULL);
	if (start >= ft_strlen(s))
	{
		subst = (char *)malloc(1 * sizeof(char));
		subst[0] = '\0';
		return (subst);
	}
	size = ft_strlen(s + start);
	if (size < len)
		len = size;
	subst = (char *)malloc(sizeof(char) * (len + 1));
	if (!subst)
		return (NULL);
	ft_strlcpy(subst, s + start, len + 1);
	return (subst);
}

char	*ft_strjoin_gnl(char *storage, char *buffer)
{
	int		len1;
	int		len2;
	char	*output;

	if (!storage)
	{
		storage = (char *)malloc(1 * sizeof(char));
		storage[0] = '\0';
	}
	if (!storage)
		return (NULL);
	if (!buffer)
		return (NULL);
	len1 = ft_strlen(storage);
	len2 = ft_strlen(buffer);
	output = malloc((len1 + len2 + 1) * sizeof(char));
	if (output == NULL)
		return (0);
	output = ft_strcpy(output, storage);
	output = ft_strcpy(&output[len1], buffer);
	output = &output[-len1];
	if (*storage)
		free(storage);
	storage = NULL;
	return (output);
}

size_t	ft_strlen(const char *s)
{
	int	i;

	i = 0;
	while (s[i] != '\0')
		i++;
	return (i);
}

char	*ft_strcpy(char *dest, const char *s)
{
	int	i;

	i = 0;
	while (s[i] != '\0')
	{
		dest[i] = s[i];
		++i;
	}
	dest[i] = '\0';
	return (dest);
}

/* char	*ft_strdup(const char *s)
{
	int		len;
	char	*output;

	len = ft_strlen(s);
	output = malloc((len + 1) * sizeof(char));
	if (output == NULL)
		return (0);
	else
		output = ft_strcpy(output, s);
	return (output);
} */
