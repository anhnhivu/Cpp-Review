#include <iostream>

using namespace std;

int isPowerOf2(int n) {
    if (n < 0)
        n = -n;
    if (n == 1)
        return false;
    while (n > 1) {
        if (n % 2 != 0)
            return false;
        n /= 2;
    }
    return true;
}

int main() {

    int n;
    cout << "Enter a positive integer: ";
    cin >> n;

    if (isPowerOf2(n))
        cout << n << " is a power of 2.\n";
    else
        cout << n << " is not a power of 2.\n";

    return 0;
}