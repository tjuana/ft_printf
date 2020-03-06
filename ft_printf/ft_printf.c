/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjuana <tjuana@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/22 16:16:07 by ccriston          #+#    #+#             */
/*   Updated: 2020/03/06 17:56:57 by tjuana           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

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

