/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                        :+:      :+:    :+:  */
/*                                                    +:+ +:+         +:+     */
/*   By: cmichael <cmichael@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/16 15:25:55 by cmichael          #+#    #+#             */
/*   Updated: 2021/10/23 13:31:18 by cmichael         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

void	*ft_memmove(void *dst, const void *src,
						size_t n)
{
	size_t	i;
	char	*s;
	char	*d;
	int		fromup;

	if (!dst && !src)
		return (NULL);
	i = 0;
	d = ((char *)dst);
	s = ((char *)src);
	fromup = 0;
	if (s < d)
		fromup = 1;
	while (i < n)
	{
		if (fromup)
			d[n - i - 1] = s[n - i - 1];
		else
			d[i] = s[i];
		i++;
	}
	return (dst);
}
