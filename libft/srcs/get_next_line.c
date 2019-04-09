#include "get_next_line.h"
#include <stdio.h>

int	get_next_line(const int fd, char **line)
{
	static char	*str;
	int		ret;
	char		*tmp;
	char		buf[BUFF_SIZE + 1];
	unsigned int	len;

	len = 0;
	if (fd < 0)
		return (-1);
	while ((ret = read(fd, buf, BUFF_SIZE)) > 0)
	{
		buf[ret] = '\0';
		if (!str)
			str = ft_strnew(1);
		tmp = ft_strjoin(str, buf);
		free(str);
		str = ft_strdup(tmp);
		if (ft_strchr(str, '\n'))
		{
		//	ft_strchrsr(str, '\n', '\0');
			break ;
		}
	}
	free(tmp);
	if (ret < 0)
	{
		ft_putstr("Error ret < 0\n");
		return (-1);
	}
	else if (ret == 0 && !str)
	{
		return (0);
	}
	else
	{
		while (str && str[len] != '\n')
			len++;
		if (str[len])
		{
			*line = ft_strsub(str, 0, len);
			tmp = ft_strdup(&str[len + 1]);
			free(str);
			str = tmp;
		}
		else
		{
			if (ret == BUFF_SIZE)
				return (get_next_line(fd, line));
			*line = ft_strdup(str);
			ft_strdel(&str);
		}
		
		return (1);
	}
}

int	main(int argc, char **argv)
{
	int	fd;
	char	*line;
	int	i;

	i = 0;
	if (argc != 2)
	{
		ft_putstr("Too many or too few argument!");
		return (-1);
	}
	fd = open(argv[1], O_RDONLY);
	if (fd == -1)
	{
		ft_putstr("open() error");
		return (1);
	}
	while (i++ < 2)
	{
		if (get_next_line(fd, &line) > 0)
		{
			ft_putstr("This is next line: ");
			ft_putstr(line);
		}
	}
	if (close(fd) == -1)
	{
		ft_putstr("close() error");
			return (1);
	}
	return (0);
}
