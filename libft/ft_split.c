/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmichael <cmichael@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/16 15:25:55 by cmichael          #+#    #+#             */
/*   Updated: 2022/01/21 12:34:10 by cmichael         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

size_t	count_len(char const *s, char c)
{
	size_t	result;
	int		check;

	check = 1;
	result = 0;
	while (*s)
	{
		if (*s != c && check == 1)
		{
			result++;
			check = 0;
		}
		if (*s == c)
			check = 1;
		s++;
	}
	return (result);
}

int	*count_lengths(char const *s, char c, size_t len)
{
	int	*result;
	int	cur;
	int	i;

	cur = 0;
	result = malloc(sizeof(int) * (len + 1));
	if (!result)
		return (NULL);
	while (*s)
	{
		i = 0;
		while (*s && *s == c)
			s++;
		while (*s && *s != c)
		{
			s++;
			i++;
		}
		result[cur] = i;
		cur++;
	}
	return (result);
}

void	free_all(char	**result, size_t cur)
{
	size_t	i;

	i = 0;
	while (i < cur)
	{
		free(result[cur]);
		i++;
	}
	free(result);
}

char	**fill_result(const char *s, char c,
					size_t length, const int *lengths)
{
	size_t	cur;
	char	**result;

	cur = 0;
	result = malloc(sizeof(char *) * (length + 1));
	if (!result)
		return (NULL);
	while (*s && cur < length)
	{
		while (*s && *s == c)
			s++;
		result[cur] = ft_substr(s, 0, lengths[cur]);
		if (!result[cur])
		{
			free_all(result, cur);
			return (NULL);
		}
		while (*s && *s != c)
			s++;
		cur++;
		if (*s)
			s++;
	}
	return (result);
}

char	**ft_split(char const *s, char c)
{
	char		**result;
	size_t		length;
	int			*lengths;

	if (!s)
		return (NULL);
	length = count_len(s, c);
	lengths = count_lengths(s, c, length);
	if (!lengths)
		return (NULL);
	result = fill_result(s, c, length, lengths);
	free(lengths);
	if (!result)
		return (NULL);
	result[length] = (void *)0;
	return (result);
}
