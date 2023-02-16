#include "libkd.h"

void	kd_lstadd_back(t_list **lst, t_list *new)
{
	if (*lst)
		kd_lstlast(*lst)->next = new;
	else
		*lst = new;
}
