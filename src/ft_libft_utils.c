/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_libft_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaragone <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/03 17:10:52 by jaragone          #+#    #+#             */
/*   Updated: 2023/11/03 17:10:54 by jaragone         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putstr_fd(char *s, int fd)
{
	int	i;

	i = 0;
	if (!s)
		return (0);
	while (s[i])
	{
		if (ft_putchar_fd(s[i], fd) == -1)
			return (-1);
		i++;
	}
	return (0);
}

int	ft_putnbr_fd(int n, int fd)
{
	long long int	t;
	long long int	power;
	char			num;

	t = n;
	if (t < 0)
	{
		if (ft_putchar_fd('-', fd) == -1)
			return (-1);
		t = -t;
	}
	power = 1;
	while (power <= t / 10)
		power *= 10;
	while (power > 0)
	{
		num = (t / power) % 10 + '0';
		if (ft_putchar_fd(num, fd) == -1)
			return (-1);
		t %= power;
		power /= 10;
	}
	return (0);
}

int	ft_putchar_fd(char c, int fd)
{
	return (write(fd, &c, 1));
}

size_t	ft_strlen(const char *str)
{
	int	len;

	len = 0;
	while (str[len] != '\0')
	{
		len++;
	}
	return (len);
}
