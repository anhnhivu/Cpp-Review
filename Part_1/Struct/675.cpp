#include <iostream>
#include <string.h>
#include <vector>

using namespace std;

// Assumption: from year 1950 to 2049

struct Thesis {
    string code;
    string title;
    string studentName;
    string professorName;
    short int yearPublished = 2022;
};

void inputThesisList(vector<Thesis>& ThesisList) {
    ThesisList.clear();

    int numberOfThesis = 0;
    cout << "Insert number of theses: ";
    cin >> numberOfThesis;

    for (int i = 0; i < numberOfThesis; i++) {

        cout << "Enter the detail for thesis number " << i + 1 << ": \n";
        Thesis newThesis;

        cout << "Thesis Code (max 10 characters): ";
        cin >> newThesis.code;
        if (newThesis.code.size() == 0 || newThesis.code.size() > 10) {
            cout << "Invalid.\n";
        }

        cout << "Thesis Title (max 100 characters): ";
        cin >> newThesis.title;
        if (newThesis.title.size() == 0 || newThesis.title.size() > 100) {
            cout << "Invalid.\n";
        }

        cout << "Student (max 30 characters): ";
        cin >> newThesis.studentName;
        if (newThesis.studentName.size() == 0 || newThesis.studentName.size() > 30) {
            cout << "Invalid.\n";
        }

        cout << "Professor (max 30 characters): ";
        cin >> newThesis.professorName;
        if (newThesis.professorName.size() == 0 || newThesis.professorName.size() > 30) {
            cout << "Invalid.\n";
        }

        cout << "Year published (4 characters, between 1950 and 2049): ";
        cin >> newThesis.yearPublished;
        if (newThesis.yearPublished < 1950 || newThesis.yearPublished > 2049) {
            cout << "Invalid.\n";
        }

        ThesisList.push_back(newThesis);
    }
}

void printThesisList(const vector<Thesis> &ThesisList) {
    int lenOfList = ThesisList.size();
    cout << "\nList of Theses: \n";
    for (int i = 0; i < lenOfList; i++) {
        Thesis tmp = ThesisList[i];
        cout << i + 1 << ". Code: " << tmp.code << ", Title: " << tmp.title << ", Student: " << tmp.studentName << ", Professor: " << tmp.professorName << ", Year: " << tmp.yearPublished << ".\n";
    }
}

void yearWithMostTheses(const vector<Thesis>& ThesisList) {
    int freqThesesInYear[100];
    int lenOfList = ThesisList.size();
    for (int i = 0; i < 100; i++) {
        freqThesesInYear[i] = 0;
    }
    for (int i = 0; i < lenOfList; i++) {
        freqThesesInYear[ThesisList[i].yearPublished - 1950]++;
    }

    short int yearWithMost = 0;
    int maxNumberOfTheses = 0;
    for (int i = 0; i < 100; i++) {
        if (freqThesesInYear[i] > maxNumberOfTheses) {
            yearWithMost = i;
            maxNumberOfTheses = freqThesesInYear[i];
        }
    }
    cout << "\nYear with the highest number of theses is: " << yearWithMost + 1950 << "\n";
}

void mostRecentTheses(const vector<Thesis>& ThesisList) {

    short int mostRecentYear = 1950;
    int lenOfList = ThesisList.size();
    for (int i = 0; i < lenOfList; i++) {
        if (ThesisList[i].yearPublished > mostRecentYear) {
            mostRecentYear = ThesisList[i].yearPublished;
        }
    }
    cout << "\nMost recent theses are in year " << mostRecentYear << ": \n";
    for (int i = 0; i < lenOfList; i++) {
        if (ThesisList[i].yearPublished == mostRecentYear) {
            Thesis tmp = ThesisList[i];
            cout << i + 1 << ". Code: " << tmp.code << ", Title: " << tmp.title << ", Student: " << tmp.studentName << ", Professor: " << tmp.professorName << ", Year: " << tmp.yearPublished << ".\n";
        }
    }
}

int main() {

    vector<Thesis> ThesisList;
    inputThesisList(ThesisList);
    printThesisList(ThesisList);
    yearWithMostTheses(ThesisList);
    mostRecentTheses(ThesisList);

    return 0;
}