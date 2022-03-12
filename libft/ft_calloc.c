/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmichael <cmichael@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/16 15:25:55 by cmichael          #+#    #+#             */
/*   Updated: 2021/10/21 09:05:14 by cmichael         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	void	*result;
	int		i;
	int		n;
	char	*tmp;

	result = malloc(size * count);
	if (!result)
		return (NULL);
	i = 0;
	n = size * count / sizeof(char);
	tmp = (char *)result;
	while (i != n)
	{
		*tmp = 0;
		tmp++;
		i++;
	}
	return (result);
}
