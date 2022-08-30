#include <iostream>

using namespace std;

int sumOfDigits(int n) {
    int sumOfDigits = 0;
    while (n > 0) {
        sumOfDigits += (n % 10);
        n /= 10;
    }
    return sumOfDigits;
}

int main() {

    int n;
    cout << "Enter a positive integer: ";
    cin >> n;

    if (n < 1)
        cout << "Not a valid positive integer.\n";
    else
        cout << "Sum of digits of " << n << " is: " << sumOfDigits(n) << "\n";

    return 0;
}