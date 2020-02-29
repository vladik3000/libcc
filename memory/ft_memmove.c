/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbutterw <dbutterw@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/08 00:07:54 by dbutterw          #+#    #+#             */
/*   Updated: 2020/01/06 14:39:22 by dbutterw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	unsigned char	*tmpdst;
	unsigned char	*tmpsrc;

	if (!src && !dst)
		return (NULL);
	tmpdst = (unsigned char*)dst;
	tmpsrc = (unsigned char*)src;
	if (tmpsrc < tmpdst)
		while (len--)
			*(tmpdst + len) = *(tmpsrc + len);
	else
		while (len--)
			*tmpdst++ = *tmpsrc++;
	return (dst);
}