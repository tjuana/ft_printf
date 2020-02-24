/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccriston <ccriston@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/22 16:16:07 by ccriston          #+#    #+#             */
/*   Updated: 2020/02/24 16:07:17 by ccriston         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdarg.h>
#include <stdlib.h>
#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_putstr(char const *s)
{
	if (s)
	{
		while (*s != '\0')
		{
			ft_putchar((int)*s);
			s++;
		}
	}
}



int		parse_percent(char **format)
{
	int		i;

	i = 0;
	while (ft_strchr("0 -123456789.hfdl", (*format)[i]) && *format != '\0')
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
	while (*format != '\0')
	{
		if (*format == '%' && (*format + 1) == '%')
		{
			format++;
			write(1, "%", 1);
			char_printed++;
		}
		else if (*format == '%' && (*format + 1) != '%')
			char_printed += parse_percent(&format);
		else
		{
			write(1, &(*format), 1);
			char_printed++;
		}
		if (*format != '\0')
			format++;
	}
	va_end(arg);
	return (char_printed);
}

int	main(int ac, char **av)
{
	printf("AAAAAAA\n%%%");
	//printf("Hello! %+10s\n %#x %#X %010d %010d", "Elena", 1234, 1234, 1, -123567899);
	return (0);
}
