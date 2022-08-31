#include <iostream>

using namespace std;

const int MAX_VALUE = 100;  // Assume that array contains no more than 100 values.

void printReverseArr(int arr[MAX_VALUE], int index) {
    if (index == 0) {
        cout << "\n";
        return;
    }
    cout << arr[index-1] << " ";
    printReverseArr(arr, index - 1);
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

    cout << "Print array in reverse order: "; // 719
    printReverseArr(arr, lenArr);
}