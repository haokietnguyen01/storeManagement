#include "Customer.h"
#include "Person.h"
#include <iostream>
#include <fstream>
#include <iomanip>

using namespace std;

void Customer::enterInf()
{
    ofstream fo("customer.txt");
    do
    {
        cout << endl;
        fflush(stdin);
        cout << "\t\t\t - Nhap Ho va Ten : ";
        getline(cin, nameCus);
        cout << endl;
    }
    while (nameCus.length() == 0);
    formatName(nameCus);
    spaceOfName(nameCus);
    do
    {
        cout << "\t\t\t - Nhap ngay sinh : ";
        cin >> dayOfBirth >> monthOfBirth >> yearOfBirth;
        cout << endl;
    }
    while (!check(dayOfBirth, monthOfBirth, yearOfBirth));

    do
    {
        cout << "\t\t\t - Nhap so CMND : ";
        cin >> IdentityNum;
        cout << endl;
    }
    while (IdentityNum.length() != 9 || !checkNumInt(IdentityNum));

    do
    {
        cout << "\t\t\t - Nhap so dien thoai : ";
        cin >> Phonenum;
        cout << endl;
    }
    while (Phonenum.length() != 10 || !checkNumInt(Phonenum));

    cout << endl << "\t\t\t -> Nhap thanh cong" << endl;
    fo << nameCus << "," << dayOfBirth << " " << monthOfBirth << " " << yearOfBirth << " " << IdentityNum << " " << Phonenum;
    fo.close();
}
void Customer::displayInf()
{
    cout << "\t\t\t Thông Tin Khách Hàng : " << endl;
    ifstream fi("customer.txt");
    if(checkFile(fi))
    {
        cout << endl;
        cout << "\t\t\t -> Khong co thong tin khach hang" << endl << endl;
    }
    else
    {
        string nameCus;
        int dayOfBirth, monthOfBirth, yearOfBirth;
        long long IdentityNum, Phonenum;
        getline(fi, nameCus, ',');
        fi >> dayOfBirth;
        fi >> monthOfBirth;
        fi >> yearOfBirth;
        fi >> IdentityNum;
        fi >> Phonenum;
        cout << "\t\t\t - Ho va ten: " << nameCus << endl;
        cout << endl;
        cout << "\t\t\t - Ngay sinh: " << dayOfBirth << "/" << monthOfBirth << "/" << yearOfBirth << endl;
        cout << endl;
        cout << "\t\t\t - CMND: " << IdentityNum << endl;
        cout << endl;
        cout << "\t\t\t - So dien thoai: " << "+84 " << Phonenum << endl;
        cout << endl;

    }
    fi.close();
}

void Customer::editInf()
{
    char chooseEditInf;
    ifstream fi("customer.txt");
    if(checkFile(fi))
    {
        cout << endl << "\t\t\t -> Vui long nhap thong tin cua ban" << endl;
    }
    else
    {
        string nameCus;
        int dayOfBirth, monthOfBirth, yearOfBirth;
        string IdentityNum, Phonenum;
        getline(fi, nameCus, ',');
        fi >> dayOfBirth;
        fi >> monthOfBirth;
        fi >> yearOfBirth;
        fi >> IdentityNum;
        fi >> Phonenum;
        fi.close();

        ofstream fo("customer.txt");
        cout << "\t\t\t\t\t\t [1]-Chinh sua Ten" << endl;
        cout << "\t\t\t\t\t\t [2]-Chinh sua ngay sinh" << endl;
        cout << "\t\t\t\t\t\t [3]-Chinh sua CMND" << endl;
        cout << "\t\t\t\t\t\t [4]-Chinh sua so dien thoai" << endl;
        cout << "\n\t\t\t_____________________________________________________________________" << endl << endl;
        cout << "\t\t\t - Enter: ";
        cin >> chooseEditInf;
        cout << endl;
        switch(chooseEditInf)
        {
        case 49:
            cout << "\t\t\t - Ho va ten: ";
            fflush(stdin);
            getline(cin, nameCus);
            cout << endl;
            cout << "\t\t\t -> Da chinh sua ten thanh " << nameCus << endl;
            fo << nameCus << "," << dayOfBirth << " " << monthOfBirth << " " << yearOfBirth << " " << IdentityNum << " " << Phonenum;
            break;
        case 50:
            do
            {
                cout << "\t\t\t - Nhap ngay sinh : ";
                cin >> dayOfBirth >> monthOfBirth >> yearOfBirth;
                cout << endl;
            }
            while (!check(dayOfBirth, monthOfBirth, yearOfBirth));
            cout << "\t\t\t -> Da chinh sua ngay sinh thanh " << dayOfBirth << "/" << monthOfBirth << "/" << yearOfBirth << endl;
            fo << nameCus << "," << dayOfBirth << " " << monthOfBirth << " " << yearOfBirth << " " << IdentityNum << " " << Phonenum;
            break;

        case 51:
            do
            {
                cout << "\t\t\t - Nhap so CMND : ";
                cin >> IdentityNum;
                cout << endl;
            }
            while (IdentityNum.length() != 9  || !checkNumInt(IdentityNum));
            cout << "\t\t\t -> Da chinh sua CMND thanh " << IdentityNum << endl;
            fo << nameCus << "," << dayOfBirth << " " << monthOfBirth << " " << yearOfBirth << " " << IdentityNum << " " << Phonenum;
            break;
        case 52:
            do
            {
                cout << "\t\t\t - Nhap so dien thoai : ";
                cin >> Phonenum;
                cout << endl;
            }
            while (Phonenum.length() != 10 || !checkNumInt(Phonenum));
            cout << "\t\t\t -> Da chinh sua so dien thoai thanh " << Phonenum << endl;
            fo << nameCus << "," << dayOfBirth << " " << monthOfBirth << " " << yearOfBirth << " " << IdentityNum << " " << Phonenum;
            break;
        }
        fo.close();
    }
}

