/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmichael <cmichael@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/16 15:25:55 by cmichael          #+#    #+#             */
/*   Updated: 2022/01/13 11:18:40 by cmichael         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char			*result;
	size_t			current;
	long			max;
	unsigned int	s_len;

	if (!s)
		return (0);
	current = 0;
	s_len = ft_strlen((char *)s);
	max = (long)s_len - (long)start;
	if (max < 0)
		max = 0;
	if ((size_t)max < len)
		len = (size_t)max;
	result = malloc(sizeof(char) * (len + 1));
	if (!result)
		return (NULL);
	while ((current < len)
		&& (current + start < s_len))
	{
		result[current] = s[current + start];
		current++;
	}
	result[current] = '\0';
	return (result);
}
