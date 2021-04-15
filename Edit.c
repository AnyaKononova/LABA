#include<stdio.h>
#include<stdlib.h>
#include"Aliexpress.h"

void edit(ali *head){
	int y;
    	do
             {
	        printf("Выберете, что нужно отредактировать:  \n"
        	"[1] Изменить название товара.\n[2] Изменить вес посылки.\n[3] Изменить название магазина продавца Aliexpress.\n"
	        "[4] Изменить стоимость позиции.\n[5] Изменить особенности перевозки и описание товара.\n[6] Изменить количество товара на складе.\n"
	        "[7] Завершить редактирвоание, сохранить все изменения и выйти из режима.\n");
        	scanf("%d",&y);
	        getchar();
        	switch(y){
			case 1:
				free(head->name);
				printf("Введите новое название позиции в каталоге > ");
				head->name=inputlines();
			break;
			case 2:
				free(head->weight);
				printf("Введите новый вес товара (в граммах) > ");
				head->weight=inputlines();
			break;
			case 3:
				free(head->seller);
				printf("Введите новое название магазина продавца Аликспресс > ");
				head->seller=inputlines();
			break;
			case 4:
				printf("Введите новую стоимость товара > ");
				scanf("%f",&head->price);
			break;
			case 5:
				free(head->delivery);
				printf("Введите новые особенности перевозки и описание > ");
				head->delivery=inputlines();
			break;
			case 6:
				printf("Введите новое число доступных товаров на складе > ");
				scanf("%d",&head->quantity);
			break;
			case 7:
			break;
			default:
				printf("Команды под данным номером не существует.\n");
			break;
	        }
    	}
	while(y !=7);
}
