#include "libkd.h"

void	kd_lstremove(t_list **lst, t_list *remove, void (*del)(void *))
{
	t_list	*temp;

	if (*lst == remove)
	{
		*lst = (*lst)->next;
		kd_lstdelone(remove, del);
	}
	else
	{
		temp = *lst;
		while (temp->next)
		{
			if (temp->next == remove)
			{
				temp->next = remove->next;
				kd_lstdelone(remove, del);
			}
			else
				temp = temp->next;
		}
	}
}
