
#ifndef FT_PRINTF_H
# define FT_PRINTF_H

#include <stdio.h>
#include <stdarg.h>
#include <stdlib.h>
#include <unistd.h>
#include "libft.h"
#include <math.h>

int     ft_printf(const char *format, ...);
int		parse_percent(char **format, va_list *arg);

typedef struct			s_pf
{
	va_list				arg;
	char				*str;
	char				*buff;
	size_t				buff_len;
	// struct s_pf_spec	spec;
}						t_pf;

#endif