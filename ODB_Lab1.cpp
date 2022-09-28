
#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <iostream>
#include <Windows.h>
#include "Company.h"
#include "Flat.h"
#include <time.h>
#include "Macro.h"
#include "Index.h"


void write_index(int, Index*, FILE*);
Index* get_index_arr(int&, FILE*);
int find_company_ifile_pos(int, Index*, int);
int get_company_ifile_pos(FILE*, int);
int get_company_pos(int, FILE*);
Company_dat get_company_data(int, FILE*);
Flat_dat get_flat_data(int, FILE*);
int get_flat_pos(int, int, FILE*, FILE*, FILE*);
bool update_company_file(int, int, FILE*);
bool update_flat_file(int, int, FILE*);
bool update_ind_file(int, int, Index*, int);
void delete_company(int, FILE*, FILE*, FILE*);
void delete_flat(int, int, FILE*, FILE*, FILE*);
void trash_bin(FILE*, FILE*, FILE*);
void set_company_file(FILE*, FILE*, Company);
void set_flat_file(FILE*, FILE*, FILE*, Flat, int);
void add_company_file(Company, FILE*, FILE*);
void add_flat_file(Flat, int, FILE*, FILE*, FILE*);
void set_company(FILE*, FILE*);
void add_company(FILE*, FILE*);
void del_company(FILE*, FILE*, FILE*);
void get_company(FILE*, FILE*);
void del_flat(FILE*, FILE*, FILE*);
void add_flat(FILE*, FILE*, FILE*);
void get_flat(FILE*, FILE*, FILE*);
void set_flat(FILE*, FILE*, FILE*);
void print_flats(FILE*);
void print_companies(FILE*);
void interact(FILE*, FILE*, FILE*);

int main()
{
    FILE* index_file, * flat_file, * company_file;
    fopen_s(&index_file, INDEX_FILE, "wb");
    fopen_s(&company_file, MASTER_FILE, "wb");
    fopen_s(&flat_file, SLAVE_FILE, "wb");
    index_file = freopen(INDEX_FILE, "rb+", index_file);
    company_file = freopen(MASTER_FILE, "rb+", company_file);
    flat_file = freopen(SLAVE_FILE, "rb+", flat_file);
    interact(index_file, company_file, flat_file);
    fclose(index_file);
    fclose(company_file);
    fclose(flat_file);
}


void interact(FILE* index_file, FILE* company_file, FILE* flat_file) {
    
    while (true) {
        int inp;
        std::cout << "\n 1 - add company;\n 2 - print company;\n 3 - update company;\n 4 - delete company;\n 5 - add flat;\n 6 - print flat;\n 7 - update flat;\n 8 - delete flat;\n 9 - print all companies;\n 10 - print all flats;\n 11 - use trash bin;\n 0 - exit\n";
        std::cin >> inp;
        switch (inp)
        {
        case 1:
            add_company(company_file, index_file);
            break;
        case 2:
            get_company(index_file, company_file);
            break;
        case 3:
            set_company(index_file, company_file);
            break;
        case 4:
            del_company(company_file, flat_file, index_file);
            break;
        case 5:
            add_flat(flat_file, company_file, index_file);
            break;
        case 6:
            get_flat(flat_file, company_file, index_file);
            break;
        case 7:
            set_flat(flat_file, company_file, index_file);
            break;
        case 8:
            del_flat(company_file, flat_file, index_file);
            break;
        case 9:
            print_companies(company_file);
            break;
        case 10:
            print_flats(flat_file);
            break;
        case 11:
            trash_bin(company_file, flat_file, index_file);
            break;
        case 0:
            return;
        default:
            continue;
        }
    }
}

void del_company(FILE* company_file, FILE* flat_file, FILE* index_file) {
    std::cout << "\n Enter ID: ";
    int comp_id;
    std::cin >> comp_id;
    delete_company(comp_id, index_file, company_file, flat_file);
}

void add_company(FILE* company_file, FILE* index_file) {
    Company company;
    std::cout << "\n Enter ID: ";
    std::cin >> company.ID;
    std::cout << "\n Enter name: ";
    std::cin >> company.name;
    std::cout << "\n Enter e_mail: ";
    std::cin >> company.e_mail;
    std::cout << "\n Enter name of company CEO: ";
    std::cin >> company.head_name;
    add_company_file(company, company_file, index_file);
}

