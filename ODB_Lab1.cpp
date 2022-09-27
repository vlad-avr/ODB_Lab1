
#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <iostream>

#include "Company.h"
#include "Flat.h"
#include <time.h>
#include "Macro.h"
#include "Index.h"


int MAX_ID = 0;


/*
unsigned int get_pos_comp(const char* file_name) {
    FILE* file;
    fopen_s(&file, file_name, "rb");
    fseek(file, 0L, SEEK_END);
    unsigned long id = ftell(file) % (_SIZE * sizeof(char) + _SIZE * sizeof(char) + sizeof(long) + sizeof(bool) + sizeof(int));
    fclose(file);
    return id;
}

void clear_file(const char* file_name) {
    FILE* file;
    fopen_s(&file, file_name, "wb");
    fclose(file);
}

Company* gen_comp() {
    char name[_SIZE];
    for (int i = 0; i < 10; i++) {
        char c = rand() % 26 + 65;
        name[i] = c;
    }
    name[10] = '\0';
    char e_mail[_SIZE];
    for (int i = 0; i < 10; i++) {
        char c = rand() % 26 + 65;
        e_mail[i] = c;
    }
    e_mail[10] = '\0';
    Company* company = new Company(MAX_ID, name, e_mail, false, 0);
    MAX_ID++;
    return company;
}

Flat* gen_flat(Company* cmp) {
    char address[_SIZE];
    for (int i = 0; i < 10; i++) {
        char c = rand() % 26 + 65;
        address[i] = c;
    }
    address[10] = '\0';
    Flat* flat = new Flat(cmp->number_of_flats + 1 + cmp->ID * 1000, address, (rand() % 100000 + 1000) / 10.0, cmp->ID, false);
    return flat;
}

void write_company(Company*, const char*);
Company* read_company(long int, const char*);
void write_flat(Flat*, const char*);
Flat* read_flat(unsigned long int, const char*);
void update_company(Company*, const char*, unsigned long int);
void print_companies(const char*);*/
void write_index(int, Index*, FILE*);
Index* get_index_arr(int&, FILE*);
int find_company_ifile_pos(int, Index*, int);
int get_company_ifile_pos(FILE*, int);
int get_company_pos(int, FILE*);
Company_dat get_company_data(int, FILE*);
Flat_dat get_flat_data(int, FILE*);
int get_flat_pos(int, int, FILE*, FILE*, FILE*);


int main()
{
    
}


/*void write_company(Company* company, const char*file_name) {
    FILE* file;
    fopen_s(&file, file_name, "ab");
    //fseek(file, file_pos * sizeof(Company), SEEK_SET);
    fwrite(&company->ID, sizeof(long), 1, file);
    fwrite(company->name, _SIZE *sizeof(char), 1, file);
    fwrite(company->e_mail, _SIZE * sizeof(char), 1, file);
    fwrite(&company->is_deleted, sizeof(bool), 1, file);
    fwrite(&company->number_of_flats, sizeof(int), 1, file);
    fclose(file);
}

void update_company(Company* company, const char* file_name, unsigned long int file_pos) {
    FILE* file;
    fopen_s(&file, file_name, "rb");
    fseek(file, file_pos * company->get_size(), SEEK_SET);
    fseek(file, -1*company->get_size(), SEEK_CUR);
    fwrite(&company->ID, sizeof(long), 1, file);
    fwrite(company->name, _SIZE * sizeof(char), 1, file);
    fwrite(company->e_mail, _SIZE * sizeof(char), 1, file);
    fwrite(&company->is_deleted, sizeof(bool), 1, file);
    fwrite(&company->number_of_flats, sizeof(int), 1, file);
    fclose(file);
}

void write_flat(Flat* flat, const char* file_name) {
    FILE* file;
    fopen_s(&file, file_name, "ab");
    fwrite(&flat->ID, sizeof(long), 1, file);
    fwrite(flat->address, _SIZE * sizeof(char), 1, file);
    fwrite(&flat->price, sizeof(double), 1, file);
    fwrite(&flat->company_ID, sizeof(long), 1, file);
    fwrite(&flat->is_deleted, sizeof(bool), 1, file);
    fclose(file);
}

Company* read_company(long int file_pos, const char* file_name) {
    FILE* file;
    fopen_s(&file, file_name, "rb");
    Company* cmp = new Company();

    fseek(file, file_pos * cmp->get_size(), SEEK_SET);
    fread_s(&cmp->ID, sizeof(long), sizeof(long), 1, file);
    fread_s(cmp->name, _SIZE*sizeof(char), _SIZE *sizeof(char), 1, file);
    fread_s(cmp->e_mail, _SIZE * sizeof(char), _SIZE * sizeof(char), 1, file);
    fread_s(&cmp->is_deleted, sizeof(bool), sizeof(bool), 1, file);
    fread_s(&cmp->number_of_flats, sizeof(int), sizeof(int), 1, file);
    fclose(file);
    return cmp;
}

Flat* read_flat(unsigned long int file_pos, const char* file_name) {
    FILE* file;
    fopen_s(&file, file_name, "rb");
    Flat* flat = new Flat();
    fseek(file, file_pos * flat->get_size(), SEEK_SET);
    fread_s(&flat->ID, sizeof(long), sizeof(long), 1, file);
    fread_s(flat->address, _SIZE * sizeof(char), _SIZE * sizeof(char), 1, file);
    fread_s(&flat->price, sizeof(double), sizeof(double), 1, file);
    fread_s(&flat->company_ID, sizeof(long), sizeof(long), 1, file);
    fread_s(&flat->is_deleted, sizeof(bool), sizeof(bool), 1, file);
    fclose(file);
    return flat;
}

void print_companies(const char* file_name) {
    FILE* file;
    fopen_s(&file, file_name, "rb");
    Company* cmp = new Company;
    char c = ' ';
    while (!feof(file)) {
        if (cmp->ID != -1) {
            cmp->print();
        }
        fread_s(&cmp->ID, sizeof(long), sizeof(long), 1, file);
        fread_s(cmp->name, _SIZE * sizeof(char), _SIZE * sizeof(char), 1, file);
        fread_s(cmp->e_mail, _SIZE * sizeof(char), _SIZE * sizeof(char), 1, file);
        fread_s(&cmp->is_deleted, sizeof(bool), sizeof(bool), 1, file);
        fread_s(&cmp->number_of_flats, sizeof(int), sizeof(int), 1, file);
        
    }
    fclose(file);
}*/

