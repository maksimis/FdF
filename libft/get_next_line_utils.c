/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmichael <cmichael@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/29 20:00:53 by cmichael          #+#    #+#             */
/*   Updated: 2022/01/04 13:41:37 by cmichael         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "get_next_line.h"
#include "libft.h"

char	*ft_strcpy(char *dst, const char *src)
{
	int	i;

	i = 0;
	while (src[i])
	{
		dst[i] = src[i];
		i++;
	}
	dst[i] = '\0';
	return (dst);
}

char	*ft_strdup2(char *src, int add_enter)
{
	int		i;
	int		len;
	char	*str;

	len = 0;
	while (src[len])
		len++;
	str = (char *)malloc(sizeof(*str) * (len + add_enter + 1));
	if (!str)
		return (NULL);
	i = 0;
	while (i < len)
	{
		str[i] = src[i];
		i++;
	}
	if (add_enter)
		str[i++] = '\n';
	str[i] = '\0';
	return (str);
}

char	*ft_strjoin2(char const *s1, char const *s2, int add_enter)
{
	size_t	length;
	int		iter;
	char	*result;

	length = ft_strlen(s1) + ft_strlen(s2) + add_enter;
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
	if (add_enter)
		result[iter++] = '\n';
	result[iter] = '\0';
	return (result);
}
