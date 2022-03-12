/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmichael <cmichael@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/16 15:25:55 by cmichael          #+#    #+#             */
/*   Updated: 2022/01/13 11:15:40 by cmichael         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	int		length;
	int		iter;
	char	*result;

	if (!s1 || !s2)
		return (NULL);
	length = ft_strlen((char *)s1) + ft_strlen((char *)s2);
	iter = 0;
	result = malloc(sizeof(char) * (length + 1));
	if (!result)
		return (NULL);
	while (*s1)
	{
		result[iter] = *s1;
		iter++;
		s1++;
	}
	while (*s2)
	{
		result[iter] = *s2;
		iter++;
		s2++;
	}
	result[iter] = '\0';
	return (result);
}
