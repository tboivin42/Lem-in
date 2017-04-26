/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tboivin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/08 20:37:03 by tboivin           #+#    #+#             */
/*   Updated: 2017/04/08 20:48:32 by tboivin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_print_until(t_conv *c)
{
	int i;

	i = 0;
	while (c->str[i] && c->str[i] != '%')
	{
		ft_putchar_fd(c->str[i], c->fd);
		i++;
	}
	return (i);
}

int		ft_init(t_conv *c)
{
	int		i;
	t_flags *f;

	f = start_struct();
	if (!(c->str = ft_strchr(c->str, '%')))
		return (c->final_len);
	c->str++;
	while ((i = ft_get_conv(*c->str, f)) == -1)
	{
		ft_get_flags(c->str, f);
		c->str++;
	}
	if (c->str)
		c->str++;
	handle(f, c);
	c->final_len += ft_print_until(c);
	c->s = ft_strnew(0);
	free(f);
	ft_init(c);
	return (c->final_len);
}

int		ft_dprintf(int fd, const char *format, ...)
{
	t_conv	*c;

	c = start_conv(fd);
	va_start(c->ag, format);
	c->str = (char*)format;
	return (ft_vprintf(c));
}

int		ft_printf(const char *format, ...)
{
	t_conv	*c;

	c = start_conv(1);
	va_start(c->ag, format);
	c->str = (char*)format;
	return (ft_vprintf(c));
}

int		ft_vprintf(t_conv *c)
{
	int		len;

	len = 0;
	c->final_len = 0;
	len = ft_print_until(c);
	len += ft_init(c);
	va_end(c->ag);
	free_struct(c);
	free(c);
	return (len);
}
