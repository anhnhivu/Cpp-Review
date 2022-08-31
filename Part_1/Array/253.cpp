#include <iostream>

using namespace std;

const int MAX_VALUE = 100;  // Assume that array A and B contains no more than 100 values.
                            // Assume that all values in array A and B does not exceed 100. 

bool checkAinB(int arrA[MAX_VALUE], int lenA, int arrB[MAX_VALUE], int lenB) {
    int freqB[MAX_VALUE];
    for (int i = 0; i < MAX_VALUE; i++) {
        freqB[i] = 0; 
    }
    for (int i = 0; i < lenB; i++) {
        freqB[arrB[i]]++; 
    }
    
    bool aIsInB = true;
    for (int i = 0; i < lenA; i++) {
        if (freqB[arrA[i]] == 0) {
            aIsInB = false;
        }
    }
    return aIsInB;
}

int main() {

    int arrA[MAX_VALUE];
    int lengthArrA;
    cout << "Enter length of your array A: ";
    cin >> lengthArrA;
    cout << "Enter the numbers in the array A: \n";
    for (int i = 0; i < lengthArrA; i++) {
        cout << i + 1 << ": ";
        cin >> arrA[i];
    }

    int lengthArrB;
    cout << "Enter length of your array B: ";
    cin >> lengthArrB;
    int arrB[MAX_VALUE];
    cout << "Enter the numbers in the array B: \n";
    for (int i = 0; i < lengthArrB; i++) {
        cout << i + 1 << ": ";
        cin >> arrB[i];
    }

    if (checkAinB(arrA, lengthArrA, arrB, lengthArrB)) {
        cout << "Every value in array A exists in array B.\n";
    }
    else {
        cout << "Not all value in array A exists in array B.\n";
    }

    return 0;
}