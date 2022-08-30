#include <iostream>
#include <math.h>

using namespace std;

bool isArmstrongNumber(int k, int numberOfDigits) {
    if (k < 1) 
        return false;
    int sum = 0;
    int originalNumber = k;
    while (k > 0) {
        sum += pow((k % 10), numberOfDigits);
        k /= 10;
    }
    if (sum == originalNumber)
        return true;
    return false;
}

void printArmstrongNumbers() {
    cout << "List of Armstrong numbers from 1 to 1.000.000:";
    int numberOfDigits = 1;
    for (int i = 1; i < pow(10, 6); i++) {
        if (isArmstrongNumber(i, numberOfDigits)) {
            cout << " " << i;
        }
        if (i == 10 || i == pow(10, 2) || i == pow(10, 3) || i == pow(10, 4) || i == pow(10, 5)) {
            numberOfDigits++;
        }
    }
    cout << ".\n";
}

int main() {
    
    printArmstrongNumbers();
    return 0;
}