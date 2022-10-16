/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_xtoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssukwatt <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/16 20:15:04 by ssukwatt          #+#    #+#             */
/*   Updated: 2022/10/16 21:22:11 by ssukwatt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	assign_str_xtoa(char *str_num, unsigned int n, long len, char type)
{
	unsigned int	temp;
	char			*hex;

	if (type == 'x')
		hex = "0123456789abcdef";
	else if (type == 'X')
		hex = "0123456789ABCDEF";
	temp = n;
	while (temp != 0)
	{
		str_num[len--] = hex[temp % 16];
		temp /= 16;
	}
}

char	*ft_xtoa(unsigned int n, char type)
{
	unsigned int	temp;
	long			len;
	char			*str_num;

	len = 0;
	temp = n;
	if (temp <= 0)
		len++;
	while (temp != 0)
	{
		temp /= 16;
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
	assign_str_xtoa(str_num, n, len, type);
	return (str_num);
}
