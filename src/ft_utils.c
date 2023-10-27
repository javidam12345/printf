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

void	print_character(va_list *arg_ptr, int *num_of_characters)
{
	char	c;

	c = va_arg(*arg_ptr, int);
	write(1, &c, 1);
	(*num_of_characters)++;
}

void	print_percentage(int *num_of_character)
{
	write(1, "%", 1);
	(*num_of_character)++;
}

void	print_rest(const char *character, int *num_of_characters)
{
	write(1, character, 1);
	(*num_of_characters)++;
}
