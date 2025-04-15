/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_hex_MJ.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yabounna <yabounna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/04 10:11:04 by yabounna          #+#    #+#             */
/*   Updated: 2024/12/05 12:18:40 by yabounna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putnbr_hex_mj(unsigned int n)
{
	char	*hex_digits;
	int		count;

	count = 0;
	hex_digits = "0123456789ABCDEF";
	if (n > 15)
	{
		count += ft_putnbr_hex_mj(n / 16);
	}
	count += ft_putchar(hex_digits[n % 16]);
	return (count);
}
