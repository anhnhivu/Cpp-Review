#include <iostream>

int daysInAMonth[12] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };

struct Date 
{
    int day;
    int month;
    int year;
};

void printDate(const Date& date) 
{
    std::cout << date.day << "." << date.month << "." << date.year << " \n";
}

bool isLeapYear(const int& year) 
{
    if (year % 4 == 0 && (year % 100 != 0 || year % 400 == 0))
        return true;
    return false;
}

void findDate(int year, int noOfDate) 
{
    if (isLeapYear(year))
        daysInAMonth[1]++;

    int month = 0;
    while (noOfDate > daysInAMonth[month]) 
    {
        noOfDate -= daysInAMonth[month];
        month++;
    }

    Date newDate;
    newDate.year = year;
    newDate.month = month + 1;
    newDate.day = noOfDate;

    std::cout << "The corresponding date is: ";
    printDate(newDate);
}

int main() 
{
    int year;
    int noOfDate;
    std::cout << "Enter year: ";
    std::cin >> year;

    if (year > 9999)
        std::cout << "Invalid.\n";

    std::cout << "Enter the day number (1-366): ";
    std::cin >> noOfDate;

    if (noOfDate > 366 || noOfDate == 0)
        std::cout << "Invalid.\n";
    else
        findDate(year, noOfDate);

    return 0;
}