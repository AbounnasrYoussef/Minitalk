/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yabounna <yabounna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/02 08:53:44 by yabounna          #+#    #+#             */
/*   Updated: 2024/12/07 14:52:52 by yabounna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdarg.h>

int		ft_putstr(char *s);
int		ft_putchar(char c);
int		ft_putnbr(int n);
char	*ft_strchr(const char *s, int c);
int		cherche_indicateur(char c, va_list args);
int		ft_putnbr_unsigned(unsigned int n);
int		ft_putnbr_hex(unsigned int n);
int		ft_putpointer(unsigned long ptr);
int		ft_putnbr_hex_mj(unsigned int n);
int		ft_printf(const char *format, ...);
int		ft_putnbr_addr(unsigned long n);

#endif
