#include <iostream>

using namespace std;

const int MAX_VALUE = 100;   // Assume that array contains no more than 100 values.

int sumOfEvenNumbers(int arr[MAX_VALUE], int lenArr, int sum) {
    if (lenArr == 0) {
        return sum;
    }

    if (arr[lenArr - 1] % 2 == 0)
        sum += arr[lenArr - 1];
    
    return sumOfEvenNumbers(arr, lenArr - 1, sum);
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

    cout << sumOfEvenNumbers(arr, lenArr, 0);
    
    return 0;
}