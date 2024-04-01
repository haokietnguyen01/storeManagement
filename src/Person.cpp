#include "Person.h"
#include "Manager.h"
#include "Customer.h"

#include <iostream>
#include <cstring>
#include <fstream>
#include <iomanip>

//Kiem tra nam nhuan
bool checkYear(int year)
{
    if ((year % 4 == 0 && year % 100 != 0) || year % 400 == 0) return true;
    return false;
}

//Kiem tra ngay cua thang
int checkDay(int month, int year)
{
    int dayOfYear;

    switch (month)
    {
    case 1:
    case 3:
    case 5:
    case 7:
    case 8:
    case 10:
    case 12:
        dayOfYear = 31;
        break;
    case 4:
    case 6:
    case 9:
    case 11:
        dayOfYear = 30;
        break;
    case 2:
        if (checkYear(year)) dayOfYear = 29;
        else dayOfYear = 28;
        break;
    }

    return dayOfYear;
}

//Kiem tra ngay thang nam
bool check(int day, int month, int year)
{
    if (day < 1 || day > checkDay(month, year)) return false;
    if (month < 1 || month > 12) return false;
    if (year < 1000) return false;
    return true;
}


string formatName(string& name)
{
    string result = "";
    for (int i = 0; i < name.size(); i++)if (name[i] >= 'A' && name[i] <= 'Z')
        {
            name[i] += 32;
        }
    int i = 0;
    while (name[i] == ' ')i++;
    if (name[i] >= 'a' && name[i] <= 'z')name[i] -= 32;
    for (i; i < name.size(); i++)
    {
        if (name[i] == ' ')
        {
            while (name[i + 1] == ' ')i++;
            if (name[i + 1] >= 'a' && name[i + 1] <= 'z')name[i + 1] -= 32;
        }
        result += name[i];
    }
    if (result[result.size() - 1] == ' ')result.pop_back();
    return result;
}

void deleteSpace(char str[], int position)
{
    int length = strlen(str);
    for (int i = position; i < length; i++)
    {
        str[i] = str[i + 1];
    }
    str[length - 1] = '\0';
}

void delete_spaceHead(char str[])
{
    int i = 0;
    while (true)
    {
        if (str[i] == ' ') deleteSpace(str, i);
        else break;
    }
}

void delete_spaceEnd(char str[])
{
    while (true)
    {
        if (str[strlen(str) - 1] == ' ') deleteSpace(str, strlen(str) - 1);
        else break;
    }
}

void delete_spaceMid(char str[])
{
    int i, j;
    int len = strlen(str);
    for (i = 0; i < len; i++)
    {
        if (str[i] == ' ' && str[i + 1] == ' ')
        {
            for (j = i + 1; j < len; j++)
            {
                str[j] = str[j + 1];
            }
            i--;
            len--;
        }
    }
}

string copyString(char* str, int length)
{
    string s = "";
    for (int i = 0; i < length; i++)
    {
        s = s + str[i];
    }
    return s;
}

string spaceOfName(string& name)
{
    char str[100];
    int length;
    length = name.copy(str, name.size());
    str[length] = '\0';
    delete_spaceHead(str);
    delete_spaceMid(str);
    delete_spaceEnd(str);
    name = copyString(str, strlen(str));
    return name;
}

bool checkFile(ifstream& pFile)
{
    return pFile.peek() == ifstream::traits_type::eof();
}

bool checkNumInt(string a)
{

    for(int i = 0; i < a.size(); i++)
    {
        if(!(a[i] <= '9' && a[i] >= '0')) return false;
    }
    return true;
}


string Person::get_name()
{
    return name;
}

string Person::get_price()
{
    return price;
}

int Person::get_day()
{
    return day;
}

int Person::get_month()
{
    return month;
}

int Person::get_year()
{
    return year;
}

void Person::set_name(string nameT)
{
    name = nameT;
}

void Person::set_price(string priceT)
{
    price = priceT;
}


void Person::set_day(int dayT)
{
    day = dayT;
}

void Person::set_month(int monthT)
{
    month = monthT;
}

void Person::set_year(int yearT)
{
    year = yearT;
}

