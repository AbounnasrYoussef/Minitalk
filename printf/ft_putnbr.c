/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yabounna <yabounna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/03 17:46:59 by yabounna          #+#    #+#             */
/*   Updated: 2024/12/05 12:05:16 by yabounna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putnbr(int n)
{
	long	nb;
	int		count;

	nb = n;
	count = 0;
	if (nb < 0)
	{
		nb = -nb;
		count += write (1, "-", 1);
	}
	if (nb > 9)
	{
		count += ft_putnbr(nb / 10);
		count += ft_putchar((nb % 10) + '0');
	}
	else
	{
		count += ft_putchar(nb + '0');
	}
	return (count);
}
