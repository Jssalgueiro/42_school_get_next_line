#include "get_next_line.h"

size_t	ft_strlen(const char *str)
{
	size_t	i;

	if (!str)
		return (0);
	i = 0;
	while (str[i])
		i++;
	return (i);
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
}

void	*ft_memcpy(void *dest, const void *src, size_t len)
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
}

char	*ft_substr(char const *str, unsigned int start, size_t len)
{
	char	*new_str;
	size_t	i;

	if (!str)
		return (0);
	new_str = malloc((len + 1) * sizeof(char));
	if (!new_str)
		return (0);
	else if (start >= ft_strlen(str))
		new_str[0] = '\0';
	else
	{
		i = 0;
		while (str[start + i] && i < len)
		{
			new_str[i] = str[start + i];
			i++;
		}
		new_str[i] = '\0';
	}
	return (new_str);
}

char	*ft_strjoin(char const *str1, char const *str2)
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