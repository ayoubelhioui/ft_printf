/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-hiou <ael-hiou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/28 20:40:46 by ael-hiou          #+#    #+#             */
/*   Updated: 2021/11/30 11:20:44 by ael-hiou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putchar(int *count, char c)
{
	write(1, &c, 1);
	*count += 1;
}

void	ft_putnbr_unsigned(unsigned int n, int *count)
{
	int		currentdigit;

	currentdigit = 0;
	if (n >= 10)
	{
		ft_putnbr_unsigned(n / 10, count);
		currentdigit = (n % 10) + 48;
		ft_putchar(count, currentdigit);
	}
	else
	{
		currentdigit = n + 48;
		ft_putchar(count, currentdigit);
	}
}
