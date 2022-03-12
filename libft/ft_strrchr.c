/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                         :+:      :+:    :+: */
/*                                                    +:+ +:+         +:+     */
/*   By: cmichael <cmichael@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/16 15:25:55 by cmichael          #+#    #+#             */
/*   Updated: 2021/10/23 17:39:45 by cmichael         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	char			*buff;
	unsigned int	counter;

	counter = 0;
	buff = (char *)s;
	while (*buff)
	{
		buff++;
		counter++;
	}
	while (counter && *buff != (unsigned char)c)
	{
		counter--;
		buff--;
	}
	if ((unsigned char)c != *s && *buff == *s)
		return (NULL);
	return (buff);
}
