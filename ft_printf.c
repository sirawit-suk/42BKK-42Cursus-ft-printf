/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssukwatt <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/16 20:55:04 by ssukwatt          #+#    #+#             */
/*   Updated: 2022/10/16 22:49:41 by ssukwatt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		check_format(const char *format, int index, int *print_size,
			va_list arguments);
char	*c_wrapper(int character);
char	*s_wrapper(char *str);
char	*d_wrapper(int number);

int	ft_printf(const char *format, ...)
{
	va_list	arguments;
	int		i;
	int		print_size;

	i = 0;
	print_size = 0;
	va_start(arguments, format);
	while (format[i] != '\0')
	{
		if (format[i] == '%')
			i += check_format(format, i + 1, &print_size, arguments);
		else
			print_size += write(1, format + i, 1);
		i++;
	}
	va_end(arguments);
	return (print_size);
}

int	check_format(const char *format, int index, int *print_size,
				va_list arguments)
{
	char	*print_str;

	if (format[index] == 'c')
		print_str = c_wrapper(va_arg(arguments, int));
	else if (format[index] == 's')
		print_str = s_wrapper(va_arg(arguments, char *));
	else if (format[index] == 'd' || format[index] == 'i')
		print_str = d_wrapper(va_arg(arguments, int));
	else if (format[index] == 'u')
		print_str = u_wrapper(va_arg(arguments, unsigned int));
	else if (format[index] == '%')
		print_str = c_wrapper('%');
	else if (format[index] == 'x' || format[index] == 'X')
		print_str = x_wrapper(va_arg(arguments, unsigned int), format[index]);
	else if (format[index] == 'p')
		print_str = p_wrapper(va_arg(arguments, size_t));
	*print_size += ft_putstr_fd(print_str, 1, format[index]);
	if (print_str)
		free(print_str);
	return (1);
}

char	*c_wrapper(int character)
{
	char	*str;

	if (character == 0)
		return (NULL);
	str = ft_calloc(2, sizeof(char));
	if (str == NULL)
		return (NULL);
	*str = character;
	return (str);
}

char	*s_wrapper(char *str_input)
{
	char	*str;

	str = ft_strdup(str_input);
	if (str == NULL)
		return (NULL);
	return (str);
}

char	*d_wrapper(int number)
{
	char	*str;

	str = ft_itoa(number);
	if (str == NULL)
		return (NULL);
	return (str);
}
