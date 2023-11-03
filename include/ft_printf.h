/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaragone <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/27 19:25:37 by jaragone          #+#    #+#             */
/*   Updated: 2023/10/27 19:25:40 by jaragone         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <stdarg.h>
# include <stdio.h>
# include <unistd.h>

int		ft_printf(const char *format, ...);

void	analyze_string(const char *format, va_list *arg_ptr,
			int *num_of_characters);

int		percentage_switcher(const char *character, va_list *arg_ptr,
			int *num_of_characters);

// number starts here!

int		read_number(va_list *arg_ptr, int *num_of_characters);

// read string

int		print_string(va_list *arg_ptr, int *num_of_characters);

// read pointer

int		print_memory(va_list *arg_ptr, int *num_of_characters);

int		print_hex_for_pointer(void *pointer, int *num_of_characters);

int		print_hex(unsigned long long number, int uppercase,
			int *num_of_characters);

int		read_number_u(unsigned int a, int *num_of_characters);

int		print_character(va_list *arg_ptr, int *num_of_characters);

int		print_percentage(int *num_of_character);

int		print_rest(const char *character, int *num_of_characters);

int		ft_putstr_fd(char *s, int fd);

int		ft_putnbr_fd(int n, int fd);

int		ft_putchar_fd(char c, int fd);

size_t	ft_strlen(const char *str);

#endif
