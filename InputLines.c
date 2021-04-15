#include<string.h>
#include<stdio.h>
#include<stdlib.h>

#include"Aliexpress.h"

char* inputlines(){
	char buffer[80];
	char *a;
	fgets(buffer,80,stdin);
	a=(char*)malloc(sizeof(char)*(strlen(buffer)+1));
	strcpy(a,buffer);
	return a;
}

