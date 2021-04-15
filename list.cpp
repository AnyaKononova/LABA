#include"list.h"
#include <string>  



Ali* List::search(int index) {
	Ali* searched = NULL, * tmp = head;
	int i = 0;
	while (tmp != NULL) {
		if (i == index) {
			searched = tmp;
			break;
		}
		tmp = tmp->next;
		i++;
	}
	return searched;
}

Ali* List::searchSeller(std::string seller) {
	Ali* searched = NULL, * tmp = head;
	while (tmp != NULL) {
		if (tmp->GetSeller() == seller) {
			searched = tmp;
			break;
		}
		tmp = tmp->next;
	}
	return searched;
}

void List::addItem(Ali a) {

	Ali* tmp = new Ali(a);

	tmp->next = head;
	tmp->prev = NULL;

	if (head) {
		head->prev = tmp;
	}
	head = tmp;

}

void List::printList() {
	Ali* tmp = head;
	while (tmp != NULL) {
		std::cout << *tmp << '\n';
		tmp = tmp->next;
	}
}

void  List::printToFile(std::string filename) {
	std::ofstream out(filename);
	if (out.is_open()) {
		Ali* tmp = head;
		while (tmp != NULL) {
			out << tmp->GetName() << '\n' << tmp->GetPrice() << '\n' << tmp->GetDelivery() << '\n' << tmp->GetQuantity() << '\n' << tmp->GetSeller() << '\n' << tmp->GetWeight() << '\n';
			tmp = tmp->next;
		}
	}
	else {
		std::cout << "Файл не открывается " << filename << '\n';
	}
	out.close();
}
void List::readFromFile(std::string filename) {
	std::ifstream in(filename);
	std::string name, delivery,seller,price,quantity, weight;
	if (in.is_open()) {
		while (1) {
			if (std::getline(in, name) && std::getline(in, price) && std::getline(in, delivery) && std::getline(in, quantity) && std::getline(in, seller) && std::getline(in, weight)) {
				Ali newali(name, seller, delivery, std::stod(price), std::stoi(weight), std::stoi(quantity));
				this->addItem(newali);
			}
			else {
				break;
			}
		}
		in.close();
	}
	else {
		std::cout << "Файл не открывается " << filename << '\n';
	}
}
void List::remove(int index) {

	Ali* searched = search(index);
	if (!searched)
		return;

	if (index == 0) {
		if (head->next) {
			head = searched->next;
			searched->next->prev = NULL;
		}
		else {
			head = NULL;
			return;
		}
	}
	else {
		if (searched->prev) {
			searched->prev->next = searched->next;
		}
		if (searched->next) {
			searched->next->prev = searched->prev;
		}
	}
	delete searched;

}

void List::free() {
	Ali* tmp = head;
	while (tmp != NULL) {
		Ali* p = tmp;
		tmp = tmp->next;
		delete p;
	}
}

void List::edit(int index) {
	Ali* f = search(index);
	if (!f)
		return;
	int y;

	do
	{

		std::cout << "Выберете, что нужно отредактировать: \n";
		std::cout << "[1] Изменить название товара.\n[2] Изменить вес посылки.\n[3] Изменить название магазина продавца Aliexpress.\n";
		std::cout << "[4] Изменить стоимость позиции.\n[5] Изменить особенности перевозки и описание товара.\n[6] Изменить количество товара на складе.\n";
		std::cout << "[7] Завершить редактирвоание, сохранить все изменения и выйти из режима.\n";

		std::cin>>y;

		switch (y) {
		case 1:
		{
			std::string name;
			std::cout << "Введите новое название позиции в каталоге > ";
			std::cin >> name;
			f->SetName(name);
		}
			break;

		case 2:
		{
			std::cout << "Введите новый вес товара (в граммах) > ";
			int weight;
			std::cin >> weight;
			f->SetWeight(weight);
		}
			break;

		case 3:
		{
			std::cout <<"Введите новое название магазина продавца Аликспресс > ";
			std::string seller;
			std::cin >> seller;
			f->SetSeller(seller);
		}
			break;
		case 4:
		{
			std::cout << "Введите новую стоимость товара > ";
			float price;
			std::cin >> price;
			f->SetPrice(price);
		}
			break;

		case 5:
		{
			std::cout << "Введите новые особенности перевозки и описание >";
			std::string delivery;
			std::cin >> delivery;
			f->SetDelivery(delivery);
		}
			break;

		case 6:
		{
			std::cout << "Введите новое число доступных товаров на складе > ";
			int quantity;
			std::cin >> quantity;
			f->SetQuantity(quantity);
		}
			break;

		case 7:

			break;

		default:

			std::cout<<"Команды под данным номером не существует.\n";

			break;

		}

	} while (y != 7);

}

