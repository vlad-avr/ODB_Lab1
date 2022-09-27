
#include <iostream>
#include "Macro.h"


struct Flat {
	int ID;
	char address[_SIZE];
	double price;
	char type[_SIZE];
};


struct Flat_dat {
	Flat flat;
	int next_flat;
	bool is_deleted;
};

unsigned int f_size() {
	return (2 * _SIZE * sizeof(char) + 2 * sizeof(int) + sizeof(double) + sizeof(bool));
}

void print(Flat flat) {
	std::cout << "\n ID: " << flat.ID << "\n";
	std::cout << " Address: " << flat.address << "\n";
	std::cout << " Price: " << flat.price << "\n";
	std::cout << " Type: " << flat.type << "\n";
}

void write_flat(FILE* flat_file, Flat_dat* flat) {
	fwrite(&flat->flat.ID, sizeof(int), 1, flat_file);
	fwrite(&flat->flat.address, sizeof(char) * _SIZE, 1, flat_file);
	fwrite(&flat->flat.price, sizeof(double), 1, flat_file);
	fwrite(&flat->flat.type, sizeof(char) * _SIZE, 1, flat_file);
	fwrite(&flat->next_flat, sizeof(int), 1, flat_file);
	fwrite(&flat->is_deleted, sizeof(bool), 1, flat_file);
}

void read_flat(FILE* flat_file, Flat_dat* flat) {
	fread_s(&flat->flat.ID, sizeof(int), sizeof(int),  1, flat_file);
	fread_s(&flat->flat.address, sizeof(char) * _SIZE, sizeof(char) * _SIZE, 1, flat_file);
	fread_s(&flat->flat.price, sizeof(double), sizeof(double), 1, flat_file);
	fread_s(&flat->flat.type, sizeof(char) * _SIZE, sizeof(char) * _SIZE, 1, flat_file);
	fread_s(&flat->next_flat, sizeof(int), sizeof(int), 1, flat_file);
	fread_s(&flat->is_deleted, sizeof(bool), sizeof(bool), 1, flat_file);
}

/*class Flat
{
public:
	unsigned long int ID = -1;
	char* address = new char[_SIZE];
	double price = 0.0;
	unsigned long int company_ID = -1;
	bool is_deleted = false;

	Flat(unsigned long int ID, char* address, double price, unsigned long int company_ID, bool is_deleted) {
		this->ID = ID;
		memcpy(this->address, address, _SIZE);
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

	unsigned int get_size() {
		return _SIZE * sizeof(char) + sizeof(long) * 2 + sizeof(double) + sizeof(bool);
	}
};*/