void set_company(FILE* index_file, FILE* company_file) {
    int comp_id;
    std::cout << "\n Enter ID: ";
    std::cin >> comp_id;
    int c_pos = get_company_pos(comp_id, index_file);
    Company_dat c_dat = get_company_data(c_pos, company_file);
    while (true) {
        int inp;
        std::cout << "\n 1 - update name;\n 2  - update e_mail;\n 3 - update head_name;\n 0 - update\n";
        std::cin >> inp;
        switch (inp)
        {
        case 1:
            std::cin >> c_dat.company.name;
            break;
        case 2:
            std::cin >> c_dat.company.e_mail;
            break;
        case 3:
            std::cin >> c_dat.company.head_name;
            break;
        case 0:
            set_company_file(index_file, company_file, c_dat.company);
            return;
        default:
            continue;
        }
    }

}

void get_company(FILE* index_file, FILE* company_file) {
    int comp_id;
    std::cout << "\n Enter ID: ";
    std::cin >> comp_id;
    int c_pos = get_company_pos(comp_id, index_file);
    Company_dat c_dat = get_company_data(c_pos, company_file);
    c_print(c_dat.company);
}

void del_flat(FILE* company_file, FILE* flat_file, FILE* index_file) {
    std::cout << "\n Enter company ID \\ flat ID: ";
    int c_id, f_id;
    std::cin >> c_id >> f_id;
    delete_flat(f_id, c_id, index_file, flat_file, company_file);
}

void add_flat(FILE* flat_file, FILE* company_file, FILE* index_file) {
    std::cout << "\n Enter company ID: ";
    int c_id;
    std::cin >> c_id;
    Flat flat;
    flat.company_ID = c_id;
    std::cout << "\n Enter ID: ";
    std::cin >> flat.ID;
    std::cout << "\n Enter address: ";
    std::cin >> flat.address;
    std::cout << "\n Enter price: ";
    std::cin >> flat.price;
    std::cout << "\n Enter type: ";
    std::cin >> flat.type;
    add_flat_file(flat, c_id, index_file, company_file, flat_file);
}

void get_flat(FILE* flat_file, FILE* company_file, FILE* index_file) {
    std::cout << "\n Enter company ID: ";
    int c_id;
    std::cin >> c_id;
    std::cout << "\n Enter flat ID: ";
    int f_id;
    std::cin >> f_id;
    int f_pos = get_flat_pos(f_id, c_id, index_file, company_file, flat_file);
    Flat_dat f_dat = get_flat_data(f_pos, flat_file);
    f_print(f_dat.flat);
}

void set_flat(FILE* flat_file, FILE* company_file, FILE* index_file) {
    std::cout << "\n Enter company ID: ";
    int c_id;
    std::cin >> c_id;
    std::cout << "\n Enter flat ID: ";
    int f_id;
    std::cin >> f_id;
    int f_pos = get_flat_pos(f_id, c_id, index_file, company_file, flat_file);
    Flat_dat f_dat = get_flat_data(f_pos, flat_file);
    while (true) {
        int inp;
        std::cout << "\n 1 - update address;\n 2 - update price;\n 3 - update type;\n 0 - update\n";
        std::cin >> inp;
        switch (inp)
        {
        case 1:
            std::cin >> f_dat.flat.address;
            break;
        case 2:
            std::cin >> f_dat.flat.price;
            break;
        case 3:
            std::cin >> f_dat.flat.type;
            break;
        case 0:
            set_flat_file(index_file, flat_file, company_file, f_dat.flat, c_id);
            return;
        default:
            continue;
        }
    }
}

void print_flats(FILE* flat_file) {
    fseek(flat_file, 0, SEEK_SET);
    Flat_dat f_dat;
    int eof_checker = getc(flat_file);
    while (!feof(flat_file) && eof_checker != EOF) {
        fseek(flat_file, -1L, SEEK_CUR);
        read_flat(flat_file, f_dat);
        if (!f_dat.is_deleted) {
            f_print(f_dat.flat);
        }
        eof_checker = getc(flat_file);
    }
}

