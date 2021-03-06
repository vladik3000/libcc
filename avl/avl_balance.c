/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   avl_balance.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlorrine <hlorrine@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/12 22:55:50 by hlorrine          #+#    #+#             */
/*   Updated: 2020/11/12 22:55:52 by hlorrine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cc_avl.h"
#include "cc_math.h"

static t_avl_tree		*right_rotate(t_avl_tree *y)
{
	t_avl_tree			*x;
	t_avl_tree			*t;

	x = y->left;
	t = x->right;
	x->right = y;
	y->left = t;
	y->height = (int)max(avl_get_height(x->right), \
	avl_get_height(x->left)) + 1;
	y->height = (int)max(avl_get_height(y->right), \
	avl_get_height(y->left)) + 1;
	return (x);
}

static t_avl_tree		*left_rotate(t_avl_tree *x)
{
	t_avl_tree			*y;
	t_avl_tree			*t;

	y = x->right;
	t = y->left;
	y->left = x;
	x->right = t;
	y->height = (int)max(avl_get_height(x->right), \
	avl_get_height(x->left)) + 1;
	y->height = (int)max(avl_get_height(y->right), \
	avl_get_height(y->left)) + 1;
	return (y);
}

t_avl_tree				*avl_balance(t_avl_tree *node, \
int (*cmp)(const void *, const void *))
{
	int					balance;

	if (!node)
		return (node);
	balance = avl_get_height(node->left) - avl_get_height(node->right);
	if (balance > 1 && cmp(node->left->pair->key, node->pair->key) < 0)
		return (right_rotate(node));
	if (balance < -1 && cmp(node->right->pair->key, node->pair->key) > 0)
		return (left_rotate(node));
	if (balance > 1 && cmp(node->left->pair->key, node->pair->key) > 0)
	{
		node->left = left_rotate(node->left);
		return (right_rotate(node));
	}
	if (balance < -1 && \
		cmp(node->right->pair->key, node->pair->key) < 0)
	{
		node->right = right_rotate(node->right);
		return (left_rotate(node));
	}
	return (node);
}
