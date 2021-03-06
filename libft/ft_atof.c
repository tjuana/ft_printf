/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atof.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccriston <ccriston@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/24 18:07:28 by ccriston          #+#    #+#             */
/*   Updated: 2020/02/24 18:07:49 by ccriston         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

double		ft_atof(char *str, int i)
{
	double		s;
	double		r;
	double		d;

	d = 1.;
	r = 0.;
	s = (str[i] == '-') ? -1. : 1.;
	(str[i] == '-' || str[i] == '+') ? i++ : i;
	while (str[i] && str[i] >= '0' && str[i] <= '9')
		r = r * 10. + str[i++] - '0';
	(str[i] && str[i] == '.') ? i++ : 1;
	while (str[i] && str[i] >= '0' && str[i] <= '9' && (d *= 10.) != 0.)
		r = r * 10. + str[i++] - '0';
	return ((r != 0.) ? (r = (r / d) * s) : (r /= d));
}
