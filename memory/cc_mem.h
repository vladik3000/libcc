/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cc_mem.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlorrine <hlorrine@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/12 22:59:53 by hlorrine          #+#    #+#             */
/*   Updated: 2020/11/12 22:59:55 by hlorrine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CC_MEM_H
# define CC_MEM_H
# include <stddef.h>

# undef xmalloc
# undef memset
# undef memcpy
# undef memmove
# undef memalloc
# undef memccpy
# undef memchr
# undef memcmp
# undef memdel
# undef bzero

void		*xmalloc(size_t size);
void		*memset(void *b, int c, size_t len);
void		*memcpy(void *dst, const void *src, size_t n);
void		*memmove(void *dst, const void *src, size_t len);
void		*memalloc(size_t size);
void		*memccpy(void *dst, const void *src, int c, size_t n);
void		*memchr(const void *s, int c, size_t n);
int			memcmp(const void *s1, const void *s2, size_t n);
void		memdel(void **ap);
void		bzero(void *s, size_t n);

#endif
