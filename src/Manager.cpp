#include "Manager.h"
#include "Person.h"
#include <iostream>
#include <fstream>
#include <sstream>
#include <cstdlib>
#include <iomanip>

using namespace std;

void Manager::input()
{
    string nameT = "\n";
    ofstream fo("store.txt");
    cout << endl;
    cout << "\t\t\t - So loai san pham: ";
    cin >> length;
    cout << endl;
    fo << length;
    for (int i = 1; i <= length; i++)
    {
        cout << "\t\t\t [San pham thu " << i << "]";
        cout << endl;
        fflush(stdin);
        do
        {
            cout << endl;
            cout << "\t\t\t - Ten san pham: ";
            getline(cin, name);
            cout << endl;
        }
        while(name.length() == 0);
        formatName(name);
        spaceOfName(name);
        name = nameT + name;
        items[i].set_name(name);

        do
        {
            cout << "\t\t\t - Gia san pham: ";
            cin >> price;
            cout << endl;
        }
        while(!checkNumInt(price));
        items[i].set_price(price);

        do
        {
            cout << "\t\t\t - Ngay nhap san pham: ";
            cin >> day >> month >> year;
            cout << endl;
        }
        while (!check(day, month, year));
        items[i].set_day(day);
        items[i].set_month(month);
        items[i].set_year(year);
        fo << items[i].get_name() << "," << items[i].get_price() << " " << items[i].get_day() << " " << items[i].get_month() << " " << items[i].get_year();
    }
    fo.close();
}

void Manager::add()
{
    string nameT = "\n";
    ifstream fi("store.txt");
    if(checkFile(fi))
    {
        cout << endl;
        fflush(stdin);
        cout << "\t\t\t - Ten san pham: ";
        getline(cin, name);
        cout << endl;
        formatName(name);
        spaceOfName(name);
        items[length].set_name(name);
        do
        {
            cout << "\t\t\t - Gia san pham: ";
            cin >> price;
            cout << endl;
        }
        while(!checkNumInt(price));
        items[length].set_price(price);
        do
        {
            cout << "\t\t\t - Ngay nhap san pham: ";
            cin >> day >> month >> year;
            cout << endl;
        }
        while (!check(day, month, year));

        cout << "\t\t\t -> Da them thanh cong san pham [" << name << "]" << endl;

        ofstream fo("store.txt");
        fo << "1" << endl;
        fo << name << "," << price << " " << day << " " << month << " " << year << endl;

    }
    else
    {
        fi >> length;
        for (int i = 1; i <= length; i++)
        {
            getline(fi, name, ',');
            fi >> price >> day >> month >> year;
            items[i].set_name(name);
            items[i].set_price(price);
            items[i].set_day(day);
            items[i].set_month(month);
            items[i].set_year(year);
        }
        length++;
        fi.close();
        cout << endl;
        fflush(stdin);
        cout << "\t\t\t - Ten san pham: ";
        getline(cin, name);
        cout << endl;
        formatName(name);
        spaceOfName(name);
        name = nameT + name;
        items[length].set_name(name);
        do
        {
            cout << "\t\t\t - Gia san pham: ";
            cin >> price;
            cout << endl;
        }
        while(!checkNumInt(price));
        items[length].set_price(price);
        do
        {
            cout << "\t\t\t - Ngay nhap san pham: ";
            cin >> day >> month >> year;
            cout << endl;
        }
        while (!check(day, month, year));

        items[length].set_day(day);
        items[length].set_month(month);
        items[length].set_year(year);

        ofstream fo("store.txt");
        fo << length;
        for (int i = 1; i <= length; i++)
        {
            fo << items[i].get_name() << "," << items[i].get_price() << " " << items[i].get_day() << " " << items[i].get_month() << " " << items[i].get_year();
        }
        fo.close();
    }
}

void Manager::search()
{
    string str;
    string nameT;
    int flag = 0;
Manager:
    display();
    ifstream fi("store.txt");
    if(checkFile(fi))
    {

    }

    else
    {
        cout << endl;
        fflush(stdin);
        cout << "\t\t\t - Tim kiem: ";
        getline(cin, str);
        cout << endl;
        formatName(str);
        spaceOfName(str);
        system("cls");
        cout << "\t\t\t==========================********************=======================" << endl;
        cout << "\t\t\t                                 SAN PHAM                            " << endl;
        cout << "\t\t\t==========================********************=======================" << endl;
        cout << "\t\t\t|          Ten san pham|        Gia san pham|     Ngay nhap san pham|" << endl;
        for (int i = 1; i <= length; i++)
        {
            if (items[i].findStr(str) == 1)
            {
                cout << "\t\t\t=====================================================================" << endl;
                items[i].displayItem();
                flag = 1;
            }
        }
        cout << "\t\t\t==========================********************=======================" << endl;
        if (flag == 0) cout << "\t\t\t -> Khong tim thay san pham" << endl;
        cout << endl;
    }
    fi.close();
}

