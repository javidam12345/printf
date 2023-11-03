/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaragone <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/27 17:55:19 by jaragone          #+#    #+#             */
/*   Updated: 2023/10/27 17:55:20 by jaragone         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printf(const char *format, ...)
{
	int		num_of_characters;
	va_list	arg_ptr;

	num_of_characters = 0;
	va_start(arg_ptr, format);
	analyze_string(format, &arg_ptr, &num_of_characters);
	va_end(arg_ptr);
	return (num_of_characters);
}

void	analyze_string(const char *format, va_list *arg_ptr,
		int *num_of_characters)
{
	while (*format != '\0')
	{
		if (*format == '%')
		{
			if (percentage_switcher(++format, arg_ptr, num_of_characters) == -1)
			{
				*num_of_characters = -1;
				return ;
			}
		}
		else
		{
			if (write(1, format, 1) == -1)
			{
				*num_of_characters = -1;
				return ;
			}
			(*num_of_characters)++;
		}
		format++;
	}
}

int	percentage_switcher(const char *character, va_list *arg_ptr,
		int *num_of_characters)
{
	if ((*character == 'd') || (*character == 'i'))
		return (read_number(arg_ptr, num_of_characters));
	else if (*character == 's')
		return (print_string(arg_ptr, num_of_characters));
	else if (*character == 'p')
		return (print_memory(arg_ptr, num_of_characters));
	else if (*character == 'c')
		return (print_character(arg_ptr, num_of_characters));
	else if (*character == 'u')
		return (read_number_u(va_arg(*arg_ptr, unsigned int),
				num_of_characters));
	else if (*character == 'x')
		return (print_hex((unsigned long long)va_arg(*arg_ptr, unsigned int), 0,
				num_of_characters));
	else if (*character == 'X')
		return (print_hex((unsigned long long)va_arg(*arg_ptr, unsigned int), 1,
				num_of_characters));
	else if (*character == '%')
		return (print_percentage(num_of_characters));
	else
		return (print_rest(character, num_of_characters));
}
