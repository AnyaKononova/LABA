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
		std::cout << "���� �� ����������� " << filename << '\n';
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
		std::cout << "���� �� ����������� " << filename << '\n';
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

		std::cout << "��������, ��� ����� ���������������: \n";
		std::cout << "[1] �������� �������� ������.\n[2] �������� ��� �������.\n[3] �������� �������� �������� �������� Aliexpress.\n";
		std::cout << "[4] �������� ��������� �������.\n[5] �������� ����������� ��������� � �������� ������.\n[6] �������� ���������� ������ �� ������.\n";
		std::cout << "[7] ��������� ��������������, ��������� ��� ��������� � ����� �� ������.\n";

		std::cin>>y;

		switch (y) {
		case 1:
		{
			std::string name;
			std::cout << "������� ����� �������� ������� � �������� > ";
			std::cin >> name;
			f->SetName(name);
		}
			break;

		case 2:
		{
			std::cout << "������� ����� ��� ������ (� �������) > ";
			int weight;
			std::cin >> weight;
			f->SetWeight(weight);
		}
			break;

		case 3:
		{
			std::cout <<"������� ����� �������� �������� �������� ���������� > ";
			std::string seller;
			std::cin >> seller;
			f->SetSeller(seller);
		}
			break;
		case 4:
		{
			std::cout << "������� ����� ��������� ������ > ";
			float price;
			std::cin >> price;
			f->SetPrice(price);
		}
			break;

		case 5:
		{
			std::cout << "������� ����� ����������� ��������� � �������� >";
			std::string delivery;
			std::cin >> delivery;
			f->SetDelivery(delivery);
		}
			break;

		case 6:
		{
			std::cout << "������� ����� ����� ��������� ������� �� ������ > ";
			int quantity;
			std::cin >> quantity;
			f->SetQuantity(quantity);
		}
			break;

		case 7:

			break;

		default:

			std::cout<<"������� ��� ������ ������� �� ����������.\n";

			break;

		}

	} while (y != 7);

}

