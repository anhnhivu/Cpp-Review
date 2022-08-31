#include <iostream>

using namespace std;

bool allEvenDigits(int n) {
    if (n == 0)
        return true;
    if ((n % 10) % 2 == 1)
        return false;
    else
        return allEvenDigits(n / 10);
}

int main() {

    int n;
    cout << "Enter a positive integer: ";
    cin >> n;

    if (allEvenDigits(n)) {
        cout << n << " contains only even digits.\n";
    }
    else {
        cout << n << " does not contain only even digits.\n";
    }
    
    return 0;
}