/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_integer.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaragone <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/27 17:50:21 by jaragone          #+#    #+#             */
/*   Updated: 2023/10/27 17:50:22 by jaragone         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	read_number(va_list *arg_ptr, int *num_of_characters)
{
	int	converted;

	converted = va_arg(*arg_ptr, int);
	if (ft_putnbr_fd(converted, 1) == -1)
		return (-1);
	if (converted < 0)
	{
		converted = -converted;
		(*num_of_characters)++;
	}
	if (converted == 0)
		(*num_of_characters)++;
	else
	{
		while (converted != 0)
		{
			(*num_of_characters)++;
			converted /= 10;
		}
	}
	return (0);
}

static int	ft_putchar_increment(char c, int fd, int *num_of_characters)
{
	if (ft_putchar_fd(c, fd) == -1)
		return (-1);
	(*num_of_characters)++;
	return (0);
}

static int	print_digits(char *digits, int digit, int *num_of_characters)
{
	while (digit > 0)
	{
		if (ft_putchar_increment(digits[--digit], 1, num_of_characters) == -1)
			return (-1);
	}
	return (0);
}

int	read_number_u(unsigned int n, int *num_of_characters)
{
	unsigned int	temp;
	int				digit_count;
	char			digits[10];

	temp = n;
	digit_count = 0;
	if (temp == 0)
	{
		if (ft_putchar_increment('0', 1, num_of_characters) == -1)
			return (-1);
	}
	else
	{
		while (temp > 0)
		{
			digits[digit_count++] = (temp % 10) + '0';
			temp /= 10;
		}
		if (print_digits(digits, digit_count, num_of_characters) == -1)
			return (-1);
	}
	return (0);
}
