/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tboivin <tboivin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/18 23:32:05 by tboivin           #+#    #+#             */
/*   Updated: 2017/04/08 20:51:14 by tboivin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include "libft.h"

typedef struct	s_conv
{
	va_list		(ag);
	char		*str;
	char		*sp;
	char		*ze;
	char		*s;
	wchar_t		wc;
	int			fd;
	wchar_t		*ws;
	char		c;
	int			slen;
	long long	i;
	int			final_len;
	int			wi;
	wchar_t		*wtmp;
}				t_conv;

typedef struct	s_flags
{
	char		flags;
	int			preci;
	int			point;
	int			champ;
	int			espace;
	int			pos;
	char		base;
	int			neg;
	int			signe;
	int			zero;
	int			space;
	int			left;
	int			hast;
	int			hh;
	int			h;
	int			l;
	int			ll;
	int			j;
	int			z;
	int			final_len;
}				t_flags;

/*
**DOSSIER ADD
*/
int				ft_vprintf(t_conv *c);
int				ft_dprintf(int fd, const char *format, ...);
void			get_space_w(t_conv *c, t_flags *f);
void			get_zero_w(t_conv *c, t_flags *f);
void			get_space(t_conv *c, t_flags *f);
void			get_sign(t_conv *c, t_flags *f);
void			get_zero(t_conv *c, t_flags *f);
int				ft_get_conv(char s, t_flags *f);

void			conv_hast(t_conv *c, t_flags *f);
void			conv_s(t_conv *c, t_flags *f);
void			conv_c(t_conv *c, t_flags *f);
void			conv_u(t_conv *c, t_flags *f);
void			conv_d(t_conv *c, t_flags *f);
void			conv_x(t_conv *c, t_flags *f, int x);
void			print_s(t_conv *c, t_flags *f);
void			handles_d(t_conv *c, t_flags *f);

void			handles_c(t_conv *c, t_flags *f);
void			ft_get_flags(char *s, t_flags *f);
void			handle(t_flags *f, t_conv *c);
void			len_espace(t_conv *c, t_flags *f);
void			print_d(t_conv *c, t_flags *f);
t_flags			*start_struct(void);
t_conv			*start_conv(int fd);
void			handle_flags_d(t_conv *c, t_flags *f);

char			*ft_uitoa(unsigned long int n);
char			*ft_litoa(long int n);
char			*ft_itoa_base(long int n, int b, int conv);
char			*ft_itoa_base_neg(unsigned long int n, int b, int conv);
void			*ft_strset(int c, size_t len);
int				ft_printf(const char *format, ...);
void			ft_get_mod(char *s, t_flags *f);
int				ft_putnwchar_(t_conv *c, t_flags *f, size_t v, int size);
int				ft_putnwchar(t_conv *c, t_flags *f);
void			ft_putnwstr(t_conv *c, t_flags *f);
size_t			ft_strnwlen(t_conv *c, t_flags *f);
void			free_struct(t_conv *s);

#endif
