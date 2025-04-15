/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cherche_indicateur.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yabounna <yabounna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/03 13:54:17 by yabounna          #+#    #+#             */
/*   Updated: 2024/12/07 10:52:26 by yabounna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	cherche_indicateur(char format, va_list gere_liste)
{
	int	count;

	count = 0;
	if (format == 'c')
		count += ft_putchar(va_arg(gere_liste, int));
	else if (format == 's')
		count += ft_putstr(va_arg(gere_liste, char *));
	else if (format == 'd' || format == 'i')
		count += ft_putnbr(va_arg(gere_liste, int));
	else if (format == '%')
		count += write(1, "%", 1);
	else if (format == 'u')
		count += ft_putnbr_unsigned(va_arg(gere_liste, int));
	else if (format == 'x')
		count += ft_putnbr_hex(va_arg(gere_liste, int));
	else if (format == 'p')
		count += ft_putpointer(va_arg(gere_liste, unsigned long));
	else if (format == 'X')
		count += ft_putnbr_hex_mj(va_arg(gere_liste, unsigned long));
	return (count);
}
