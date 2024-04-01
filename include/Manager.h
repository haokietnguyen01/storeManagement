#ifndef MANAGER_H
#define MANAGER_H

#include "Person.h"

using namespace std;

class Manager :public Person
{
protected:
    Person* items = new Person[length];
public:
    Manager()
    {

    }

    Manager(int length)
    {
        this->length = length;
    }

    void input();
    void add();
    void search();
    void edit();
    void remove();
    void display();
};
#endif // MANAGER_H
