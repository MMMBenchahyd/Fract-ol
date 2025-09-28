/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   atodouble.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbenchah <mbenchah@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/27 00:31:25 by mbenchah          #+#    #+#             */
/*   Updated: 2025/02/27 00:34:31 by mbenchah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static void	skip_space(char **s)
{
	while (**s == ' ' || (**s >= '\t' && **s <= '\r'))
		(*s)++;
}

static double	fractional_part(const char *s)
{
	double		res;
	double		div;

	res = 0.0;
	div = 1.0;
	while (*s >= '0' && *s <= '9')
	{
		div *= 10.0;
		res = res * 10.0 + (double)(*s++ - '0');
	}
	res /= div;
	return (res);
}

double	ft_atod(const char *s)
{
	double	nb;
	int		sign;

	skip_space((char **)&s);
	sign = 1;
	if (*s == '-')
	{
		sign = -1;
		s++;
	}
	else if (*s == '+')
		s++;
	nb = 0.0;
	while (*s >= '0' && *s <= '9')
		nb = nb * 10.0 + (double)(*s++ - '0');
	if (*s == '.')
		nb += fractional_part(s + 1);
	return (nb * sign);
}

int	valid_double(char *s)
{
	char	*ptr;

	skip_space(&s);
	if (*s == '-' || *s == '+')
		s++;
	ptr = s;
	while (*s >= '0' && *s <= '9')
		s++;
	if (*s == 0 && s > ptr)
		return (1);
	if (*s != '.')
		return (0);
	s++;
	ptr = s;
	while (*s >= '0' && *s <= '9')
		s++;
	if (ptr == s)
		return (0);
	skip_space(&s);
	if (*s)
		return (0);
	return (1);
}
