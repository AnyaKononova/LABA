#include<stdio.h>

typedef struct ali{
	char* name;
	char* weight;
	char* seller;
	float price;
	char* delivery;
	int quantity;
	struct ali* next;
}ali;
ali* clear(ali *head);
ali *newcloth(ali * head);
ali *search(char *str,ali *head);
ali* read();
char* inputlines();
char* read2 (FILE *f,char *a);
void edit(ali *head);
void rewrite(ali *head);


