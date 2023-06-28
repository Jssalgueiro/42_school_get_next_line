/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsilva-s <jsilva-s@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/12 10:40:58 by jsilva-s          #+#    #+#             */
/*   Updated: 2023/06/28 13:23:52 by jsilva-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*Description: function that returns a line read from a file descriptor.
Parameters: fd: The file descriptor to read from
Return:
Read line: correct behavior
NULL: there is nothing else to read, or an error occurred
*/

// Testar compilar sem passar o buffer

#include "get_next_line.h"

char	*ft_remove_line(char *storage, char *line)
{
	int		len_line;
	int		len_storage;
	char	*output;

	if (storage == NULL || line == NULL)
	{
		free(line);
		return (NULL);
	}
	len_line = ft_strlen(line);
	len_storage = ft_strlen(storage);
	output = ft_substr_gnl(storage, len_line, len_storage - len_line);
	free(storage);
	if (output[0] == '\0')
	{
		free(output);
		return (NULL);
	}
	return (output);
}

char	*ft_buff_line(char *storage)
{
	int		i;
	char	*line;

	i = 0;
	if (*storage == '\0')
		return (NULL);
	while (storage[i] != '\0' && storage[i] != '\n')
		i++;
	if (storage[i] == '\n')
		i++;
	line = ft_substr_gnl(storage, 0, i);
	if (line == NULL)
	{
		free(line);
		return (NULL);
	}
	return (line);
}

int	ft_nl(char *str)
{
	int	i;
	int	nl;

	i = 0;
	nl = 0;
	while (str[i] != '\0')
	{
		if (str[i] == '\n')
			nl++;
		i++;
	}
	return (nl);
}

char	*ft_read_buff(int fd, char *storage)
{
	char	*buffer;
	int		n;

	n = 1;
	buffer = malloc(sizeof(char) * BUFFER_SIZE + 1);
	if (!buffer)
		return (NULL);
	if (!storage)
		storage = "";
	while (ft_nl(storage) == 0 && n != 0)
	{
		n = read(fd, buffer, BUFFER_SIZE);
		if (n == -1)
		{
			free(buffer);
			return (0);
		}
		buffer[n] = '\0';
		if (n > 0)
			storage = ft_strjoin_gnl(storage, buffer);
	}
	free(buffer);
	return (storage);
}

char	*get_next_line(int fd)
{
	static char	*storage;
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	storage = ft_read_buff(fd, storage);
	if (!storage)
		return (NULL);
	line = ft_buff_line(storage);
	storage = ft_remove_line(storage, line);
	return (line);
}

/* int main()
{
    int fd;
    char path[] = "./read_error.txt";
    fd = open(path, O_RDONLY); // Open file for reading only.
	printf("%s\n", get_next_line(fd));
    printf("%s\n", get_next_line(fd));
    printf("%s\n", get_next_line(fd));
    printf("%s\n", get_next_line(fd));
    close(fd);
} */