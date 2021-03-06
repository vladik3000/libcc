/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   avl_insert.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlorrine <hlorrine@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/12 22:56:54 by hlorrine          #+#    #+#             */
/*   Updated: 2020/11/12 22:56:56 by hlorrine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cc_avl.h"
#include "cc_math.h"
#include "cc_mem.h"

static t_avl_tree	*replace_node(t_avl_obj *obj, t_avl_pair *pair, \
	t_avl_tree *node)
{
	obj->del(node->pair);
	memmove(node->pair, pair, sizeof(t_avl_pair));
	return (node);
}

static t_avl_tree	*insert_pair(t_avl_obj *obj, t_avl_pair *pair, \
	t_avl_tree *node)
{
	int cmp_val;

	if (!node)
		return (avl_new_node(pair));
	cmp_val = obj->cmp(pair->key, node->pair->key);
	if (cmp_val < 0)
		node->left = insert_pair(obj, pair, node->left);
	else if (cmp_val > 0)
		node->right = insert_pair(obj, pair, node->right);
	else
		return (replace_node(obj, pair, node));
	node->height = (int)max(avl_get_height(node->left), \
		avl_get_height(node->right)) + 1;
	return (avl_balance(node, obj->cmp));
}

t_avl_tree			*avl_insert(t_avl_obj *obj, t_avl_pair *pair)
{
	if (!obj || !pair)
		return (NULL);
	return ((obj->tree = insert_pair(obj, pair, obj->tree)));
}
