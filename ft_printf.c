/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-hiou <ael-hiou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/27 13:01:23 by ael-hiou          #+#    #+#             */
/*   Updated: 2021/11/29 22:38:53 by ael-hiou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putstr(char *str, int *count)
{
	int	i;

	if (!str)
	{
		ft_putstr("(null)", count);
		return ;
	}
	i = 0;
	while (str[i])
		ft_putchar(count, str[i++]);
}

void	ft_putnbr(int n, int *count)
{
	long	s;
	int		currentdigit;

	s = n;
	currentdigit = 0;
	if (s < 0)
	{
		s *= -1;
		ft_putchar(count, '-');
	}
	if (s >= 10)
	{
		ft_putnbr(s / 10, count);
		currentdigit = (s % 10) + 48;
		ft_putchar(count, currentdigit);
	}
	else
	{
		currentdigit = s + 48;
		ft_putchar(count, currentdigit);
	}
}

void	ft_putnbr_hex(int *count, unsigned long int n, char a)
{
	int		currentdigit;
	char	*base_v1;
	char	*base_v2;

	base_v1 = "0123456789abcdef";
	base_v2 = "0123456789ABCDEF";
	currentdigit = 0;
	if (a >= 65 && a <= 90)
		base_v1 = base_v2;
	if (n >= 16)
	{
		ft_putnbr_hex(count, n / 16, a);
		currentdigit = base_v1[n % 16];
		ft_putchar(count, currentdigit);
	}
	else
	{
		currentdigit = base_v1[n];
		ft_putchar(count, currentdigit);
	}
}

void	ft_getformat(int *count, char a, va_list lst)
{
	if (a == 'c')
		ft_putchar(count, va_arg(lst, int));
	else if (a == 's')
		ft_putstr(va_arg(lst, char *), count);
	else if (a == 'd' || a == 'i')
		ft_putnbr(va_arg(lst, int), count);
	else if (a == 'x' || a == 'X')
		ft_putnbr_hex(count, va_arg(lst, unsigned int), a);
	else if (a == 'u')
		ft_putnbr_unsigned(va_arg(lst, unsigned int), count);
	else if (a == 'p')
	{
		ft_putstr("0x", count);
		ft_putnbr_hex(count, va_arg(lst, unsigned long int), a);
	}
	else if (a == '%')
		ft_putchar(count, a);
}

int	ft_printf(const char *str, ...)
{
	va_list	lst;
	int		i;
	int		count;

	i = 0;
	count = 0;
	va_start(lst, str);
	while (str[i])
	{
		if (str[i] == '%')
		{
			i++;
			ft_getformat(&count, str[i], lst);
		}
		else
			ft_putchar(&count, str[i]);
		if (str[i] == '\0')
			break ;
		i++;
	}
	va_end(lst);
	return (count);
}
