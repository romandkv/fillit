/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isspace.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pshock <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/16 17:30:26 by pshock            #+#    #+#             */
/*   Updated: 2019/09/16 17:41:36 by pshock           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_isspace(char nptr)
{
	if (nptr == ' ' || nptr == '\t' || nptr == '\r' ||
			nptr == '\f' || nptr == '\v' || nptr == '\n')
		return (1);
	return (0);
}
