#include<stdio.h>
#include<stdlib.h>
#include"Aliexpress.h"
ali* clear(ali *head)
{
    	ali *dop;
    	dop=head->next;
    	free(head->name);
    	free(head->weight);
    	free(head->seller);
    	free(head->delivery);
    	free(head);
	return dop;
}

