#include "libft.h"

int			get_next_line(const int fd, char **line)
{
	char	buff[BUFF_SIZE];
	char	*new;
	char	*temp;
	int		result;

	new = ft_strnew(0);
	while ((result = read(fd, buff, 1)) > 0)
	{
		buff[1] = 0;
		if (!ft_strcmp(buff, "\n"))
			break ;
		temp = new;
		new = ft_strjoin(new, buff);
		free(temp);
	}
	*line = ft_strdup(new);
	free(new);
	return (result);
}
