/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strispath.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlorrine <hlorrine@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/12 23:01:49 by hlorrine          #+#    #+#             */
/*   Updated: 2020/11/12 23:01:51 by hlorrine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cc_str.h"

int	strispath(const char *str)
{
	if (*str == '/' || !strncmp(str, "./", 2) || !strncmp(str, "../", 3))
		return (1);
	return (0);
}