void print_companies(FILE* company_file) {
    fseek(company_file, 0, SEEK_SET);
    Company_dat c_dat;
    int eof_checker = getc(company_file);
    while (!feof(company_file) && eof_checker != EOF) {
        fseek(company_file, -1, SEEK_CUR);
        read_company(company_file, c_dat);
        if (!c_dat.is_deleted) {
            c_print(c_dat.company);
        }
        eof_checker = getc(company_file);
    }
}

void set_company_file(FILE* index_file, FILE* company_file, Company company) {
    int cpos = get_company_pos(company.ID, index_file);
    if (cpos == NOT_FOUND) {
        return;
    }
    Company_dat c_dat = get_company_data(cpos, company_file);
    c_dat.company = company;
    fseek(company_file, cpos * comp_size(), SEEK_SET);
    write_company(company_file, c_dat);
}

void add_company_file(Company company, FILE* company_file, FILE* index_file) {
    int iarr_size;
    Index* index_arr = get_index_arr(iarr_size, index_file);
    index_file = freopen(INDEX_FILE, "wb", index_file);
    if (!iarr_size) {
        Index index;
        index.ID = company.ID;
        index.file_pos = 0;
        index.delete_flag = false;
        fwrite((char*)&index, sizeof(Index), 1, index_file);
    }
    else {
        for (int i = 0; i < iarr_size; i++) {
            if (index_arr[i].ID > company.ID) {
                Index index;
                index.ID = company.ID;
                index.file_pos = iarr_size;
                index.delete_flag = false;
                fwrite((char*)&index, sizeof(Index), 1, index_file);
                while (i < iarr_size) {
                    fwrite((char*)&index_arr[i++], sizeof(Index), 1, index_file);
                }
                break;
            }
            else {
                fwrite((char*)&index_arr[i], sizeof(Index), 1, index_file);
                if (iarr_size == i + 1) {
                    Index index;
                    index.ID = company.ID;
                    index.file_pos = iarr_size;
                    index.delete_flag = false;
                    fwrite((char*)&index, sizeof(Index), 1, index_file);
                }
            }
        }
    }
    delete[] index_arr;
    fflush(index_file);
    index_file = freopen(INDEX_FILE, "rb+", index_file);
    company_file = freopen(MASTER_FILE, "ab", company_file);
    Company_dat c_dat;
    c_dat.company = company;
    c_dat.flat_id = NOT_FOUND;
    c_dat.is_deleted = false;
    write_company(company_file, c_dat);
    fflush(company_file);
    company_file = freopen(MASTER_FILE, "rb+", company_file);
}

void add_flat_file(Flat flat, int company_id, FILE* index_file, FILE* company_file, FILE* flat_file) {
    int comp_pos = get_company_pos(company_id, index_file);
    if (comp_pos == NOT_FOUND) {
        return;
    }
    Company_dat c_dat;
    fseek(company_file, comp_size() * comp_pos, SEEK_SET);
    read_company(company_file, c_dat);
    Flat_dat f_dat;
    f_dat.flat = flat;
    f_dat.next_flat = c_dat.flat_id;
    f_dat.is_deleted = false;
    flat_file = freopen(SLAVE_FILE, "ab", flat_file);
    write_flat(flat_file, f_dat);
    flat_file = freopen(SLAVE_FILE, "rb+", flat_file);
    fseek(flat_file, 0, SEEK_END);
    int nflat_pos = ftell(flat_file) / f_size();
    c_dat.flat_id = nflat_pos - 1;
    fseek(company_file, comp_pos * comp_size(), SEEK_SET);
    write_company(company_file, c_dat);
}

void set_flat_file(FILE* index_file, FILE* flat_file, FILE* company_file, Flat flat, int company_id) {
    int fpos = get_flat_pos(flat.ID, company_id, index_file, company_file, flat_file);
    if (fpos != NOT_FOUND) {
        return;
    }
    Flat_dat f_dat = get_flat_data(fpos, flat_file);
    f_dat.flat = flat;
    fseek(flat_file, fpos * f_size(), SEEK_SET);
    write_flat(flat_file, f_dat);
}

