#include <iostream>

using namespace std;

int numberOfDivisors(int n) {
    if (n == 1)
        return 1;
    int totalNumberOfDivisors = 2; // n always has two divisors: 1 and itself
    for (int i = 2; i < n; i++) {
        if (n % i == 0) {
            totalNumberOfDivisors++;
        }
    }
    return totalNumberOfDivisors;
}

int main() {
    int n;
    cout << "Enter a positive integer: ";
    cin >> n;
    
    if (n < 1)
        cout << "Not a valid positive integer.\n";
    else
        cout << "Total number of divisors for " << n << " is: " << numberOfDivisors(n) << "\n";

    return 0;
}