/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmichael <cmichael@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/16 15:25:55 by cmichael          #+#    #+#             */
/*   Updated: 2021/10/20 08:56:18 by cmichael         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

int	is_probel(char c)
{
	return (c == '\t' || c == '\n' || c == '\r'
		|| c == '\v' || c == '\f' || c == ' ');
}

int	ft_atoi(const char *str)
{
	unsigned long	result;
	long			minus;

	result = 0;
	minus = 1;
	while (*str != '\0' && is_probel(*str))
		str++;
	if (*str == '-')
	{
		minus = -1;
		str++;
	}
	if (*str == '+' && minus == 1)
		str++;
	while (*str >= '0' && *str <= '9' && result <= 2147483648)
	{
		result = result * 10 + *str - '0';
		str++;
	}
	if ((result > 2147483647 && minus == 1))
		return (-1);
	if (result > 2147483648)
		return (0);
	return ((int)(result * minus));
}
