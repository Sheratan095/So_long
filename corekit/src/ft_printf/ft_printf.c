/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maceccar <maceccar@student.42firenze.it>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/30 11:22:43 by maceccar          #+#    #+#             */
/*   Updated: 2024/05/03 00:47:17 by maceccar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	handle_specifier(char specifier, va_list ap)
{
	if (specifier == 'i' || specifier == 'd')
		return (ft_putnbr(va_arg(ap, int)));
	else if (specifier == 'c')
		return (ft_putchar((va_arg(ap, int))));
	else if (specifier == 's')
		return (ft_putstr((va_arg(ap, char *))));
	else if (specifier == 'p')
		return (ft_putptr(va_arg(ap, long unsigned int), "0123456789abcdef"));
	else if (specifier == 'x')
		return (ft_putbase(va_arg(ap, unsigned int), "0123456789abcdef"));
	else if (specifier == 'X')
		return (ft_putbase(va_arg(ap, unsigned int), "0123456789ABCDEF"));
	else if (specifier == '%')
		return (ft_putchar('%'));
	else if (specifier == 'u')
		return (ft_unsignedputnbr(va_arg(ap, int)));
	return (ft_putchar(specifier));
}

static int	print_format(char format, va_list ap, int *is_spec)
{
	if (ft_is_in(format, "csdiupxX%"))
	{
		*is_spec = 0;
		return (handle_specifier(format, ap));
	}
	return (0);
}

int	ft_printf(const char *format, ...)
{
	int		i;
	int		inside_specifier;
	int		*ptr;
	va_list	ap;

	i = 0;
	inside_specifier = 0;
	ptr = &inside_specifier;
	va_start(ap, format);
	while (*format)
	{
		if (inside_specifier == 0 && *format == '%')
			inside_specifier = 1;
		else if (inside_specifier == 1)
			i += print_format(*format, ap, ptr);
		else
			i += ft_putchar(*format);
		format++;
	}
	return (i);
}
