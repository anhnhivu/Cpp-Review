#include <iostream>
#include <math.h>

using namespace std;

bool isPrime(int k) {
    if (k <= 1) 
        return false;
    for (int i = 2; i <= sqrt(k); i++) {
        if (k % i == 0)
            return false;
    }
    return true;
}

void printSmallerPrimeNumbers(int n) {
    cout << "List of prime numbers smaller than " << n << ":";
    if (n <= 2) {
        cout << " None.\n";
        return;
    }
    for (int i = 2; i < n; i++) {
        if (isPrime(i)) {
            cout << " " << i;
        }
    }
    cout << ".\n";
}

int main() {
    int n;
    cout << "Enter a positive integer: ";
    cin >> n;

    if (n < 1)
        cout << "Not a valid integer";
    else
        printSmallerPrimeNumbers(n);

    return 0;
}