#include <unistd.h>
#include "get_next_line.h"

int	gnl_indexof(char *s, char c);
char	*gnl_strjoin(char *line, int *linelength, const char buf[BUFFER_SIZE + 2]);
void	gnl_cleanbuf(char buf[BUFFER_SIZE + 2]);

char	*get_next_line(int fd)
{
	static char	buf[BUFFER_SIZE + 2];
	int	readchars;
	int	linelength;
	char	*line;

	line = NULL;
	linelength = 0;
	while (1)
	{
		if (buf[0] == '\0')
		{
			readchars = read(fd, buf, BUFFER_SIZE);
			if (readchars <= 0)
				break;
			buf[readchars + 1] = '\0';
		}
		line = gnl_strjoin(line, &linelength, buf);
		gnl_cleanbuf(buf);
		if (gnl_indexof(line, '\n') != -1 || line == NULL)
			break;
	}
	return (line);
}
