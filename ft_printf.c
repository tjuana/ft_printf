/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccriston <ccriston@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/22 16:16:07 by ccriston          #+#    #+#             */
/*   Updated: 2020/02/24 14:47:02 by ccriston         ###   ########.fr       */
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

int	ft_printf(const char *restrict format, ...)
{
	va_list	vlist;
	int		i;
	int		count;
	char	*str;

	va_start(vlist, format);
	i = 0;
	count = 0;
	while (format[i] != '\0')
	{
		if  (format[i] == '%')
			if (format[i+1] == '%')
			{
				vlist ;
				count++;
			}
		i++;
	}
	va_end(vlist);
	return (0);
}

int	main(int ac, char **av)
{
	ft_printf("AAAAAAA\n%%");
	//printf("Hello! %+10s\n %#x %#X %010d %010d", "Elena", 1234, 1234, 1, -123567899);
	return (0);
}
