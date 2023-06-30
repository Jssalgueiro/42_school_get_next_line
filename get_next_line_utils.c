/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsilva-s <jsilva-s@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/12 12:26:22 by jsilva-s          #+#    #+#             */
/*   Updated: 2023/06/30 16:17:12 by jsilva-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

/* void	*ft_memcpy(void *dest, const void *src, size_t len)
{
	char		*p_dest;
	const char	*p_src;

	if (dest == src)
		return (dest);
	p_dest = dest;
	p_src = src;
	while (len--)
		p_dest[len] = p_src[len];
	return (p_dest);
} */

/* char	*ft_strjoin(char const *str1, char const *str2)
{
	size_t str1_len;
	size_t str2_len;
	char *new_str;

	if (!str1 || !str2)
		return (0);
	str1_len = ft_strlen(str1);
	str2_len = ft_strlen(str2);
	new_str = malloc((str1_len + str2_len + 1) * sizeof(char));
	if (!new_str)
		return (0);
	ft_memcpy(new_str, str1, str1_len);
	ft_memcpy((new_str + str1_len), str2, str2_len);
	new_str[str1_len + str2_len] = '\0';
	return (new_str);
}

char	*ft_strchr(const char *str, int character)
{
	if (!str || character < 0 || character > 127)
		return (0);
	while (*str && *str != character)
		str++;
	if (*str != character)
		return (0);
	return ((char *)str);
} */

size_t	ft_strlcpy(char *dst, const char *src, size_t size)/11
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
	if (start >= ft_strlen(s))
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
		storage = (char *)malloc(1 * sizeof(char));
		storage[0] = '\0';
	}
	if (!storage)
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
