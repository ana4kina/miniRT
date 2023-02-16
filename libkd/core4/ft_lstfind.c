#include "libkd.h"

t_list	*kd_lstfind(t_list *lst, void *find, int (*f)(void *, void *))
{
	while (lst)
	{
		if (!f(lst->content, find))
			return (lst);
		lst = lst->next;
	}
	return (lst);
}
