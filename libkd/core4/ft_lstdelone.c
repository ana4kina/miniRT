#include "libkd.h"

void	kd_lstdelone(t_list *lst, void (*del)(void *))
{
	del(lst->content);
	lst = kd_free(lst);
}
