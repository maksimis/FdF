/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmichael <cmichael@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/29 20:00:44 by cmichael          #+#    #+#             */
/*   Updated: 2022/01/04 13:55:06 by cmichael         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"
#include "get_next_line.h"

#ifdef BUFFER_SIZE
#else
# define BUFFER_SIZE	42
#endif

void	ft_strclr(char *s)
{
	if (s)
	{
		while (*s)
		{
			*s = '\0';
			s++;
		}
	}
}

void	my_free(char **string)
{
	if (*string)
	{
		free(*string);
		*string = NULL;
	}
}

char	*check_last_string(char *last_string, char **line)
{
	char	*new_start;

	new_start = NULL;
	if (last_string)
	{
		new_start = ft_strchr(last_string, '\n');
		if (new_start)
		{
			*new_start = '\0';
			*line = ft_strdup2(last_string, 1);
			ft_strcpy(last_string, ++new_start);
		}
		else
		{
			*line = ft_strdup2(last_string, 0);
			ft_strclr(last_string);
		}
	}
	else
		*line = NULL;
	return (new_start);
}

void	get_next_line_ut(char *buffer, char **last_string,
			char **new_start, char **result)
{
	char	*tmp_string;
	int		add_enter;

	add_enter = 0;
	*new_start = ft_strchr(buffer, '\n');
	if (*new_start)
	{
		*(*new_start) = '\0';
		(*new_start)++;
		if (*(*new_start))
		{
			my_free(last_string);
			*last_string = ft_strdup2(*new_start, 0);
		}
		add_enter = 1;
	}
	if (*result)
	{
		tmp_string = *result;
		*result = ft_strjoin2(*result, buffer, add_enter);
		free(tmp_string);
	}
	else
		*result = ft_strdup2(buffer, add_enter);
}

char	*get_next_line(int fd)
{
	char		buffer[BUFFER_SIZE + 1];
	static char	*last_string;
	char		*new_start;
	size_t		readed;
	char		*result;

	new_start = check_last_string(last_string, &result);
	if (!new_start)
		readed = read(fd, buffer, BUFFER_SIZE);
	while (!new_start && readed)
	{
		if (BUFFER_SIZE < 0 || readed > BUFFER_SIZE)
			return (NULL);
		buffer[readed] = '\0';
		get_next_line_ut(buffer, &last_string, &new_start, &result);
		if (!new_start)
			readed = read(fd, buffer, BUFFER_SIZE);
	}
	if (result && ft_strlen(result) == 0)
	{
		free(result);
		my_free(&last_string);
		return (NULL);
	}
	return (result);
}
