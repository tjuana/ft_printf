
#ifndef FT_PRINTF_H
# define FT_PRINTF_H

#include <stdio.h>
#include <stdarg.h>
#include <stdlib.h>
#include <unistd.h>
#include "../libft/includes/libft.h"

int     ft_printf(const char *format, ...);
int		parse_percent(char **format, va_list *arg);

#endif