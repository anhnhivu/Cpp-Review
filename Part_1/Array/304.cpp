#include <iostream>

using namespace std;

const int MAX_VALUE = 100;   // Assume that array contains no more than 100 values.

void segmentHasSumEqualsM(int arr[MAX_VALUE], int lenArr, int m) {

    int indexLeft = 0;
    int indexRight = lenArr;
    int sumSegment = 0;
    bool foundSegment = false;

    for (int i = 0; i < lenArr && !foundSegment; i++) {
        sumSegment += arr[i];
        indexRight = i;
        while (sumSegment > m) {
            sumSegment -= arr[indexLeft];
            indexLeft++;
        }
        if (sumSegment == m) {
            foundSegment = true;
        }
    }
    if (foundSegment) {
        cout << "Found segment: [";
        for (int i = indexLeft; i < indexRight; i++) {
            cout << arr[i] << ", ";
        }
        cout << arr[indexRight] << "].\n";
    }
    else {
        cout << "No segment found.\n";
    }
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

    int m;
    cout << "Enter a number M: ";
    cin >> m;

    segmentHasSumEqualsM(arr, lenArr, m);
    
    return 0;
}