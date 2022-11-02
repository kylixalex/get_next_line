#include <stdlib.h>

int	gnl_indexof(char *s, char c)
{
	int	i;

	i = 0;
	if (s == NULL)
		return (-1);
	while (s[i] != c)
	{
		if (s[i] == '\0')
			return (-1);
		i++;
	}
	return (i);
}

char	*gnl_strjoin(char *line, int *linelength, const char buf[BUFFER_SIZE + 2])
{
	char	*newline;
	int	i;

	newline = malloc(*linelength + BUFFER_SIZE + 2);
	i = 0;
	if (!newline)
	{
		free(line);
		return (NULL);
	}
	while (i < *linelength)
	{
		newline[i] = line[i];
		i++;
	}
	while (buf[i - *linelength] != '\0')
	{
		newline[i] = buf[i - *linelength];
		if (newline[i] == '\n')
		{
			i++;
			break;
		}
		i++;
	}
	newline[i] = '\0';
	*linelength = i;
	free(line);
	return (newline);
}

void	gnl_cleanbuf(char buf[BUFFER_SIZE + 2])
{
	int	i;
	int	j;

	i = gnl_indexof(buf, '\n') + 1;
	j = 0;
	if (i == 0)
	{
		i = 0;
		while (i < BUFFER_SIZE)
		{
			buf[i] = '\0';
			i++;
		}
	}
	else
	{
		while (i < BUFFER_SIZE)
		{
			buf[j] = buf[i];
			i++;
			j++;
		}
		while (j < BUFFER_SIZE)
		{
			buf[j] = '\0';
			j++;
		}
	}
}
