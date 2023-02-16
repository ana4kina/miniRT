#include "ft_malloc.h"

void	*kd_malloc(size_t size)
{
	return (kd_malloc_add(malloc(size)));
}

void	*kd_maltag(size_t size, char const *tag)
{
	return (kd_maltag_add(malloc(size), tag));
}

void	*kd_malloc_add(void *p)
{
	p = kd_malloc_add_queue(p, NULL);
	if (!p && errno == ENOMEM)
		kd_enomem();
	return (p);
}

void	*kd_maltag_add(void *p, char const *tag)
{
	p = kd_malloc_add_queue(p, tag);
	if (!p && errno == ENOMEM)
		kd_enomem();
	return (p);
}

void	*kd_malloc_add_queue(void *p, char const *tag)
{
	t_malloc	**list;
	t_malloc	*lst;

	list = kd_malloc_queue();
	if (p && !kd_malloc_lstfind(*list, p))
	{
		lst = kd_malloc_lstnew(p, tag);
		if (!lst)
			p = kd_free(p);
		else
		{
			lst->next = *list;
			*list = lst;
		}
	}
	return (p);
}
