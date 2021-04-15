#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include"Aliexpress.h"

char* read2 (FILE *f,char *a){
	char *b;
	b=(char*)malloc(sizeof(char)*strlen(a)+1);
	strcpy(b,a);
	return b;
}
ali* read (){
	FILE *f;
	char *k;
	char a[50];
	ali *head=NULL;
	f=fopen("Laba.txt","r");
	if(f==NULL)return head;
	while (1){
		ali *tmp;
		k=fgets(a,50,f);
		if(k==0)break;
		tmp=(ali*)malloc(sizeof(ali));
		tmp->name=read2(f,a);
		fgets(a,50,f);
		tmp->weight=read2(f,a);
		fgets(a,50,f);
		tmp->seller=read2(f,a);
		fscanf(f,"%f",&tmp->price);
		fgets(a,50,f);
		tmp->delivery=read2(f,a);
		fscanf(f,"%d",&tmp->quantity);
		tmp->next=head;
		head=tmp;
	}
	fclose(f);
	return head;
}

