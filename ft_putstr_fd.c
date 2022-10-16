/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssukwatt <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/16 19:21:43 by ssukwatt          #+#    #+#             */
/*   Updated: 2022/10/16 22:41:16 by ssukwatt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

size_t	ft_putstr_fd(char *s, int fd, char type)
{
	if (s == NULL && type == 's')
		return (write(fd, "(null)", 6));
	else if (s == NULL && type == 'p')
		return (write(fd, "(nil)", 5));
	else if (s == NULL && type == 'c')
		return (write(fd, "\0", 1));
	else if (s == NULL)
		return (0);
	return (write(fd, s, ft_strlen(s)));
}