Flat_dat get_flat_data(int flat_file_pos, FILE* flat_file) {
    if (flat_file_pos == NOT_FOUND) {
        std::cout << NOT_FOUND_ERROR;
        return Flat_dat{};
    }
    Flat_dat f_dat;
    fseek(flat_file, flat_file_pos * f_size(), SEEK_SET);
    read_flat(flat_file, &f_dat);
}

int get_flat_pos(int flat_ID, int company_ID, FILE*index_file, FILE* company_file, FILE* flat_file){
    int company_pos = get_company_pos(company_ID, index_file);
    Company_dat comp_dat = get_company_data(company_pos, company_file);
    int prev_flat_ = 0;
    int this_flat_ = comp_dat.flat_id;
    Flat_dat f_dat{};
    while (this_flat_ != NOT_FOUND && !feof(flat_file) && (f_dat.flat.ID != flat_ID || f_dat.is_deleted)) {
        prev_flat_ = this_flat_;
        fseek(flat_file, this_flat_ * f_size(), SEEK_SET);
        read_flat(flat_file, &f_dat);
        this_flat_ = f_dat.next_flat;
    }
    if (f_dat.flat.ID == flat_ID) {
        return prev_flat_;
    }
    else {
        return NOT_FOUND;
    }
}

Company_dat get_company_data(int comp_file_pos, FILE* company_file) {
    if (comp_file_pos == NOT_FOUND) {
        std::cout << NOT_FOUND_ERROR;
        return Company_dat{};
    }
    Company_dat c_dat;
    fseek(company_file, comp_file_pos * comp_size(), SEEK_SET);
    fread_s(&c_dat, comp_size(), comp_size(), 1, company_file);
    return c_dat;
}

int get_company_pos(int company_ID, FILE* index_file) {
    int i_pos = get_company_ifile_pos(index_file, company_ID);
    if (i_pos == NOT_FOUND) {
        std::cout << NOT_FOUND_ERROR;
        return NOT_FOUND;
    }
    Index index;
    fseek(index_file, i_pos * sizeof(Index), SEEK_SET);
    fread_s(&index, sizeof(index), sizeof(index), 1, index_file);
    return index.file_pos;
}

 int get_company_ifile_pos(FILE* index_file, int company_ID) {
    int arr_size = 0;
    Index* index_arr = get_index_arr(arr_size, index_file);
    return find_company_ifile_pos(company_ID, index_arr, arr_size);
}

int find_company_ifile_pos(int company_ID, Index* index_arr, int arr_size) {
    int start = 0;
    int end = arr_size - 1;
    int cnt = 0;
    while (start <= end) {
        cnt = (start + end) / 2;
        if (index_arr[cnt].ID > company_ID) {
            end = cnt-1; 
        }
        else if(index_arr[cnt].ID <= company_ID) {
            start = cnt + 1;
        }
        else {
            if (!index_arr[cnt].delete_flag) {
                return index_arr[cnt].file_pos;
            }
            else {
                start = cnt + 1;
            }
        }
    }
    return NOT_FOUND;
}

Index* get_index_arr(int& arr_size, FILE* index_file) {
    fseek(index_file, 0L, SEEK_END);
    arr_size = ftell(index_file) / sizeof(Index);
    Index* index_arr = new Index[arr_size];
    fseek(index_file, 0L, SEEK_SET);
    fread_s(index_arr, arr_size * sizeof(Index), sizeof(Index), arr_size, index_file);
    return index_arr;
}

void write_index(int arr_size, Index* index_arr, FILE* index_file) {
    index_file = freopen(INDEX_FILE, "wb", index_file);
    fwrite(index_arr, sizeof(Index), arr_size, index_file);
    fflush(index_file);
    freopen(INDEX_FILE, "rb", index_file);
}

