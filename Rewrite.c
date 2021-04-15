#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"Aliexpress.h"

   void rewrite(ali *head) 
      {
    	FILE *f;
    	f=fopen("Laba.txt","w");
	while(head !=NULL){
        	fprintf(f,"%s%s%s%f%s%d ",head->name,head->weight,head->seller,head->price,head->delivery,head->quantity);
	        head=clear(head);
    	}
    	fclose(f);
      }