void Manager::edit()
{
    string endline;
    string nameT;
    string str;
    string priceT;
    int dayT;
    int monthT;
    int yearT;
    ifstream fi("store.txt");
    if(checkFile(fi))
    {
        cout << endl;
        cout << "\t\t\t -> Khong co san pham";
    }
    else
    {
        int position;
        fi >> length;
        for (int i = 1; i <= length; i++)
        {
            getline(fi, endline, '\n');
            getline(fi, name, ',');
            fi >> price >> day >> month >> year;
            items[i].set_name(name);
            items[i].set_price(price);
            items[i].set_day(day);
            items[i].set_month(month);
            items[i].set_year(year);
        }
        fi.close();
        system("cls");
        cout << "\t\t\t=============================********************==========================" << endl;
        cout << "\t\t\t                                    SAN PHAM                            " << endl;
        cout << "\t\t\t=============================********************==========================" << endl;
        cout << "\t\t\t|    STT|        Ten san pham|        Gia san pham|     Ngay nhap san pham|" << endl;
        for (int i = 1; i <= length; i++)
        {
            cout << "\t\t\t===========================================================================" << endl;
            cout << "\t\t\t|"<<  setw(7) << i << "|"  << setw(20) << items[i].get_name() << "|" << setw(20) << items[i].get_price() << "|" << setw(16) << items[i].get_day() << "/" << items[i].get_month() << "/" << items[i].get_year() << "|" <<endl;
        }
        cout << "\t\t\t=============================********************==========================" << endl;
        cout << endl;
        cout << "\t\t\t - San pham can chinh sua: ";
        cin >> position;
        cout << endl;
        cout << "\t\t\t [Ban dang chinh sua san pham " << items[position].get_name() << "]" << endl << endl;
        str = items[position].get_name() ;
        fflush(stdin);
        cout << "\t\t\t - Chinh sua ten: ";
        getline(cin, nameT);
        cout << endl;
        formatName(nameT);
        spaceOfName(nameT);
        do
        {
            cout << "\t\t\t - Chinh sua gia: ";
            cin >> priceT;
            cout << endl;
        }
        while(!checkNumInt(priceT));
        do
        {
            cout << "\t\t\t - Chinh sua ngay: ";
            cin >> dayT >> monthT >> yearT;
            cout << endl;
        }
        while (!check(dayT, monthT, yearT));

        for (int i = 1; i <= length; i++)
        {
            if (i == position)
            {
                items[i].set_name(nameT);
                items[i].set_price(priceT);
                items[i].set_day(dayT);
                items[i].set_month(monthT);
                items[i].set_year(yearT);
            }
        }

        cout << endl;
        cout << "\t\t\t -> Da chinh sua san pham [" << str << "] thanh san pham [" << nameT << "]";
        cout << endl;
        ofstream fo("store.txt");
        fo << length << endl;
        for (int i = 1; i <= length; i++)
        {
            fo << items[i].get_name() << "," << items[i].get_price() << " " << items[i].get_day() << " " << items[i].get_month() << " " << items[i].get_year() << endl;
        }
        fo.close();
    }
}

void Manager::remove()
{
    string str;
    string endline;
    ifstream fi("store.txt");
    if(checkFile(fi))
    {
        cout << endl;
        cout << "\t\t\t -> Khong co san pham";
    }
    else
    {
        int position;
        fi >> length;
        for (int i = 1; i <= length; i++)
        {
            getline(fi, endline, '\n');
            getline(fi, name, ',');
            fi >> price >> day >> month >> year;
            items[i].set_name(name);
            items[i].set_price(price);
            items[i].set_day(day);
            items[i].set_month(month);
            items[i].set_year(year);
        }
        fi.close();
        system("cls");
        cout << "\t\t\t=============================********************==========================" << endl;
        cout << "\t\t\t                                    SAN PHAM                            " << endl;
        cout << "\t\t\t=============================********************==========================" << endl;
        cout << "\t\t\t|    STT|        Ten san pham|        Gia san pham|     Ngay nhap san pham|" << endl;
        for (int i = 1; i <= length; i++)
        {

            cout << "\t\t\t===========================================================================" << endl;
            cout << "\t\t\t|"<<  setw(7) << i << "|"  << setw(20) << items[i].get_name() << "|" << setw(20) << items[i].get_price() << "|" << setw(16) << items[i].get_day() << "/" << items[i].get_month() << "/" << items[i].get_year() << "|" <<endl;
        }
        cout << "\t\t\t=============================********************==========================" << endl;
        cout << endl << endl;
        cout << "\t\t\t - Vi tri san pham can xoa: ";
        cin >> position;
        str = items[position].get_name();
        cout << endl;
        for (int i = position; i <= length; i++)
        {
            items[i].set_name(items[i + 1].get_name());
            items[i].set_price(items[i + 1].get_price());
            items[i].set_day(items[i + 1].get_day());
            items[i].set_month(items[i + 1].get_month());
            items[i].set_year(items[i + 1].get_year());
        }
        length--;

        cout << "\t\t\t -> Da xoa thanh cong san pham " << str << endl;

        ofstream fo("store.txt");
        fo << length << endl;
        for (int i = 1; i <= length; i++)
        {
            fo << items[i].get_name() << "," << items[i].get_price() << " " << items[i].get_day() << " " << items[i].get_month() << " " << items[i].get_year()<< endl;
        }
        fo.close();
    }
}

void Manager::display()
{
    string line;
    ifstream fi("store.txt");
    if(checkFile(fi))
    {
        cout << endl;
        cout << "\t\t\t -> Khong co san pham";
    }
    else
    {
        fi >> length;
        for (int i = 1; i <= length; i++)
        {
            getline(fi, line, '\n');
            getline(fi, name, ',');
            fi >> price >> day >> month >> year;
            items[i].set_name(name);
            items[i].set_price(price);
            items[i].set_day(day);
            items[i].set_month(month);
            items[i].set_year(year);
        }
        cout << "\t\t\t==========================********************=======================" << endl;
        cout << "\t\t\t                                 SAN PHAM                            " << endl;
        cout << "\t\t\t==========================********************=======================" << endl;
        cout << "\t\t\t|          Ten san pham|        Gia san pham|     Ngay nhap san pham|" << endl;
        for (int i = 1; i <= length; i++)
        {

            cout << "\t\t\t=====================================================================" << endl;
            items[i].displayItem();
        }
        cout << "\t\t\t==========================********************=======================" << endl;
    }
    fi.close();
}
