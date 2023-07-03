/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsilva-s <jsilva-s@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/12 12:26:22 by jsilva-s          #+#    #+#             */
/*   Updated: 2023/07/03 12:09:03 by jsilva-s         ###   ########.fr       */
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

	if (!s)
		return (NULL);
	subst = (char *)malloc(sizeof(char) * (len + 1));
	if (!subst)
		return (NULL);
	if (start == ft_strlen(s))
		subst[0] = '\0';
	else
		ft_strlcpy(subst, s + start, len + 1);
	return (subst);
}

char	*ft_strjoin_gnl(char *storage, char *buffer)
{
	int		len1;
	int		len2;
	char	*output;

	if (!buffer)
		return (NULL);
	if (!storage)
	{
		storage = malloc(1);
		storage[0] = '\0';
	}
	if (!storage)
		return (NULL);
	len1 = ft_strlen(storage);
	len2 = ft_strlen(buffer);
	output = malloc((len1 + len2 + 1) * sizeof(char));
	if (!output)
		return (NULL);
	output = ft_strcpy(output, storage);
	output = ft_strcpy(&output[len1], buffer);
	output = &output[-len1];
	if (*storage)
		free(storage);
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
