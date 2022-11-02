/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyalexan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/02 21:52:25 by kyalexan          #+#    #+#             */
/*   Updated: 2022/11/02 22:05:34 by kyalexan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

static char	*returningfree(char *tofree, char *ret)
{
	free(tofree);
	return (ret);
}

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

char	*gnl_strjoin(char *line, int *linelength,
		const char buf[BUFFER_SIZE + 2])
{
	char	*newline;
	int		i;

	newline = malloc(*linelength + BUFFER_SIZE + 2);
	i = 0;
	if (!newline)
		return (returningfree(line, NULL));
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
			break ;
		}
		i++;
	}
	newline[i] = '\0';
	*linelength = i;
	return (returningfree(line, newline));
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
			buf[j++] = buf[i++];
		while (j < BUFFER_SIZE)
			buf[j++] = '\0';
	}
}
