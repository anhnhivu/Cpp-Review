#include <iostream>

using namespace std;

int daysInAMonth[12] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };

struct Date {
    int day;
    int month;
    int year;
};

void printDate(const Date& date) {
    cout << date.day << "." << date.month << "." << date.year << " \n";
}

bool isLeapYear(const int& year) {
    if (year % 4 == 0 && (year % 100 != 0 || year % 400 == 0))
        return true;
    return false;
}

void findDate(int year, int noOfDate) {
    if (isLeapYear(year))
        daysInAMonth[1]++;

    int month = 1;
    while (noOfDate > daysInAMonth[month - 1]) {
        noOfDate -= daysInAMonth[month - 1];
        month++;
    }

    Date newDate;
    newDate.year = year;
    newDate.month = month;
    newDate.day = noOfDate;

    cout << "The corresponding date is: ";
    printDate(newDate);
}

int main() {

    int year;
    int noOfDate;
    cout << "Enter year: ";
    cin >> year;
    if (year > 9999)
        cout << "Invalid.\n";
    cout << "Enter the day number: ";
    cin >> noOfDate;
    if (noOfDate > 366 || noOfDate == 0)
        cout << "Invalid.\n";

    findDate(year, noOfDate);

    return 0;
}