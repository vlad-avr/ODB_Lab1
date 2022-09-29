
#include <iostream>
#include "Macro.h"


struct Flat {
	int ID;
	int company_ID;
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
	return (2 * _SIZE * sizeof(char) + 3 * sizeof(int) + sizeof(double) + sizeof(bool));
}

void f_print(Flat flat) {
	std::cout << "\n Flat ID: " << flat.ID << "\n";
	std::cout << " Company ID: " << flat.company_ID << "\n";
	std::cout << " Address: " << flat.address << "\n";
	std::cout << " Price: " << flat.price << "\n";
	std::cout << " Type: " << flat.type << "\n";
}

void write_flat(FILE* flat_file, Flat_dat flat) {
	fwrite((char*)&flat.flat.ID, sizeof(int), 1, flat_file);
	fwrite((char*)&flat.flat.company_ID, sizeof(int), 1, flat_file);
	fwrite(&flat.flat.address, sizeof(char) * _SIZE, 1, flat_file);
	fwrite((char*)&flat.flat.price, sizeof(double), 1, flat_file);
	fwrite(&flat.flat.type, sizeof(char) * _SIZE, 1, flat_file);
	fwrite((char*)&flat.next_flat, sizeof(int), 1, flat_file);
	fwrite((char*)&flat.is_deleted, sizeof(bool), 1, flat_file);
}

void read_flat(FILE* flat_file, Flat_dat& flat) {
	fread_s((char*)&flat.flat.ID, sizeof(int), sizeof(int),  1, flat_file);
	fread_s((char*)&flat.flat.company_ID, sizeof(int), sizeof(int), 1, flat_file);
	fread_s(&flat.flat.address, sizeof(char) * _SIZE, sizeof(char) * _SIZE, 1, flat_file);
	fread_s((char*)&flat.flat.price, sizeof(double), sizeof(double), 1, flat_file);
	fread_s(&flat.flat.type, sizeof(char) * _SIZE, sizeof(char) * _SIZE, 1, flat_file);
	fread_s((char*)&flat.next_flat, sizeof(int), sizeof(int), 1, flat_file);
	fread_s((char*)&flat.is_deleted, sizeof(bool), sizeof(bool), 1, flat_file);
}

