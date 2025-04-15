/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_hex.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yabounna <yabounna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/03 18:00:51 by yabounna          #+#    #+#             */
/*   Updated: 2024/12/05 12:11:26 by yabounna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putnbr_hex(unsigned int n)
{
	char	*hex_digits;
	int		count;

	count = 0;
	hex_digits = "0123456789abcdef";
	if (n > 15)
	{
		count += ft_putnbr_hex(n / 16);
	}
	count += ft_putchar(hex_digits[n % 16]);
	return (count);
}

int	ft_putnbr_addr(unsigned long n)
{
	char	*hex_digits;
	int		count;

	count = 0;
	hex_digits = "0123456789abcdef";
	if (n > 15)
		count += ft_putnbr_addr(n / 16);
	count += ft_putchar(hex_digits[n % 16]);
	return (count);
}
