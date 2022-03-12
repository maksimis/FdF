/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmichael <cmichael@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/16 15:25:55 by cmichael          #+#    #+#             */
/*   Updated: 2021/10/23 13:31:18 by cmichael         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char	*buff;
	size_t			i;

	if (n == 0)
		return (NULL);
	i = 0;
	buff = (unsigned char *)s;
	while (i < n && *buff != (unsigned char)c)
	{
		buff++;
		i++;
	}
	if (i == n)
		return (NULL);
	return (buff);
}