int Person::findStr(string str)
{
    if (name.find(str) < 100) return 1;
    return 0;
}

void Person::displayItem()
{
    cout << "\t\t\t|"<< setw(22) << name << "|" << setw(20) << price << "|" << setw(16) << day << "/" << month << "/" << year << "|" <<endl;
}

void Person::menuManager()
{
    Manager mn;
    system("cls");
    do
    {
        system("cls");
        cout << "\t\t\t_____________________________________________________________________" << endl;
        cout << "\t\t\t                      QUAN LY CUA HANG DIEN THOAI                    " << endl;
        cout << "\t\t\t_____________________________________________________________________" << endl;
        cout <<"\n\t\t\t\t\t   [1]-Nhap san pham " << endl
             << "\n\t\t\t\t\t   [2]-Hien thi san pham " << endl
             << "\n\t\t\t\t\t   [3]-Them san pham  " << endl
             << "\n\t\t\t\t\t   [4]-Tim kiem san pham " << endl
             << "\n\t\t\t\t\t   [5]-Chinh sua san pham " << endl
             << "\n\t\t\t\t\t   [6]-Xoa san pham" << endl
             << "\n\t\t\t\t\t   [7]-Thoat " << endl
             << "\n\t\t\t_____________________________________________________________________" << endl
             << "\t\t\tNhap tuy chon  : ";
        cin >> menu;
        switch(menu)
        {
        case 49:
            //======================================Nhan Vien==========================================
            system("cls");
            cout << "\t\t\t_____________________________________________________________________" << endl;
            cout << "\t\t\t                           NHAP SAN PHAM                             " << endl;
            cout << "\t\t\t_____________________________________________________________________" << endl;
            mn.input();
            cout << endl;
            cout << "\t\t\t\t\t\t\t\t\t   <- Tro Lai [Enter]";
            cout << endl;
            system("pause");
            break;
        case 50:
            system("cls");
            cout << "\t\t\t_____________________________________________________________________" << endl;
            cout << "\t\t\t                          SAN PHAM HIEN TAI                          " << endl;
            cout << "\t\t\t_____________________________________________________________________" << endl;
            mn.display();
            cout << endl;
            cout << "\t\t\t\t\t\t\t\t\t   <- Tro Lai [Enter]";
            cout << endl;
            system("pause");
            break;
        case 51:
            system("cls");
            cout << "\t\t\t_____________________________________________________________________" << endl;
            cout << "\t\t\t                            THEM SAN PHAM                            " << endl;
            cout << "\t\t\t_____________________________________________________________________" << endl;
            mn.add();
            cout << endl;
            cout << "\t\t\t\t\t\t\t\t\t   <- Tro Lai [Enter]";
            cout << endl;
            system("pause");
            break;
        case 52:
            system("cls");
            cout << "\t\t\t_____________________________________________________________________" << endl;
            cout << "\t\t\t                           TIM KIEM SAN PHAM                         " << endl;
            cout << "\t\t\t_____________________________________________________________________" << endl;
            mn.search();
            cout << endl;
            cout << "\t\t\t\t\t\t\t\t\t   <- Tro Lai [Enter]";
            cout << endl;
            system("pause");
            break;
        case 53:
            system("cls");
            cout << "\t\t\t_____________________________________________________________________" << endl;
            cout << "\t\t\t                          CHINH SUA SAN PHAM                         " << endl;
            cout << "\t\t\t_____________________________________________________________________" << endl;
            mn.edit();
            cout << endl;
            cout << "\t\t\t\t\t\t\t\t\t   <- Tro Lai [Enter]";
            cout << endl;
            system("pause");
            break;
        case 54:
            system("cls");
            cout << "\t\t\t_____________________________________________________________________" << endl;
            cout << "\t\t\t                               XOA SAN PHAM                          " << endl;
            cout << "\t\t\t_____________________________________________________________________" << endl;
            mn.remove();
            cout << endl;
            cout << "\t\t\t\t\t\t\t\t\t    <- Tro Lai [Enter]";
            cout << endl;
            system("pause");
            break;
        case 55:
            Person::home();
        }
    }
    while(1);
    system("pause");
}

