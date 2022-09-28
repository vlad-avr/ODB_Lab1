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

void c_print(Company comp) {
	std::cout << "\n ID: " << comp.ID << "\n";
	std::cout << " Name: " << comp.name << "\n";
	std::cout << " E-mail: " << comp.e_mail << "\n";
	std::cout << "Head of the company: " << comp.head_name << "\n";
}

void write_company(FILE* company_file, Company_dat company) {
	fwrite((char*)&company.company.ID, sizeof(int), 1, company_file);
	fwrite(&company.company.name, sizeof(char) * _SIZE, 1, company_file);
	fwrite(&company.company.e_mail, sizeof(char) * _SIZE, 1, company_file);
	fwrite(&company.company.head_name, sizeof(char) * _SIZE, 1, company_file);
	fwrite((char*)&company.flat_id, sizeof(int), 1, company_file);
	fwrite((char*)&company.is_deleted, sizeof(bool), 1, company_file);
}

void read_company(FILE* company_file, Company_dat& company) {
	fread_s((char*)&company.company.ID, sizeof(int), sizeof(int), 1, company_file);
	fread_s(&company.company.name, _SIZE* sizeof(char),_SIZE * sizeof(char), 1, company_file);
	fread_s(&company.company.e_mail, _SIZE * sizeof(char), _SIZE * sizeof(char), 1, company_file);
	fread_s(&company.company.head_name, _SIZE * sizeof(char), _SIZE * sizeof(char), 1, company_file);
	fread_s((char*)&company.flat_id, sizeof(int), sizeof(int), 1, company_file);
	fread_s((char*)&company.is_deleted, sizeof(bool), sizeof(bool), 1, company_file);
}


