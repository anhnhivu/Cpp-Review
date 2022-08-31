#include <iostream>

using namespace std;

int MAX_NUM = 2147483647;
int MIN_NUM = -2147483648;

void findSegment(int arr[100], int n) {
    int minNumber = MAX_NUM;
    int maxNumber = MIN_NUM;

    for (int i = 0; i < n; i++) {
        if (arr[i] < minNumber) {
            minNumber = arr[i];
        }
        if (arr[i] > maxNumber) {
            maxNumber = arr[i];
        }
    }
    
    cout << "Segment contains all values in the array: [" << minNumber << ", " << maxNumber << "].\n";
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

    findSegment(arr, n);

    return 0;
}