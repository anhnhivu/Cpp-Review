#include <iostream>

using namespace std;

int largestPossibleK(int n) {
    if (n == 1)
        return 1;
        
    int k = 1;
    int sum = 0;
    while (sum < n - k) {
        sum += k;
        k++;
    }
    return (k-1);
}

int main() {
    int n;
    cout << "Enter a positive integer: ";
    cin >> n;

    if (n < 1)
        cout << "Not a valid positive integer.\n";
    else
        cout << "Largest k so that S(k) < " << n << " is: " << largestPossibleK(n) << "\n";

    return 0;
}