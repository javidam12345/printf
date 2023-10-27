/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_string.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaragone <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/27 17:55:40 by jaragone          #+#    #+#             */
/*   Updated: 2023/10/27 17:55:40 by jaragone         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	print_string(va_list *arg_ptr, int *num_of_characters)
{
	char	*converted;

	converted = va_arg(*arg_ptr, char *);
	if (!converted)
	{
		write(1, "(null)", 6);
		(*num_of_characters) += 6;
		return ;
	}
	(*num_of_characters) += (int)ft_strlen(converted);
	ft_putstr_fd(converted, 1);
}