void trash_bin(FILE* company_file, FILE* flat_file, FILE* index_file) {
    Index* del_index_arr;
    int iarr_size;
    del_index_arr = get_index_arr(iarr_size, index_file);
    Index* index_arr = new Index[iarr_size];
    int cur_ind_ = 0;
    for (int i = 0; i < iarr_size; i++) {
        if (!del_index_arr[i].delete_flag) {
            index_arr[cur_ind_] = del_index_arr[i];
            cur_ind_++;
        }
    }
    delete del_index_arr;
    iarr_size = cur_ind_;
    FILE* new_file;
    Flat_dat f_dat;
    int old_pos = 0;
    int new_pos = 0;
    fopen_s(&new_file, TRASH_FILE, "wb");
    fseek(flat_file, 0, SEEK_SET);
    int end_checker = getc(flat_file);
    while (!feof(flat_file) && end_checker != EOF) {
        fseek(flat_file, -1L, SEEK_CUR);
        read_flat(flat_file, f_dat);
        if (!f_dat.is_deleted) {
            write_flat(new_file, f_dat);
            if (old_pos != new_pos) {
                if (!update_company_file(new_pos, old_pos, company_file)) {
                    update_flat_file(new_pos, old_pos, flat_file);
                }
            }
            new_pos++;
        }
        end_checker = getc(flat_file);
        old_pos++;
    }
    fflush(flat_file);
    fflush(new_file);
    fclose(flat_file);
    fclose(new_file);
    remove(SLAVE_FILE);
    rename(TRASH_FILE, SLAVE_FILE);
    fopen_s(&flat_file, SLAVE_FILE, "rb");
    fopen_s(&new_file, TRASH_FILE, "wb");
    Company_dat c_dat;
    old_pos = new_pos = 0;
    fseek(company_file, 0, SEEK_SET);
    end_checker = getc(company_file);
    while (!feof(company_file) && end_checker != EOF) {
        fseek(company_file, -1L, SEEK_CUR);
        read_company(company_file, c_dat);
        if (!c_dat.is_deleted) {
            write_company(new_file, c_dat);
            if (old_pos != new_pos) {
                update_ind_file(new_pos, old_pos, index_arr, iarr_size);
            }
            new_pos++;
        }
        end_checker = getc(company_file);
        old_pos++;
    }
    fflush(new_file);
    fclose(new_file);
    fclose(company_file);
    remove(MASTER_FILE);
    rename(TRASH_FILE, MASTER_FILE);
    fopen_s(&company_file, MASTER_FILE, "rb");
    write_index(iarr_size, index_arr, index_file);
    delete[] index_arr;
}

void delete_flat(int flat_id, int company_id, FILE* index_file, FILE* flat_file, FILE* company_file) {
    int flat_fpos = get_flat_pos(flat_id, company_id, index_file, company_file, flat_file);
    if (flat_fpos == NOT_FOUND) {
        return;
    }
    Flat_dat f_dat;
    fseek(flat_file, flat_fpos * f_size(), SEEK_SET);
    read_flat(flat_file, f_dat);
    f_dat.is_deleted = true;
    fseek(flat_file, flat_fpos * f_size(), SEEK_SET);
    write_flat(flat_file, f_dat);
}

void delete_company(int company_id, FILE* index_file, FILE* company_file, FILE* flat_file) {
    int comp_fpos = get_company_pos(company_id, index_file);
    if (comp_fpos == NOT_FOUND) {
        return;
    }
    Company_dat c_dat;
    fseek(company_file, comp_fpos * comp_size(), SEEK_SET);
    read_company(company_file, c_dat);
    c_dat.is_deleted = true;
    fseek(company_file, comp_fpos * comp_size(), SEEK_SET);
    write_company(company_file, c_dat);
    int comp_ipos = get_company_ifile_pos(index_file, company_id);
    Index index;
    fseek(index_file, comp_ipos * sizeof(Index), SEEK_SET);
    fread((char*)&index, sizeof(Index), 1, index_file);
    index.delete_flag = true;
    fseek(index_file, comp_ipos * sizeof(Index), SEEK_SET);
    fwrite((char*)&index, sizeof(Index), 1, index_file);
    Flat_dat f_dat;
    int this_flat_ = c_dat.flat_id;
    while (this_flat_ != NOT_FOUND) {
        fseek(flat_file, this_flat_ * f_size(), SEEK_SET);
        read_flat(flat_file, f_dat);
        f_dat.is_deleted = true;
        fseek(flat_file, this_flat_ * f_size(), SEEK_SET);
        write_flat(flat_file, f_dat);
        this_flat_ = f_dat.next_flat;
    }
}

