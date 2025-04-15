/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yabounna <yabounna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/02 08:49:41 by yabounna          #+#    #+#             */
/*   Updated: 2024/12/07 13:13:10 by yabounna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printf(const char *format, ...)
{
	va_list	gerer_liste;
	int		i;
	int		count;

	1 && (i = 0, count = 0);
	va_start(gerer_liste, format);
	while (format[i] != '\0')
	{
		if (format[i] != '%')
		{
			ft_putchar(format[i]);
			count++;
		}
		else if ((format[i] == '%') && (ft_strchr("cspdiuxX%", format[i + 1])))
		{
			i++;
			if (format[i] == '\0')
				break ;
			count += cherche_indicateur(format[i], gerer_liste);
		}
		i++;
	}
	return (count);
}
