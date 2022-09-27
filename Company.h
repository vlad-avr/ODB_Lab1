#pragma once
#include <iostream>
#include "Macro.h"


struct Company {
	int ID;
	char name[_SIZE];
	char e_mail[_SIZE];
	char head_name[_SIZE];
};

struct Company_dat {
	Company company;
	bool is_deleted;
	int flat_id;
};


unsigned int comp_size() {
	return (3 * _SIZE * sizeof(char) + sizeof(int) + sizeof(bool) + sizeof(int));
}

void print(Company comp) {
	std::cout << "\n ID: " << comp.ID << "\n";
	std::cout << " Name: " << comp.name << "\n";
	std::cout << " E-mail: " << comp.e_mail << "\n";
	std::cout << "Head of the company: " << comp.head_name << "\n";
}

void write_company(FILE* company_file, Company_dat* company) {
	fwrite(&company->company.ID, sizeof(int), 1, company_file);
	fwrite(&company->company.name, sizeof(char) * _SIZE, 1, company_file);
	fwrite(&company->company.e_mail, sizeof(char) * _SIZE, 1, company_file);
	fwrite(&company->company.head_name, sizeof(char) * _SIZE, 1, company_file);
	fwrite(&company->flat_id, sizeof(int), 1, company_file);
	fwrite(&company->is_deleted, sizeof(bool), 1, company_file);
}

void read_company(FILE* company_file, Company_dat* company) {
	fread_s(&company->company.ID, sizeof(int), sizeof(int), 1, company_file);
	fread_s(&company->company.name, _SIZE* sizeof(char),_SIZE * sizeof(char), 1, company_file);
	fread_s(&company->company.e_mail, _SIZE * sizeof(char), _SIZE * sizeof(char), 1, company_file);
	fread_s(&company->company.head_name, _SIZE * sizeof(char), _SIZE * sizeof(char), 1, company_file);
	fread_s(&company->flat_id, sizeof(int), sizeof(int), 1, company_file);
	fread_s(&company->is_deleted, sizeof(bool), sizeof(bool), 1, company_file);
}

/*class Company
{
public:
	long int ID = -1;
	char* name = new char[_SIZE];
	char* e_mail = new char[_SIZE];
	bool is_deleted = false;
	int number_of_flats = 0;
	Company(long int ID, char* name, char* e_mail, bool is_deleted, int number_of_flats) {
		this->ID = ID;
		memcpy(this->name, name, _SIZE);
		memcpy(this->e_mail, e_mail, _SIZE);
		this->is_deleted = is_deleted;
		this->number_of_flats = number_of_flats;
	}

	Company() {}

	void print() {
		std::cout << "\n ID: " << ID << "\n";
		std::cout << " Name: " << name << "\n";
		std::cout << " E-mail: " << e_mail << "\n";
		std::cout << "Deleted: " << is_deleted << "\n";
	}

	unsigned int get_size() {
		return(_SIZE * sizeof(char) + _SIZE * sizeof(char) + sizeof(long) + sizeof(bool) + sizeof(int));
	}

	void set_name(char* new_name) {
		memcpy(name, new_name, _SIZE);
	}

	void set_email(char* new_email) {
		memcpy(e_mail, new_email, _SIZE);
	}
};*/

