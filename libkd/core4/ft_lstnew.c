#include "libkd.h"

t_list	*kd_lstnew(void *content)
{
	t_list	*list;

	list = kd_malloc(sizeof(t_list));
	if (!list)
		return (list);
	list->content = content;
	list->next = NULL;
	return (list);
}
