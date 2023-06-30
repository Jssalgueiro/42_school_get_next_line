#include "get_next_line.h"

static char	*remove_line(char *fd_buffer, size_t line_len)
{
	char	*new_fd_buffer;
	size_t	len;

	len = ft_strlen(fd_buffer) - line_len;
	new_fd_buffer = ft_substr(fd_buffer, line_len, len);
	free(fd_buffer);
	if (!*new_fd_buffer)
	{
		free(new_fd_buffer);
		return (0);
	}
	return (new_fd_buffer);
}

static char	*get_line(char *fd_buffer)
{
	int		i;
	char	*line;

	i = 0;
	while (fd_buffer[i] && fd_buffer[i] != '\n')
		i++;
	if (fd_buffer[i] == '\n')
		i++;
	line = ft_substr(fd_buffer, 0, i);
	if (!*line)
	{
		free(line);
		return (0);
	}
	return (line);
}

static char	*merge_to_fd_buffer(char *fd_buffer, char *buffer)
{
	char	*fd_buffer_temp;

	if (!fd_buffer)
	{
		fd_buffer = malloc(1);
		fd_buffer[0] = '\0';
	}
	fd_buffer_temp = fd_buffer;
	fd_buffer = ft_strjoin(fd_buffer, buffer);
	free(fd_buffer_temp);
	return (fd_buffer);
}

static char	*read_file(int fd, char *fd_buffer)
{
	char	*buffer;
	ssize_t	fd_read;

	buffer = malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (!buffer)
		return (0);
	fd_read = 1;
	while (!ft_strchr(fd_buffer, '\n') && fd_read)
	{
		fd_read = read(fd, buffer, BUFFER_SIZE);
		if (fd_read == -1)
		{
			free(fd_buffer);
			free(buffer);
			return (0);
		}
		buffer[fd_read] = '\0';
		fd_buffer = merge_to_fd_buffer(fd_buffer, buffer);
	}
	free(buffer);
	return (fd_buffer);
}

char	*get_next_line(int fd)
{
	static char	*fd_buffer;
	char		*line;

	if (fd < 0 || BUFFER_SIZE < 1)
		return (0);
	fd_buffer = read_file(fd, fd_buffer);
	if (!fd_buffer)
		return (0);
	line = get_line(fd_buffer);
	fd_buffer = remove_line(fd_buffer, ft_strlen(line));
	return (line);
}

int	main(void)
{
	int fd;
	char path[] = "./read_error.txt";
	fd = open(path, O_RDONLY); // Open file for reading only.
	printf("%s\n", get_next_line(fd));
	/* printf("%s\n", get_next_line(fd));
	printf("%s\n", get_next_line(fd));
	printf("%s\n", get_next_line(fd));
	printf("%s\n", get_next_line(fd)); */
	close(fd);
}