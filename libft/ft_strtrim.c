/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmichael <cmichael@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/16 15:25:55 by cmichael          #+#    #+#             */
/*   Updated: 2022/01/21 12:08:49 by cmichael         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	trim_left;
	size_t	trim_right;
	size_t	length;
	char	*result;

	if (!s1 || !set)
		return (0);
	trim_left = 0;
	trim_right = 0;
	length = ft_strlen((char *)s1);
	while (s1[trim_left] && ft_strchr(set, s1[trim_left]))
		trim_left++;
	while (length > 0 && ft_strchr(set, s1[length - 1]))
	{
		trim_right++;
		length --;
	}
	if (length < trim_left)
		length = 0;
	else
		length = length - trim_left;
	result = ft_substr(s1, trim_left, length);
	return (result);
}
