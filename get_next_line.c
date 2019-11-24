/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pshock <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/28 16:28:02 by pshock            #+#    #+#             */
/*   Updated: 2019/10/12 13:10:56 by pshock           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "get_next_line.h"

static int	ft_fill(int fd, char **line, char **stack)
{
	int		len;
	char	*tmp;

	len = 0;
	if (!stack[fd])
		return (0);
	while (stack[fd][len] != '\n' && stack[fd][len])
		len++;
	if (stack[fd][len] == '\n')
	{
		*line = ft_strsub(stack[fd], 0, len);
		tmp = ft_strdup(stack[fd] + len + 1);
		free(stack[fd]);
		stack[fd] = tmp;
		return (1);
	}
	else if (!stack[fd][len] && len != 0)
	{
		*line = ft_strdup(stack[fd]);
		ft_strdel(&stack[fd]);
		return (1);
	}
	return (0);
}

int			get_next_line(const int fd, char **line)
{
	static char *stack[10240];
	char		buff[BUFF_SIZE + 1];
	char		*tmp;
	int			nbr;

	if (fd > 10240 || fd < 0)
		return (-1);
	while ((nbr = read(fd, buff, BUFF_SIZE)) > 0)
	{
		buff[nbr] = '\0';
		if (stack[fd] == NULL)
			stack[fd] = ft_strnew(1);
		tmp = ft_strjoin(stack[fd], buff);
		free(stack[fd]);
		stack[fd] = tmp;
		if (ft_strchr(stack[fd], '\n'))
			break ;
	}
	if (nbr < 0)
		return (-1);
	return (ft_fill(fd, line, stack));
}
