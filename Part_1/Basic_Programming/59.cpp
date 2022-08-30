#include <iostream>

using namespace std;

int isSymmetrical(int n) {
    int reverseNumber = 0;
    int tmpOriginalNumber = n;

    while (tmpOriginalNumber > 0) {
        reverseNumber = reverseNumber * 10 + (tmpOriginalNumber % 10);
        tmpOriginalNumber /= 10;
    }

    if (reverseNumber == n)
        return true;
    return false;
}

int main() {

    int n;
    cout << "Enter a positive integer: ";
    cin >> n;

    if (isSymmetrical(n))
        cout << n << " is a symmetrical number.\n";
    else
        cout << n << " is not a symmetrical number.\n";

    return 0;
}