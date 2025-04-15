/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putpointer.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yabounna <yabounna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/04 09:22:07 by yabounna          #+#    #+#             */
/*   Updated: 2024/12/05 12:23:29 by yabounna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putpointer(unsigned long ptr)
{
	int	count;

	count = 0;
	count += ft_putstr("0x");
	count += ft_putnbr_addr(ptr);
	return (count);
}
