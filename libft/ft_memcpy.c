/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmichael <cmichael@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/16 15:25:55 by cmichael          #+#    #+#             */
/*   Updated: 2021/10/23 13:31:18 by cmichael         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

void	*ft_memcpy(void *dst, const void *src,
						size_t n)
{
	size_t	i;
	char	*t;

	if (!dst && !src)
		return (NULL);
	i = 0;
	t = ((char *)dst);
	while (i < n)
	{
		*t = ((char *)src)[i];
		t++;
		i++;
	}
	return (dst);
}
