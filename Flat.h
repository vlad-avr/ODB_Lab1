#pragma once
#include <iostream>
//
class Flat
{
private:
	const int str_size = 64;
	unsigned long int ID = -1;
	char* address = new char[str_size];
	double price = 0.0;
	unsigned long int company_ID = -1;
	bool is_deleted = false;
public:
	Flat(unsigned long int ID, char* address, double price, unsigned long int company_ID, bool is_deleted) {
		this->ID = ID;
		memcpy(this->address, address, str_size);
		this->price = price;
		this->company_ID = company_ID;
		this->is_deleted = is_deleted;
	}

	Flat(){}

	void print() {
		std::cout << "\n ID: " << ID << "\n";
		std::cout << " Address: " << address << "\n";
		std::cout << " Price: " << price << "\n";
		std::cout << " Company ID: " << company_ID << "\n";
		std::cout << " Deleted: " << is_deleted << "\n";
	}
};

