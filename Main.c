#include"Aliexpress.h"
#include <stdio.h>

int main()
{
{
   ali *head=NULL;
	ali *help;
	ali *help2;
	int n;
	head=read();
	do
           {
		printf("\n\n\nЗдравствуйте. Вы попали в программу управления базой данных товаров Aliexpress. "
		"\nПожалуйста выберите действие:\n"
		"[1] Добавить позицию в каталог.\n[2] Удалить позицию из каталога.\n[3] Вывести информацию о товаре всех магазинов Алиекспресс.\n"
		"[4] Вывести информацию о товаре определенного продавца .\n"
		"[5] Редактировать позиции каталога.\n[0] Выход.\n");
		scanf("%d",&n);
		getchar();
		switch(n)
		{
			case 1:
				head=newcloth(head);
			break;
			case 2:
				help=head;
				help2=head;
				if(help==NULL){
					printf("Позиций в каталоге не найдено.\n");
					break;
				}
				printf("Введите название магазина:");
				help=search(inputlines(),help);
				if(help==NULL){
					printf("Товаров с таким названием в базе данных не найдено.\n");
					break;
				}
				if(help==head)
					head=clear(help);
				else{
					while(1){
						if(help2->next==help)
							break;
						else help2=help2->next;
					}
					help2->next=clear(help);
				}
			break;
			case 3:
				help=head;
				if(help==NULL){
					printf("Позиций в каталоге не найдено.\n");
					break;
				}
				while(help !=NULL){
					printf("Название позиции: %sВес посылки: %sПродавец: %s"
					"Стоимость: %f\nОсобенности транспортировки и описание: %sДоступное количество товара у продавца на складе: %d\n\n",
					help->name,help->weight,help->seller,help->price,help->delivery,help->quantity);
					help=help->next;
				}
			break;
			case 4:
				help=head;
				if(help==NULL){
					printf("Позиций в каталоге не найдено. \n");
					break;
				}
				printf("Введите название магазина:");
				help=search(inputlines(),help);
				if(help==NULL){
					printf("Магазин с введенным наименованием отсутсвуют.\n");
					break;
				}
				printf("Название позиции: %sВес посылки: %sПродавец: %s"
                                        "Стоимость: %.3f\nОсобенности транспортировки и описание: %sДоступное количество товара у продавца на складе: %d\n\n",
                                        help->name,help->weight,help->seller,help->price,help->delivery,help->quantity);
                                        help=help->next;

			break;
			case 5:
				help=head;
				if(help==NULL){
					printf("Позиций в каталоге не найдено.\n");
					break;
				}
				printf("Введите название магазина, чей товар вы хотите изменить:");
				help=search(inputlines(),help);
				if(help==NULL){
					printf("Товар с введеными продавцом отсутствует.\n");
					break;
				}
				edit(help);
			break;
   
			case 0:
				rewrite(head);
				printf("\n Вы вышли из центра управления базой данной. Спасибо, что воспользовались нашей программой. До свидания! \n");
			break;
			default:
				printf("Команды под данным номером не существует. Пожалуйста, попробуйте ещё раз. \n ");
			break;
		}
	}
	while(n!=0);
}
    return 0;
}
