/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccriston <ccriston@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/22 16:16:07 by ccriston          #+#    #+#             */
/*   Updated: 2020/03/06 14:55:06 by ccriston         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdarg.h>
#include <stdlib.h>
#include <unistd.h>
#include "libft/libft.h"

int		parse_percent(char **format, va_list *arg)
{
	int		i;
	char	let;
	char	*str;

	i = 0;
	let = (*format)[i];
	//write(1, &arg[0], 1);
//	long long nb;
//	nb = (long long)va_arg(arg, long long);
	
	while ((str = ft_strchr("0+-123456789.hlqjzt", let)) != NULL && *format != '\0')
	{
				
		i++;
		let = (*format)[i];
	}
	
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
		if (*str == '%' && *(str + 1) == '%')
		{
			str++;
			write(1, "%", 1);
			char_printed++;
		}
		else if (*str == '%' && (*str + 1) != '%')
		{
			str++;
			count = parse_percent(&str, &arg);
			str += count;
			//printf(" %s", str);
			char_printed += count;
		}
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
	//ft_printf("AAAAAAA\n%% wpej %c" , 'q');
	ft_printf("AAAAAAA\n%% wpej %c %s $d %s %c" , 'q', "Qweq", 324, "qq", 'g');
	// printf("Hello!  %hd ", (short)12222);
	return (0);
}
