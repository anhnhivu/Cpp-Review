#include <iostream>

using namespace std;

int MAX_ODD_NUM = 2147483647;
int MIN_EVEN_NUM = -2147483648;

int maxEvenLessThanOdd(int arr[100], int n) {
    int minOddNumber = MAX_ODD_NUM;
    int maxEvenNumber = MIN_EVEN_NUM;
    bool oddNumberExists = false;
    bool maxEvenNumberExists = false;

    for (int i = 0; i < n; i++) {
        if (arr[i] % 2 == 1 && oddNumberExists == false) {
            oddNumberExists = true;
        }
        if (arr[i] % 2 == 1 && arr[i] < minOddNumber) {
            minOddNumber = arr[i];
        }
    }
    for (int i = 0; i < n; i++) {
        if (arr[i] % 2 == 0 && arr[i] >= maxEvenNumber && arr[i] < minOddNumber) {
            maxEvenNumberExists = true;
            maxEvenNumber = arr[i];
        }
    }
    if (!oddNumberExists || !maxEvenNumberExists) {
        return -1;
    }
    return maxEvenNumber;
}

int main() {
    
    int n;
    cout << "Enter length of your array: ";
    cin >> n;

    if (n < 1) {
        cout << "Not valid.\n";
        return 0;
    }

    int arr[100];
    cout << "Enter the numbers in the array: \n";
    for (int i = 0; i < n; i++) {
        cout << i + 1 << ": ";
        cin >> arr[i];
    }

    int result = maxEvenLessThanOdd(arr, n);

    if (result == -1) {
        cout << "There is no number satisfy the conditions.";
    }
    else {
        cout << "The max even number that is smaller than all odd numbers in the array is: " << result;
    }

    return 0;
}