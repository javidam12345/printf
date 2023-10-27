/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_pointer.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaragone <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/27 17:56:21 by jaragone          #+#    #+#             */
/*   Updated: 2023/10/27 17:56:22 by jaragone         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	number_to_hex_buffer(unsigned long long number, char *buffer,
		int *index)
{
	char	*hex_digits;

	hex_digits = "0123456789abcdef";
	*index = 0;
	while (number)
	{
		buffer[(*index)++] = hex_digits[number % 16];
		number /= 16;
	}
}

void	print_hex_for_pointer(void *pointer, int *num_of_characters)
{
	unsigned long long	number;
	char				buffer[17];
	int					index;

	number = (unsigned long long)pointer;
	if (number == 0)
	{
		write(1, "0", 1);
		(*num_of_characters)++;
		return ;
	}
	number_to_hex_buffer(number, buffer, &index);
	while (--index >= 0)
	{
		write(1, &buffer[index], 1);
		(*num_of_characters)++;
	}
}

void	print_memory(va_list *arg_ptr, int *num_of_characters)
{
	void	*res;

	res = va_arg(*arg_ptr, void *);
	if (!res)
	{
		write(1, "0x0", 3);
		(*num_of_characters) += 3;
		return ;
	}
	write(1, "0x", 2);
	(*num_of_characters) += 2;
	print_hex_for_pointer(res, num_of_characters);
}

static char	*get_hex_digits(int uppercase)
{
	if (uppercase)
		return ("0123456789ABCDEF");
	else
		return ("0123456789abcdef");
}

void	print_hex(unsigned long long number, int uppercase,
		int *num_of_characters)
{
	char	*hex_digits;
	char	buffer[17];
	int		index;

	hex_digits = get_hex_digits(uppercase);
	index = 0;
	if (!number)
	{
		write(1, "0", 1);
		(*num_of_characters)++;
		return ;
	}
	while (number)
	{
		buffer[index++] = hex_digits[number % 16];
		number /= 16;
	}
	while (--index >= 0)
	{
		write(1, &buffer[index], 1);
		(*num_of_characters)++;
	}
}
