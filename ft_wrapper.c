/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_wrapper.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssukwatt <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/16 22:48:22 by ssukwatt          #+#    #+#             */
/*   Updated: 2022/10/16 22:49:53 by ssukwatt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*u_wrapper(unsigned int number)
{
	char	*str;

	str = ft_utoa(number);
	if (str == NULL)
		return (NULL);
	return (str);
}

char	*x_wrapper(unsigned int number, char type)
{
	char	*str;

	str = ft_xtoa(number, type);
	if (str == NULL)
		return (NULL);
	return (str);
}

char	*p_wrapper(size_t number)
{
	char	*str;

	if (number == 0)
		return (NULL);
	str = ft_ptoa(number);
	if (str == NULL)
		return (NULL);
	return (str);
}