bool update_company_file(int new_fpos, int old_fpos, FILE* company_file) {
    fseek(company_file, 0, SEEK_SET);
    int comp_pos = 0;
    Company_dat c_dat;
    while (!feof(company_file) && !ferror(company_file)) {
        read_company(company_file, c_dat);
        if (c_dat.flat_id == old_fpos) {
            c_dat.flat_id = new_fpos;
            fseek(company_file, comp_pos*comp_size(), SEEK_SET);
            write_company(company_file, c_dat);
            return true;
        }
        comp_pos++;
    }
    return false;
}

bool update_flat_file(int new_fpos, int old_fpos, FILE* flat_file) {
    fseek(flat_file, 0, SEEK_SET);
    int flat_pos = 0;
    Flat_dat f_dat;
    while (!feof(flat_file) && !ferror(flat_file)) {
        read_flat(flat_file, f_dat);

        if (f_dat.next_flat == old_fpos) {
            f_dat.next_flat = new_fpos;
            fseek(flat_file, flat_pos * f_size(), SEEK_SET);
            write_flat(flat_file, f_dat);
            return true;
        }
        flat_pos++;
    }
    return false;
}

bool update_ind_file(int new_cpos, int old_cpos, Index* index_arr, int arr_size) {
    for (int i = 0; i < arr_size; i++) {
        if (index_arr[i].file_pos == old_cpos) {
            index_arr[i].file_pos = new_cpos;
            return true;
        }
    }
    return false;
}

Flat_dat get_flat_data(int flat_file_pos, FILE* flat_file) {
    if (flat_file_pos == NOT_FOUND) {
        std::cout << NOT_FOUND_ERROR;
        return Flat_dat{};
    }
    Flat_dat f_dat;
    fseek(flat_file, flat_file_pos * f_size(), SEEK_SET);
    read_flat(flat_file, f_dat);
    return f_dat;
}

int get_flat_pos(int flat_ID, int company_ID, FILE*index_file, FILE* company_file, FILE* flat_file){
    int company_pos = get_company_pos(company_ID, index_file);
    Company_dat comp_dat = get_company_data(company_pos, company_file);
    int prev_flat_ = 0;
    int this_flat_ = comp_dat.flat_id;
    Flat_dat f_dat{};
    while (this_flat_ != NOT_FOUND && !feof(flat_file) && !ferror(flat_file) && (f_dat.flat.ID != flat_ID || f_dat.is_deleted)) {
        prev_flat_ = this_flat_;
        fseek(flat_file, this_flat_ * f_size(), SEEK_SET);
        read_flat(flat_file, f_dat);
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
    read_company(company_file, c_dat);
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
    fread((char*)&index, sizeof(index), 1, index_file);
    return index.file_pos;
}

int get_company_ifile_pos(FILE* index_file, int company_ID) {
    int arr_size;
    Index* index_arr = get_index_arr(arr_size, index_file);
    int res = find_company_ifile_pos(company_ID, index_arr, arr_size);
    delete[] index_arr;
    return res;
}

int find_company_ifile_pos(int company_ID, Index* index_arr, int arr_size) {
    int start = 0;
    int end = arr_size - 1;
    while (start <= end) {
        int cnt = (start + end) / 2;
        if (index_arr[cnt].ID > company_ID) {
            end = cnt-1; 
        }
        else {
            if (index_arr[cnt].ID < company_ID) {
                start = cnt + 1;
            }
            else {
                if (!index_arr[cnt].delete_flag) {
                  //  return index_arr[cnt].file_pos;
                    return cnt;
                }
                else {
                    start = cnt + 1;
                    continue;
                }
            }
        }
    }
    return NOT_FOUND;
}

Index* get_index_arr(int& arr_size, FILE* index_file) {
    fseek(index_file, 0, SEEK_END);
    arr_size = ftell(index_file) / sizeof(Index);
    Index* index_arr = new Index[arr_size];
    fseek(index_file, 0, SEEK_SET);
    fread((char*)index_arr, sizeof(Index), arr_size, index_file);
    return index_arr;
}

void write_index(int arr_size, Index* index_arr, FILE* index_file) {
    index_file = freopen(INDEX_FILE, "wb", index_file);
    fwrite((char*)index_arr, sizeof(Index), arr_size, index_file);
    fflush(index_file);
    index_file = freopen(INDEX_FILE, "rb+", index_file);
}

