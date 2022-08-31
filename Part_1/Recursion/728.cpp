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

int findCurrentMinValueIndex(int arr[MAX_VALUE], int currentIndex, int minValueIndex, int lenArr) {
    if (currentIndex == lenArr) {
        return minValueIndex;
    }
    if (arr[currentIndex] < arr[minValueIndex]) {
        minValueIndex = currentIndex;
    }
    return findCurrentMinValueIndex(arr, currentIndex + 1, minValueIndex, lenArr);
}

void sortArrWithRecursion(int arr[MAX_VALUE], int currentIndex, int lenArr) {
    // Selection Sort
    if (currentIndex == lenArr) {
        return;
    }

    int tmpSwap = arr[currentIndex];
    int minValueIndex = findCurrentMinValueIndex(arr, currentIndex, currentIndex, lenArr);
    arr[currentIndex] = arr[minValueIndex];
    arr[minValueIndex] = tmpSwap;

    sortArrWithRecursion(arr, currentIndex+1, lenArr);
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

    sortArrWithRecursion(arr, 0, lenArr);
    printArr(arr, lenArr);

    return 0;
}