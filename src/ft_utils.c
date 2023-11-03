/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaragone <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/27 17:54:58 by jaragone          #+#    #+#             */
/*   Updated: 2023/10/27 17:55:01 by jaragone         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	print_character(va_list *arg_ptr, int *num_of_characters)
{
	char	c;

	c = va_arg(*arg_ptr, int);
	if (write(1, &c, 1) == -1)
		return (-1);
	(*num_of_characters)++;
	return (0);
}

int	print_percentage(int *num_of_character)
{
	if (write(1, "%", 1) == -1)
		return (-1);
	(*num_of_character)++;
	return (0);
}

int	print_rest(const char *character, int *num_of_characters)
{
	if (write(1, character, 1) == -1)
		return (-1);
	(*num_of_characters)++;
	return (0);
}
