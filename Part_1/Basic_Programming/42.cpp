#include <iostream>

int largestPossibleK(int n) 
{
    if (n == 1)
        return 1;
        
    int k = 1;
    int sum = 0;
    while (sum + k < n) {
        sum += k;
        k++;
    }
    return k - 1;
}

int main() {
    int n;
    std::cout << "Enter a positive integer: ";
    std::cin >> n;

    if (n < 1)
        std::cout << "Not a valid positive integer.\n";
    else
        std::cout << "Largest k so that S(k) < " << n << " is: " << largestPossibleK(n) << "\n";

    return 0;
}