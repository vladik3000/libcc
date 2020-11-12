/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   avl_map_postfix.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlorrine <hlorrine@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/12 22:57:00 by hlorrine          #+#    #+#             */
/*   Updated: 2020/11/12 22:57:02 by hlorrine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cc_avl.h"

static void	walk_nodes(t_avl_tree *node, void (*f)(void *))
{
	if (!node)
		return ;
	walk_nodes(node->left, f);
	walk_nodes(node->right, f);
	f(node->pair->value);
}

void		avl_map_postfix(t_avl_obj *obj, void (*f)(void *))
{
	if (!obj || !f)
		return ;
	walk_nodes(obj->tree, f);
}
