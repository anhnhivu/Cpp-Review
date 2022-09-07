#include <iostream>
#include <string.h>
#include <vector>

struct Thesis 
{
    string code;
    string title;
    string studentName;
    string professorName;
    short int yearPublished = 2022;
};

void checkInput(const string &input, const int &length) 
{
    if (input.size() == 0 || input.size() > length) 
        std::cout << "Invalid.\n";
}

void inputThesisList(vector<Thesis>& ThesisList) 
{
    ThesisList.clear();

    int numberOfThesis = 0;
    std::cout << "Insert number of theses: ";
    std::cin >> numberOfThesis;

    for (int i = 0; i < numberOfThesis; i++) 
    {
        std::cout << "Enter the detail for thesis number " << i + 1 << ": \n";
        Thesis newThesis;

        std::cout << "Thesis Code (max 10 characters): ";
        std::cin >> newThesis.code;
        checkInput(newThesis.code, 10));

        std::cout << "Thesis Title (max 100 characters): ";
        std::cin >> newThesis.title;
        checkInput(newThesis.title, 100);

        std::cout << "Student (max 30 characters): ";
        std::cin >> newThesis.studentName;
        checkInput(newThesis.studentName, 30);

        std::cout << "Professor (max 30 characters): ";
        std::cin >> newThesis.professorName;
        checkInput(newThesis.professorName, 30);

        std::cout << "Year published (4 characters, between 1950 and 2049): ";
        std::cin >> newThesis.yearPublished;
        if (newThesis.yearPublished < 1950 || newThesis.yearPublished > 2049) 
            std::cout << "Invalid.\n";

        ThesisList.push_back(newThesis);
    }
}

void printThesisList(const vector<Thesis> &ThesisList) 
{
    int lenOfList = ThesisList.size();
    std::cout << "\nList of Theses: \n";
    for (int i = 0; i < lenOfList; i++) 
    {
        Thesis tmp = ThesisList[i];
        std::cout << i + 1 << ". Code: " << tmp.code << ", Title: " << tmp.title << ", Student: " << tmp.studentName << ", Professor: " << tmp.professorName << ", Year: " << tmp.yearPublished << ".\n";
    }
}

void yearWithMostTheses(const vector<Thesis> &ThesisList) 
{
    int freqThesesInYear[100];
    int lenOfList = ThesisList.size();
    for (int i = 0; i < 100; i++) 
        freqThesesInYear[i] = 0;
    
    for (int i = 0; i < lenOfList; i++) 
        freqThesesInYear[ThesisList[i].yearPublished - 1950]++;
    

    short int yearWithMost = 0;
    int maxNumberOfTheses = 0;
    for (int i = 0; i < 100; i++) 
        if (freqThesesInYear[i] > maxNumberOfTheses)
        {
            yearWithMost = i;
            maxNumberOfTheses = freqThesesInYear[i];
        }
    std::cout << "\nYear with the highest number of theses is: " << yearWithMost + 1950 << "\n";
}

void mostRecentTheses(const vector<Thesis> &ThesisList) 
{
    short int mostRecentYear = 1950;
    int lenOfList = ThesisList.size();
    for (int i = 0; i < lenOfList; i++) 
        if (ThesisList[i].yearPublished > mostRecentYear) 
            mostRecentYear = ThesisList[i].yearPublished;
        
    
    std::cout << "\nMost recent theses are in year " << mostRecentYear << ": \n";
    for (int i = 0; i < lenOfList; i++) 
        if (ThesisList[i].yearPublished == mostRecentYear) 
        {
            Thesis tmp = ThesisList[i];
            std::cout << i + 1 << ". Code: " << tmp.code << ", Title: " << tmp.title << ", Student: " << tmp.studentName << ", Professor: " << tmp.professorName << ", Year: " << tmp.yearPublished << ".\n";
        }
}

int main() 
{
    vector<Thesis> ThesisList;
    inputThesisList(ThesisList);
    printThesisList(ThesisList);
    yearWithMostTheses(ThesisList);
    mostRecentTheses(ThesisList);

    return 0;
}