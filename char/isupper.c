/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   isupper.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlorrine <hlorrine@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/12 22:57:52 by hlorrine          #+#    #+#             */
/*   Updated: 2020/11/12 22:57:55 by hlorrine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		isupper(int c)
{
	if (c >= 'A' && c <= 'Z')
		return (1);
	return (0);
}
