#include "libkd.h"

void	kd_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*temp;

	while (*lst)
	{
		temp = (*lst)->next;
		kd_lstdelone(*lst, del);
		*lst = temp;
	}
}
