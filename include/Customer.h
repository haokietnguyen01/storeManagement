#ifndef CUSTOMER_H
#define CUSTOMER_H

#include "Person.h"
#include "Manager.h"

class Customer :public Person, public Manager
{
    string nameCus;
    //long long price;
    int dayOfBirth;
    int monthOfBirth;
    int yearOfBirth;
    string IdentityNum;
    string Phonenum;
    string name;
    string price;
    int day;
    int month;
    int year;
    int length;
    Person* itemsForCus = new Person[length];
public:
    Customer() {
        this->nameCus = "N/A";
        this->dayOfBirth = 1;
        this->monthOfBirth = 1;
        this->yearOfBirth = 1900;
        this->IdentityNum = "N/A";
        this->Phonenum = "N/A";
    }

    void enterInf();
    void displayInf();
    void editInf();
    void searchtoBuy();
    void bill();
};

#endif // CUSTOMER_H
