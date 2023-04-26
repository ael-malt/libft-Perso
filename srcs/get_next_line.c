/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-malt <ael-malt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/06 13:27:19 by ael-malt          #+#    #+#             */
/*   Updated: 2023/04/26 13:19:15 by ael-malt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/get_next_line.h"

static int	check_line(char *buf)
{
	int	i;
	int	is_new_line;
	int	j;

	i = 0;
	j = 0;
	is_new_line = 0;
	while (buf[i])
	{
		if (is_new_line)
			buf[j++] = buf[i];
		if (buf[i] == '\n')
			is_new_line = 1;
		buf[i++] = '\0';
	}
	return (is_new_line);
}

char	*get_next_line(int fd)
{
	static char		buf[BUFFER_SIZE + 1];
	char			*ret;
	int				i;

	i = 0;
	if (BUFFER_SIZE < 1 || read(fd, 0, 0) < 0)
	{
		while (buf[i])
			buf[i++] = 0;
		return (NULL);
	}
	ret = NULL;
	while (buf[0] || read(fd, buf, BUFFER_SIZE) > 0)
	{
		ret = ft_gnl_strjoin(ret, buf);
		if (check_line(buf))
			break ;
	}
	return (ret);
}

// int	main(void)
// {
// 	int		test;
// 	char	*line;

// 	test = open("test", O_RDONLY | O_CREAT);
// 	line = (get_next_line(test));
// 	printf("%s", line);
// 	while (line != 0)
// 	{
// 		line = (get_next_line(test));
// 		printf("%s", line);
// 		free(line);
// 	}
// }
