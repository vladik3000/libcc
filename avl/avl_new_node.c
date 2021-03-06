/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   avl_new_node.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlorrine <hlorrine@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/12 22:57:10 by hlorrine          #+#    #+#             */
/*   Updated: 2020/11/12 22:57:11 by hlorrine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cc_avl.h"
#include "cc_mem.h"

t_avl_tree				*avl_new_node(t_avl_pair *pair)
{
	t_avl_tree *node;

	node = (t_avl_tree*)xmalloc(sizeof(t_avl_tree));
	node->pair = (t_avl_pair*)xmalloc(sizeof(t_avl_pair));
	memmove(node->pair, pair, sizeof(t_avl_pair));
	node->left = NULL;
	node->right = NULL;
	node->height = 1;
	return (node);
}
