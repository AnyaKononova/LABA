#include<stdio.h>
#include<stdlib.h>
#include"Aliexpress.h"

ali *newcloth(ali *head){
	ali *x=(ali*)malloc(sizeof(ali));
	printf("Введите название позиции в каталоге > ");
	x->name=inputlines();
	printf("Введите вес посылки(в граммах) > ");
	x->weight=inputlines();
	printf("Введите название магазина продавца > ");
	x->seller=inputlines();
	printf("Введите стоимость товара > ");
	scanf("%f",&x->price);
        getchar();
	printf("Введите особенности перевозки и описание товара >  ");
	x->delivery=inputlines();
	printf("Введите количество товаров на складе магазина > ");
	scanf("%d",&x->quantity);
	x->next=head;
	return x;
}

