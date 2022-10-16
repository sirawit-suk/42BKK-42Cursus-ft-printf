/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssukwatt <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/16 19:51:30 by ssukwatt          #+#    #+#             */
/*   Updated: 2022/10/16 19:51:31 by ssukwatt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	assign_str_itoa(char *str_num, int n, long len)
{
	long	temp;

	temp = n;
	if (n < 0)
		temp *= -1;
	while (temp != 0)
	{
		str_num[len--] = (temp % 10) + '0';
		temp /= 10;
	}
	if (len == 0)
		str_num[len] = '-';
}

char	*ft_itoa(int n)
{
	long	temp;
	long	len;
	char	*str_num;

	len = 0;
	temp = n;
	if (temp <= 0)
		len++;
	while (temp != 0)
	{
		temp /= 10;
		len++;
	}
	str_num = ft_calloc(len + 1, 1);
	if (str_num == NULL)
		return (NULL);
	len--;
	if (n == 0)
	{
		str_num[len] = '0';
		return (str_num);
	}
	assign_str_itoa(str_num, n, len);
	return (str_num);
}
