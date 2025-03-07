#ifndef FT_PRINTF_H
# define FT_PRINTF_H


# include <unistd.h>
# include <stdio.h>
# include <stdarg.h>
# include <limits.h>

int	ft_putchar(int c);
int	ft_printf(const char *format, ...);
int	ft_putstr(char *s);
int	ft_putnbr(int nb);
#endif 