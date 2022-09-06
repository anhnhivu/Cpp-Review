#include <iostream>
#include <algorithm>

using namespace std;

const int MAX_VALUE = 100;   // Assume that array contains no more than 100 values.

void printArr(int arr[MAX_VALUE], int lenArr) {
    for (int i = 0; i < lenArr; i++) {
        cout << arr[i] << " ";
    }
    cout << "\n";
}

void sortPositiveNumbers(int arr[MAX_VALUE], int lenArr) {

    int arrPositive[MAX_VALUE];
    int lenArrPositive = 0;
    for (int i = 0; i < lenArr; i++) {
        if (arr[i] > 0) {
            arrPositive[lenArrPositive] = arr[i];
            lenArrPositive++;
        }
    }
    sort(arrPositive, arrPositive + lenArrPositive);

    int idxPostive = 0;
    for (int i = 0; i < lenArr; i++) {
        if (arr[i] > 0) {
            arr[i] = arrPositive[idxPostive];
            idxPostive++;
        }
    }
    printArr(arr, lenArr);
}

int main() {

    int lenArr;
    cout << "Enter length of your array: ";
    cin >> lenArr;

    int arr[MAX_VALUE];
    cout << "Enter the numbers in the array: \n";
    for (int i = 0; i < lenArr; i++) {
        cout << i + 1 << ": ";
        cin >> arr[i];
    }

    sortPositiveNumbers(arr, lenArr);
    
    return 0;
}