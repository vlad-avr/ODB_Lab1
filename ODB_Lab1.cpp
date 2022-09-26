#include <stdio.h>
#include <iostream>
#include "Company.h"
#include "Flat.h"






void write_company(Company*, char*);
Company* read_company(unsigned long int, char*);
void write_flat(Flat*, char*);
Flat* read_flat(unsigned long int, char*);
void file_del(char*);
int main()
{
    const int str_size = 64;
    char file_name[20] = "Company.bin";
    char flat_file[20] = "Flat.bin";
    remove(file_name);
    remove(flat_file);
    char name[64] = "COMPANY";
    char e_mail[64] = "bruh@cock.com";
    Company* company = new Company(1, name, e_mail, 0);
    company->print();
    
    write_company(company, file_name);
    read_company(0,file_name)->print();
    char address[64] = "Dick street, 69";
    Flat* flat = new Flat(1, address, 420.0, 1, 0);
    write_flat(flat, flat_file);
    read_flat(0, flat_file)->print();
}

void write_company(Company* company, char*file_name) {
    FILE* file;
    fopen_s(&file, file_name, "wb");
    fwrite(company, sizeof(Company), 1, file);
    fclose(file);
}

void write_flat(Flat* flat, char* file_name) {
    FILE* file;
    fopen_s(&file, file_name, "wb");
    fwrite(flat, sizeof(Flat), 1, file);
    fclose(file);
}

Company* read_company(unsigned long int data_ID, char* file_name) {
    FILE* file;
    fopen_s(&file, file_name, "rb");
    Company* cmp = new Company();
    fread_s(cmp, sizeof(Company), sizeof(Company), 1, file);
    return cmp;
}

Flat* read_flat(unsigned long int data_ID, char* file_name) {
    FILE* file;
    fopen_s(&file, file_name, "rb");
    Flat* flat = new Flat();
    fread_s(flat, sizeof(Flat), sizeof(Flat), 1, file);
    return flat;
}

void file_del(char* file_name) {
    remove(file_name);
}