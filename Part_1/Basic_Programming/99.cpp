#include <iostream>

using namespace std;

void printThreeNum() {
    double num1, num2, num3;
    cout << "Enter the 1st number: ";
    cin >> num1;
    cout << "Enter the 2nd number: ";
    cin >> num2;
    cout << "Enter the 3rd number: ";
    cin >> num3;

    double smallerNum = num1;
    if (num2 < num1) {
        smallerNum = num2;
        num2 = num1;
        num1 = smallerNum;
    }
    if (num3 < num2) {
        smallerNum = num3;
        num3 = num2;
        num2 = smallerNum;
    }
    if (num2 < num1) {
        smallerNum = num2;
        num2 = num1;
        num1 = smallerNum;
    }
    cout << "In ascending order: " << num1 << " " << num2 << " " << num3 << "\n.";
}

int main() {
    printThreeNum();
    return 0;
}