void Person::menuCustomer()
{
    Customer ct;
    do
    {
        system("cls");
        cout << "\t\t\t_____________________________________________________________________" << endl;
        cout << "\t\t\t                                KHACH HANG                           " << endl;
        cout << "\t\t\t_____________________________________________________________________" << endl;
        cout << "\n\t\t\t\t\t   [1]-Nhap thong tin" << endl
             << "\n\t\t\t\t\t   [2]-Hien thi thong tin" << endl
             << "\n\t\t\t\t\t   [3]-Chinh sua thong tin" << endl
             << "\n\t\t\t\t\t   [4]-Tim kiem san pham " << endl
             << "\n\t\t\t\t\t   [5]-Bill " << endl
             << "\n\t\t\t\t\t   [6]-Thoat " << endl
             << "\n\t\t\t_____________________________________________________________________" << endl
             << "\t\t\tNhap tuy chon  : ";
        cin >> menu;
        switch(menu)
        {
        case 49:
            system("cls");
            cout << "\t\t\t_____________________________________________________________________" << endl;
            cout << "\t\t\t                          NHAP THONG TIN                             " << endl;
            cout << "\t\t\t_____________________________________________________________________" << endl;
            ct.enterInf();
            cout << endl;
            cout << "\t\t\t\t\t\t\t\t\t   <- Tro Lai [Enter]";
            cout << endl;
            break;
        case 50:
            system("cls");
            cout << "\t\t\t_____________________________________________________________________" << endl;
            cout << "\t\t\t                         HIEN THI THONG TIN                          " << endl;
            cout << "\t\t\t_____________________________________________________________________" << endl;
            ct.displayInf();
            cout << endl;
            cout << "\t\t\t\t\t\t\t\t\t   <- Tro Lai [Enter]";
            cout << endl;
            system("pause");
            break;
        case 51:
            system("cls");
            cout << "\t\t\t_____________________________________________________________________" << endl;
            cout << "\t\t\t                         CHINH SUA THONG TIN                         " << endl;
            cout << "\t\t\t_____________________________________________________________________" << endl;
            ct.editInf();
            cout << endl;
            cout << "\t\t\t\t\t\t\t\t\t   <- Tro Lai [Enter]";
            cout << endl;
            system("pause");
            break;
        case 52:
            system("cls");
            cout << "\t\t\t_____________________________________________________________________" << endl;
            cout << "\t\t\t                          TIM KIEM THONG TIN                         " << endl;
            cout << "\t\t\t_____________________________________________________________________" << endl;
            ct.searchtoBuy();
            cout << endl;
            cout << "\t\t\t\t\t\t\t\t\t   <- Tro Lai [Enter]";
            cout << endl;
            system("pause");
            break;
        case 53:
            system("cls");
            cout << "\t\t\t_____________________________________________________________________" << endl;
            cout << "\t\t\t                               XUAT BILL                             " << endl;
            cout << "\t\t\t_____________________________________________________________________" << endl;
            ct.bill();
            cout << endl;
            cout << "\t\t\t\t\t\t\t\t\t   <- Tro Lai [Enter]";
            cout << endl;
            system("pause");
            break;
        case 54:
            Person::home();
        }
    }
    while(1);
}

void Person::home()
{
    char login;
    do
    {
        system("cls");
        cout << "\t\t\t_____________________________________________________________________" << endl;
        cout << "\t\t\t                               DANG NHAP                             " << endl;
        cout << "\t\t\t_____________________________________________________________________" << endl;
        cout << "\n\t\t\t\t\t\t   [1]-Khach hang" << endl
             << "\n\t\t\t\t\t\t   [2]-Nhan vien" << endl
             << "\n\t\t\t\t\t\t   [3]-Thoat" << endl
             << "\n\t\t\t_____________________________________________________________________" << endl << endl << endl
             << "\t\t\tDang Nhap : ";
        cin >> login;
        switch(login)
        {
        case 49:
            menuCustomer();
            break;
        case 50:
            menuManager();
            break;
        case 51:
            exit(0);
        }
    }
    while(1);
    system("pause");
}
