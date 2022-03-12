/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmichael <cmichael@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/16 15:25:55 by cmichael          #+#    #+#             */
/*   Updated: 2021/10/21 13:21:53 by cmichael         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

char	*return_if_zero(void)
{
	char	*result;

	result = malloc(2 * sizeof(char));
	result[0] = '0';
	result[1] = '\0';
	return (result);
}

int	count_length(int n)
{
	int		length;

	length = 0;
	if (n < 0)
		length++;
	while (n != 0)
	{
		n = n / 10;
		length++;
	}
	return (length);
}

char	*my_itoa(int length, int minus, int n)
{
	char	*result;
	int		buff;

	result = malloc((length + 1) * sizeof(char));
	if (!result)
		return ((void *)0);
	buff = length;
	if (n == -2147483648)
	{
		buff--;
		result[buff] = '8';
		n = -214748364;
	}
	if (minus)
		n = -n;
	while (n > 0)
	{
		buff--;
		result[buff] = n % 10 + '0';
		n = n / 10;
	}
	if (minus)
		result[0] = '-';
	result[length] = '\0';
	return (result);
}

char	*ft_itoa(int n)
{
	char	*result;
	int		length;
	int		minus;

	if (n == 0)
		return (return_if_zero());
	minus = 0;
	length = count_length(n);
	if (n < 0)
		minus = 1;
	result = my_itoa(length, minus, n);
	return (result);
}
