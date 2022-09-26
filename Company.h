#pragma once
#include <iostream>



class Company
{
private:
	const int str_size = 64;
	long int ID = -1;
	char* name = new char[str_size];
	char* e_mail = new char[str_size];
	bool is_deleted = false;
public:
	Company(long int ID, char* name, char* e_mail, bool is_deleted) {
		this->ID = ID;
		memcpy(this->name, name, str_size);
		memcpy(this->e_mail, e_mail, str_size);
		this->is_deleted = is_deleted;
	}

	Company() {}

	void print() {
		std::cout << "\n ID: " << ID << "\n";
		std::cout << "Name: " << name << "\n";
		std::cout << "E_mail: " << e_mail << "\n";
		std::cout << "Deleted: " << is_deleted << "\n";
	}
};

