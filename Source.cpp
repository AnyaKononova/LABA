#include"list.h"
#include<iostream>
#include<locale.h>
using namespace std;
int main(int argc, char** argv) {

	setlocale(LC_ALL, "Russian");
	if (argc < 2) {
		std::cout << "Введите имя файла(базы данных)\n";
		return 1;
	}
	string filename = argv[1];
	List list;
	int choose = -1;

	list.readFromFile(filename);
	cout << "\n\n\nЗдравствуйте. Вы попали в программу управления базой данных товаров Aliexpress. ";
		

	while (choose != 0) {

		cout << "\nПожалуйста выберите действие:\n";
		cout << "[1] Добавить позицию в каталог.\n[2] Удалить позицию из каталога.\n[3] Вывести информацию о товаре всех магазинов Алиекспресс.\n";
		cout << "[4] Вывести информацию о товаре определенного продавца .\n[5] Редактировать позиции каталога.\n[0] Выход.\n";
		cin >> choose;
		switch (choose) {
		case 1: {
			Ali x;
			std::string s;
			int y;
			float ff;
			std::cout << "Введите название позиции в каталоге > ";
			std::cin >> s;
			x.SetName(s);

			std::cout << "Введите вес посылки(в граммах) > ";
			std::cin >> y;
			x.SetWeight(y);


			std::cout << "Введите название магазина продавца > ";
			std::cin >> s;
			x.SetSeller(s);


			std::cout << "Введите стоимость товара > ";
			std::cin >>ff;
			x.SetPrice(ff);

			std::cout << "Введите особенности перевозки и описание товара > ";
			std::cin >> s;

			x.SetDelivery(s);

			std::cout << "Введите количество товаров на складе магазина > ";
			std::cin >> y;
			x.SetQuantity(y);

			list.addItem(x);
			list.printToFile(filename);
		}
		break;
		case 2: {
			int id;
			cout << "ID товара: " << '\n';
			cin >> id;
			list.remove(id);
			list.printToFile(filename);
		}
			break;
		case 3: {
			list.printList();
		}
		break;
		case 4: {
			string seller;

			cout << "Название магазина продавца: " << '\n';
			cin >> seller;
			Ali* a = list.searchSeller(seller);
			cout << *a << '\n';
		}
		break;
		case 5: {
			int index;
			cout << "Введите индекс: " << '\n';
			cin >> index;
			list.edit(index);
			list.printToFile(filename);
		}
		break;
		case 6:
		default:
			break;
		}
	}
	list.free();
	return 0;
}