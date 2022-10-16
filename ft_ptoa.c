/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ptoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssukwatt <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/16 20:15:04 by ssukwatt          #+#    #+#             */
/*   Updated: 2022/10/16 22:50:44 by ssukwatt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*strjoin_free(char *str1, char *str2);

static char	*assign_str_ptoa(char *str_num, size_t n, long len)
{
	size_t	temp;
	char	*hex;

	hex = "0123456789abcdef";
	temp = n;
	while (temp != 0)
	{
		str_num[len--] = hex[temp % 16];
		temp /= 16;
	}
	return (strjoin_free("0x", str_num));
}

char	*strjoin_free(char *str1, char *str2)
{
	char	*str;

	str = ft_strjoin(str1, str2);
	if (str == NULL)
		return (NULL);
	if (str2)
		free(str2);
	return (str);
}

char	*ft_ptoa(size_t n)
{
	size_t	temp;
	long	len;
	char	*str_num;

	len = 0;
	temp = n;
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
	str_num = assign_str_ptoa(str_num, n, len);
	return (str_num);
}
