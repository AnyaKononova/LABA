#pragma once
#include<string>
#include<iostream>
#include<fstream>


class Ali {
	private:
	std::string name;
	std::string seller;
	std::string delivery;
	float price;
	int weight;
	int quantity;
public:
	Ali* next;
	Ali* prev;
	Ali() {
		next = NULL;
		prev = NULL;
	}
	Ali(std::string name, std::string seller, std::string delivery, float price, int weight, int quantity) : name(name), seller(seller), delivery(delivery), price(price), weight(weight), quantity(quantity) {
		next = NULL;
		prev = NULL;
	}
	friend std::ostream& operator<< (std::ostream& out, const Ali& ali)
	{
		out << "-------------------------------------------------" << '\n';
		out << "Item " + ali.name + " seller " + ali.seller << '\n';
		out << "Delivery company: " + ali.delivery << '\n';
		out << "Price: " << ali.price << '\n' << "Weight: " << ali.weight << '\n' << "Quantity: " << ali.quantity << '\n';
		out << "-------------------------------------------------" << '\n';
		return out;
	}
	friend std::istream& operator>> (std::istream& is, Ali& ali)
	{
		is >> ali.name >> ali.seller >> ali.delivery >> ali.weight >> ali.price >> ali.quantity;
		return is;
	}
	void SetName(std::string s) {
		this->name = s;
	}
	std::string GetName() {
		return this->name;
	}
	void SetSeller(std::string s) {
		this->seller = s;
	}
	std::string GetSeller() {
		return this->seller;
	}
	void SetDelivery(std::string s) {
		this->delivery = s;
	}
	std::string GetDelivery() {
		return this->delivery;
	}
	void SetPrice(float p) {
		this->price = p;
	}
	float GetPrice() {
		return this->price;
	}
	void SetWeight(int w) {
		this->weight = w;
	}
	int GetWeight() {
		return this->weight;
	}


	void SetQuantity(int q) {
		this->quantity = q;
	}
	int GetQuantity() {
		return this->quantity;
	}
	~Ali() {

	}
};

class List {
public:
	Ali* head;
	List() {
		head = NULL;
	}
	List(Ali ali) {
		Ali* tmp = new Ali(ali);
		head = tmp;
	}


	void edit(int index);

	Ali* search(int index);

	void addItem(Ali a);

	void printList();

	void printToFile(std::string filename);
	
	void readFromFile(std::string filename);

	Ali* searchSeller(std::string seller);

	void remove(int index);

	void free();


	~List() {
	}
};

