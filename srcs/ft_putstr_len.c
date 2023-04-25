/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_len.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-malt <ael-malt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/02 00:07:47 by ael-malt          #+#    #+#             */
/*   Updated: 2023/04/22 16:53:29 by ael-malt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void	ft_putstr_len(char *s, int *len)
{
	int	i;

	if (!s)
		*len += write(1, "(null)", 6);
	else
	{
		i = 0;
		while (s[i])
			*len += write(1, &s[i++], 1);
	}
}