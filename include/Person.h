#ifndef PERSON_H
#define PERSON_H

#include <string>

using namespace std;

bool checkYear(int year);
int checkDay(int month, int year);
bool check(int day, int month, int year);
string formatName(string& name);
void deleteSpace(char str[], int position);
void delete_spaceHead(char str[]);
void delete_spaceEnd(char str[]);
void delete_spaceMid(char str[]);
string copyString(char* str, int length);
string spaceOfName(string& name);
bool checkFile(ifstream& pFile);
bool checkNumInt(string a);


class Person
{
private:
    char menu;
protected:
    string name;
    string price;
    int day;
    int month;
    int year;
    int length;
public:
    Person()
    {
        this->name = "N/A";
        this->price = "N/A";
        this->day = 1;
        this->month = 1;
        this->year = 2000;
    }
    Person(string name, string price, int day, int month, int year)
    {

        this->name = name;
        this->price = price;
        this->day = day;
        this->month = month;
        this->year = year;
    }

    string get_name();
    string get_price();
    int get_day();
    int get_month();
    int get_year();
    void set_name(string nameT);
    void set_price(string priceT);
    void set_day(int dayT);
    void set_month(int monthT);
    void set_year(int yearT);
    int findStr(string str);
    void displayItem();
    void home();
    void menuManager();
    void menuCustomer();
};

#endif // PERSON_H