void Customer::searchtoBuy()
{
Manager:
    display();
    int itemInCart;
    string endline;
    string str;
    int flag = 0;
    ifstream fi;
    fi.open("customer.txt");
    if(checkFile(fi))
    {
        cout << endl << "\t\t\t -> Vui long nhap thong tin cua ban" << endl;
    }
    else
    {
        string nameCus, dayOfBirth, monthOfBirth, yearOfBirth, IdentityNum, Phonenum;
        getline(fi, nameCus, ',');
        getline(fi, dayOfBirth, ',');
        getline(fi, monthOfBirth, ',');
        getline(fi, yearOfBirth, ',');
        getline(fi, IdentityNum, ',');
        getline(fi, Phonenum, ',');
        fi.close();
        fi.open("store.txt");
        if(checkFile(fi))
        {
            cout << endl << endl << "\t\t\t -> Cua hang hien dang het hang. Xin vui long quay lai sau!" << endl;
        }
        else
        {
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
            fflush(stdin);
            cout << "\t\t\t - Tim kiem: ";
            getline(cin, str);
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
            cout << "\t\t\t CHON SAN PHAM CHO VAO GIO HANG" << endl << endl;
            for (int i = 1; i <= length; i++)
            {
                if (items[i].findStr(str) == 1)
                {
                    cout << "\t\t\t Bam [" << i << "]-De cho san pham " << items[i].get_name() << " voi gia " << items[i].get_price() << " vao gio hang" << endl;
                }
            }
            cout << endl;
            cout << "\t\t\t - Them vao gio hang: ";
            cin >> itemInCart;
            ofstream fo("cart.txt");
            fo << nameCus << "," << dayOfBirth << " " << monthOfBirth << " " << yearOfBirth << " " << IdentityNum << " " << Phonenum << endl;
            fo << items[itemInCart].get_name() << "," << items[itemInCart].get_price() << " " << items[itemInCart].get_day() << " " << items[itemInCart].get_month() << " " << items[itemInCart].get_year();
            fo.close();
            cout << "\t\t\t -> Da bo vao gio hang san pham ";
            cout << items[itemInCart].get_name() << " voi gia " << items[itemInCart].get_price() << " nhap hang vao ngay " << items[itemInCart].get_day() << "/" << items[itemInCart].get_month() << "/" << items[itemInCart].get_year() << endl << endl;
        }
    }

}

void Customer::bill()
{
    int acp;
    ifstream fi("customer.txt");
    if(checkFile(fi))
    {
        cout << endl << "\t\t\t -> Vui long nhap thong tin cua ban" << endl;
    }
    else
    {
        ifstream fi("store.txt");
        if(checkFile(fi))
        {
            cout << endl << "\t\t\t -> Gio hang cua ban dang trong" << endl;
        }
        else
        {
            ifstream fi("cart.txt");
            string nameCus, dayOfBirth, monthOfBirth, yearOfBirth, IdentityNum, Phonenum;
            string name, space;
            long long price;
            int day, month, year;
            getline(fi, nameCus, ',');
            fi >> dayOfBirth;
            fi >> monthOfBirth;
            fi >> yearOfBirth;
            fi >> IdentityNum;
            fi >> Phonenum;
            getline(fi, space, '\n');
            getline(fi, name, ',');
            fi >> price >> day >> month >> year;
            fi.close();
            cout << "\t\t\t - Ho va ten khach hang: " << nameCus << endl;
            cout << "\t\t\t - Ngay sinh khach hang: " << dayOfBirth << "/" << monthOfBirth << "/" << yearOfBirth << endl;
            cout << "\t\t\t - CMND khach hang: " << IdentityNum << endl;
            cout << "\t\t\t - So dien thoai khach hang: " << "+84 " << Phonenum << endl;
            cout << "\t\t\t - Ten san pham: " << name << endl;
            cout << "\t\t\t - Gia san pham: " << price << endl;
            cout << "\t\t\t - So luong san pham: 1 " << endl;
        }
    }
    fi.close();
}
