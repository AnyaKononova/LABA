#include<stdio.h>
#include<string.h>
#include"Aliexpress.h"

ali *search(char *str,ali *head){
    while(head !=NULL){
        if(!strcmp(head->seller,str))
        	break;
        else head=head->next;
    }
    return head;
}

