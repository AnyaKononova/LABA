#include"list.h"
#include<iostream>
#include<locale.h>
using namespace std;
int main(int argc, char** argv) {

	setlocale(LC_ALL, "Russian");
	if (argc < 2) {
		std::cout << "������� ��� �����(���� ������)\n";
		return 1;
	}
	string filename = argv[1];
	List list;
	int choose = -1;

	list.readFromFile(filename);
	cout << "\n\n\n������������. �� ������ � ��������� ���������� ����� ������ ������� Aliexpress. ";
		

	while (choose != 0) {

		cout << "\n���������� �������� ��������:\n";
		cout << "[1] �������� ������� � �������.\n[2] ������� ������� �� ��������.\n[3] ������� ���������� � ������ ���� ��������� �����������.\n";
		cout << "[4] ������� ���������� � ������ ������������� �������� .\n[5] ������������� ������� ��������.\n[0] �����.\n";
		cin >> choose;
		switch (choose) {
		case 1: {
			Ali x;
			std::string s;
			int y;
			float ff;
			std::cout << "������� �������� ������� � �������� > ";
			std::cin >> s;
			x.SetName(s);

			std::cout << "������� ��� �������(� �������) > ";
			std::cin >> y;
			x.SetWeight(y);


			std::cout << "������� �������� �������� �������� > ";
			std::cin >> s;
			x.SetSeller(s);


			std::cout << "������� ��������� ������ > ";
			std::cin >>ff;
			x.SetPrice(ff);

			std::cout << "������� ����������� ��������� � �������� ������ > ";
			std::cin >> s;

			x.SetDelivery(s);

			std::cout << "������� ���������� ������� �� ������ �������� > ";
			std::cin >> y;
			x.SetQuantity(y);

			list.addItem(x);
			list.printToFile(filename);
		}
		break;
		case 2: {
			int id;
			cout << "ID ������: " << '\n';
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

			cout << "�������� �������� ��������: " << '\n';
			cin >> seller;
			Ali* a = list.searchSeller(seller);
			cout << *a << '\n';
		}
		break;
		case 5: {
			int index;
			cout << "������� ������: " << '\n';
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