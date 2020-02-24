/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccriston <ccriston@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/22 16:16:07 by ccriston          #+#    #+#             */
/*   Updated: 2020/02/24 16:35:31 by ccriston         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdarg.h>
#include <stdlib.h>
#include <unistd.h>
#include "libft/libft.h"





int		parse_percent(char **format)
{
	int		i;
	char	let;

	i = 0;
	let = (*format)[i];
	while (ft_strchr("0 -123456789.hfdl", let) != NULL && *format != '\0')
		i++;

		
	return (i);
}

int	ft_printf(const char *restrict format, ...)
{
	va_list	arg;
	int		char_printed;
	int		count;
	char	*str;

	va_start(arg, format);
	count = 0;
	str = (char *)format;
	while (*str != '\0')
	{
		if (*str == '%' && (*str + 1) == '%')
		{
			str++;
			write(1, "%", 1);
			char_printed++;
		}
		else if (*str == '%' && (*str + 1) != '%')
			char_printed += parse_percent(&str);
		else
		{
			write(1, &(*str), 1);
			char_printed++;
		}
		if (*str != '\0')
			str++;
	}
	va_end(arg);
	return (char_printed);
}

int	main(int ac, char **av)
{
	ft_printf("AAAAAAA\n%%");
	//printf("Hello! %+10s\n %#x %#X %010d %010d", "Elena", 1234, 1234, 1, -123567899);
	return (0);
}
